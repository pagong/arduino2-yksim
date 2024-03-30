/* YkSim.h --- adaption of libyubikey for Arduino 1.0.x
**
**  msd, 05-feb-2013:	based on code from https://github.com/Yubico/yubico-c
*/

/*
 * Written by Simon Josefsson <simon@josefsson.org>.
 * Copyright (c) 2006-2012 Yubico AB
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef YUBIKEYSIM_H
#define YUBIKEYSIM_H

#include <YkCore.h>
#include <Keyboard.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include "yksgenerate.h"
#include "ykseeprom.h"
// #include "ykshiddev.h"	// unused!
// #include "ykstouch.h"	// unused!
// #include "ykstimer.h"	// unused!

extern void YubikeyInit(void);

extern void GeneratePayload(int);
extern void GenerateToken(void);
extern void GenerateStatic(void);

// extern void GenerateChallResp(void);	// unused !
// extern void GenerateHOTP(void);	// unused !
// extern void GenerateTOTP(void);	// unused !

// extern void SendKbString(char * in);	// unused !

#ifdef __cplusplus
}
#endif
#endif

