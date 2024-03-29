// simple YubiKey generator for Arduino 2.2.x
//
// read AES key, counter, public and private ID from EEPROM
// use button on Pin 3 as key press on Arduino Pro Micro

#include "YkCore.h"
#include "YkSim.h"
#include <SoftTimer.h>

yubikey_ctx_st ctx;

char otp[YUBIKEY_OTP_MAXSIZE];
char *pos;

#define BLINKPIN	 17
#define BUTTONPIN	  3
#define THRESHOLD	  2

#define	TIME_POLL	100	// poll "key" every 100 ms
#define	TIME_SEND	 10	// send kb codes every 10 ms

/*************************************/

void checkKey(Task* me) {
  static int key_on = 0, key_off = 0, key_press = 0;

  yubikey_incr_timestamp(&ctx);

  if (digitalRead(BUTTONPIN) == LOW) {
    key_off = 0;
    key_press = 0;
    key_on += 1;
    digitalWrite(BLINKPIN, HIGH);
  } else {
    if (key_on > THRESHOLD) key_press = key_on;
    key_on = 0;
    key_off += 1;
    digitalWrite(BLINKPIN, LOW);
  }

  if ((key_press > 0) && (key_off > THRESHOLD)) {
    payload(key_press);
    key_press = 0;
  }
}

/*************************************/

Task taskKey(TIME_POLL, checkKey);
Task taskKB (TIME_SEND, sendKey);

/*************************************/

void setup() {
  Serial.begin(9600);
  pinMode(BLINKPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);

  YubikeyInit();

  SoftTimer.add(&taskKey);
}

/*************************************/

void sendKey(Task* me) {
  if (*pos) {
    Keyboard.write(*pos);
    pos++;
  } else {
    Keyboard.write('\n');
    Keyboard.end();
    SoftTimer.remove(&taskKB);
    SoftTimer.add(&taskKey);
  }
}

/*************************************/

void payload(int duration) {
  *otp = '\0';
  if (duration <= 10) gen_token();
  if (duration >= 15) gen_static();

  pos = otp;
  Keyboard.begin();
  SoftTimer.remove(&taskKey);
  SoftTimer.add(&taskKB);
}

/*************************************/

void gen_token(void) {
  unsigned long time1, time2;

  yubikey_simulate(otp, &ctx);
  yubikey_incr_usage(&ctx);
}

/*************************************/

void gen_static(void) {
  unsigned long time1, time2;
  char buffer[16];

  yubikey_eeget_static ((uint8_t *) buffer);
  yubikey_modhex_encode (otp, buffer, 16);
}

/*************************************/

void YubikeyInit() {
  unsigned long time1, time2;
  
  uint32_t seed         = analogRead(0);

  uint8_t aeskey[16];
  uint8_t privID[6];
  uint8_t pubID[16];
  uint16_t counter;
  uint8_t *ptr;

  char public_id[32+1];
  char private_id[12+1];

  uint32_t time = 0x010203;

  Serial.println("Initializing YubiKey ...");
  time1 = micros();

  ptr = aeskey;
  yubikey_eeget_aeskey(ptr);

  ptr = (uint8_t*) &counter;
  yubikey_eeget_counter(ptr);

  ptr = privID;
  yubikey_eeget_private(ptr);
  yubikey_hex_encode(private_id, (char *)privID, 6);

  ptr = pubID;
  yubikey_eeget_public(ptr);
  yubikey_hex_encode(public_id, (char *)pubID, 6);

  yubikey_init(&ctx, aeskey, public_id, private_id, counter, time, seed);
  yubikey_incr_counter(&ctx);

  ptr = (uint8_t*) &(ctx.counter);
  yubikey_eeset_counter(ptr);

  time2 = micros();
  Serial.print("done in ");
  Serial.print(time2-time1);
  Serial.println(" micros");
}

/*************************************/
