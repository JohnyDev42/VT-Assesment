/*
 * Copyright (c) 2016-2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TA_STKQUE_H
#define TA_STKQUE_H


/*
 * This UUID is generated with uuidgen
 * the ITU-T UUID generator at http://www.itu.int/ITU-T/asn1/uuid.html
 */
#define TA_STKQUE_UUID \
	{ 0xd481ae8e, 0xc1c7, 0x48c0, \
		{ 0xa2, 0x28, 0xff, 0x85, 0x8a, 0x65, 0x4c, 0x69} } 

//#define TA_GCD_UUID 71340bf4-c79e-4ef7-a1d2-1c746e0f62a3
//d481ae8e-c1c7-48c0-a228-ff858a654c69
/* The function IDs implemented in this TA */
//#define TA_GCD_CMD_VALUE	0
#define TA_CREATEST_CMD_VALUE   0
#define TA_PUSH_CMD_VALUE   1
#define TA_POP_CMD_VALUE   2
#define TA_ISFULL_CMD_VALUE   3
#define TA_ISEMPTY_CMD_VALUE   4
#define TA_PEEK_CMD_VALUE   5


#endif /*TA_GCD_H*/
