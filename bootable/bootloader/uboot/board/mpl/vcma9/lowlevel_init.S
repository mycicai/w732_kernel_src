/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*
 * Memory Setup stuff - taken from blob memsetup.S
 *
 * Copyright (C) 1999 2000 2001 Erik Mouw (J.A.K.Mouw@its.tudelft.nl) and
 *                     Jan-Derk Bakker (J.D.Bakker@its.tudelft.nl)
 *
 * Modified for the Samsung SMDK2410 by
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#include <config.h>
#include <version.h>


/* some parameters for the board */

#define BWSCON		0x48000000
#define PLD_BASE	0x2C000000
#define SDRAM_REG	0x2C000106

/* BWSCON */
#define DW8			(0x0)
#define DW16			(0x1)
#define DW32			(0x2)
#define WAIT			(0x1<<2)
#define UBLB			(0x1<<3)

/* BANKSIZE */
#define BURST_EN		(0x1<<7)

#define B1_BWSCON		(DW16)
#define B2_BWSCON		(DW32)
#define B3_BWSCON		(DW32)
#define B4_BWSCON		(DW16 + WAIT + UBLB)
#define B5_BWSCON		(DW8 + UBLB)
#define B6_BWSCON		(DW32)
#define B7_BWSCON		(DW32)

/* BANK0CON */
#define B0_Tacs			0x0	/*  0clk */
#define B0_Tcos			0x1	/*  1clk */
/*#define B0_Tcos		0x0	  0clk */
#define B0_Tacc			0x7	/*  14clk */
/*#define B0_Tacc		0x5	  8clk */
#define B0_Tcoh			0x0	/*  0clk */
#define B0_Tah			0x0	/*  0clk */
#define B0_Tacp			0x0     /* page mode is not used */
#define B0_PMC			0x0	/* page mode disabled */

/* BANK1CON */
#define B1_Tacs			0x0	/*  0clk */
#define B1_Tcos			0x1	/*  1clk */
/*#define B1_Tcos		0x0	  0clk */
#define B1_Tacc			0x7	/*  14clk */
/*#define B1_Tacc		0x5	  8clk */
#define B1_Tcoh			0x0	/*  0clk */
#define B1_Tah			0x0	/*  0clk */
#define B1_Tacp			0x0     /* page mode is not used */
#define B1_PMC			0x0	/* page mode disabled */

#define B2_Tacs			0x3	/*  4clk */
#define B2_Tcos			0x3	/*  4clk */
#define B2_Tacc			0x7     /* 14clk */
#define B2_Tcoh			0x3	/*  4clk */
#define B2_Tah			0x3	/*  4clk */
#define B2_Tacp			0x0	/* page mode is not used */
#define B2_PMC			0x0     /* page mode disabled */

#define B3_Tacs			0x3	/*  4clk */
#define B3_Tcos			0x3	/*  4clk */
#define B3_Tacc			0x7     /* 14clk */
#define B3_Tcoh			0x3	/*  4clk */
#define B3_Tah			0x3	/*  4clk */
#define B3_Tacp			0x0	/* page mode is not used */
#define B3_PMC			0x0     /* page mode disabled */

#define B4_Tacs			0x3	/*  4clk */
#define B4_Tcos			0x1	/*  1clk */
#define B4_Tacc			0x7	/* 14clk */
#define B4_Tcoh			0x1	/*  1clk */
#define B4_Tah			0x0	/*  0clk */
#define B4_Tacp			0x0     /* page mode is not used */
#define B4_PMC			0x0	/* page mode disabled */

#define B5_Tacs			0x0	/*  0clk */
#define B5_Tcos			0x3	/*  4clk */
#define B5_Tacc			0x5	/*  8clk */
#define B5_Tcoh			0x2	/*  2clk */
#define B5_Tah			0x1	/*  1clk */
#define B5_Tacp			0x0     /* page mode is not used */
#define B5_PMC			0x0	/* page mode disabled */

#define B6_MT			0x3	/* SDRAM */
#define B6_Trcd			0x1	/* 3clk */
#define B6_SCAN			0x2	/* 10bit */

#define B7_MT			0x3	/* SDRAM */
#define B7_Trcd			0x1	/* 3clk */
#define B7_SCAN			0x2	/* 10bit */

/* REFRESH parameter */
#define REFEN			0x1	/* Refresh enable */
#define TREFMD			0x0	/* CBR(CAS before RAS)/Auto refresh */
#define Trp			0x0	/* 2clk */
#define Trc			0x3	/* 7clk */
#define Tchr			0x2	/* 3clk */
#define REFCNT			1113	/* period=15.6us, HCLK=60Mhz, (2048+1-15.6*60) */
/**************************************/

_TEXT_BASE:
	.word	TEXT_BASE

.globl lowlevel_init
lowlevel_init:
	/* memory control configuration */
	/* make r0 relative the current location so that it */
	/* reads SMRDATA out of FLASH rather than memory ! */
	ldr     r0, =CSDATA
	ldr	r1, _TEXT_BASE
	sub	r0, r0, r1
	ldr	r1, =BWSCON	/* Bus Width Status Controller */
	add     r2, r0, #CSDATA_END-CSDATA
0:
	ldr     r3, [r0], #4
	str     r3, [r1], #4
	cmp     r2, r0
	bne     0b

	/* PLD access is now possible */
	/* r0 == SDRAMDATA */
	/* r1 == SDRAM controller regs */
	ldr	r2, =PLD_BASE
	ldrb	r3, [r2, #SDRAM_REG-PLD_BASE]
	mov	r4, #SDRAMDATA1_END-SDRAMDATA
	/* calculate start and end point */
	mla	r0, r3, r4, r0
	add     r2, r0, r4
0:
	ldr     r3, [r0], #4
	str     r3, [r1], #4
	cmp     r2, r0
	bne     0b

	/* everything is fine now */
	mov	pc, lr

	.ltorg
/* the literal pools origin */

CSDATA:
    .word (0+(B1_BWSCON<<4)+(B2_BWSCON<<8)+(B3_BWSCON<<12)+(B4_BWSCON<<16)+(B5_BWSCON<<20)+(B6_BWSCON<<24)+(B7_BWSCON<<28))
    .word ((B0_Tacs<<13)+(B0_Tcos<<11)+(B0_Tacc<<8)+(B0_Tcoh<<6)+(B0_Tah<<4)+(B0_Tacp<<2)+(B0_PMC))
    .word ((B1_Tacs<<13)+(B1_Tcos<<11)+(B1_Tacc<<8)+(B1_Tcoh<<6)+(B1_Tah<<4)+(B1_Tacp<<2)+(B1_PMC))
    .word ((B2_Tacs<<13)+(B2_Tcos<<11)+(B2_Tacc<<8)+(B2_Tcoh<<6)+(B2_Tah<<4)+(B2_Tacp<<2)+(B2_PMC))
    .word ((B3_Tacs<<13)+(B3_Tcos<<11)+(B3_Tacc<<8)+(B3_Tcoh<<6)+(B3_Tah<<4)+(B3_Tacp<<2)+(B3_PMC))
    .word ((B4_Tacs<<13)+(B4_Tcos<<11)+(B4_Tacc<<8)+(B4_Tcoh<<6)+(B4_Tah<<4)+(B4_Tacp<<2)+(B4_PMC))
    .word ((B5_Tacs<<13)+(B5_Tcos<<11)+(B5_Tacc<<8)+(B5_Tcoh<<6)+(B5_Tah<<4)+(B5_Tacp<<2)+(B5_PMC))
CSDATA_END:

SDRAMDATA:
/* 4Mx8x4 */
    .word ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))
    .word ((B7_MT<<15)+(B7_Trcd<<2)+(B7_SCAN))
    .word ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)
    .word 0x32 + BURST_EN
    .word 0x30
    .word 0x30
SDRAMDATA1_END:

/* 8Mx8x4 (not implemented yet) */
    .word ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))
    .word ((B7_MT<<15)+(B7_Trcd<<2)+(B7_SCAN))
    .word ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)
    .word 0x32 + BURST_EN
    .word 0x30
    .word 0x30

/* 2Mx8x4 (not implemented yet) */
    .word ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))
    .word ((B7_MT<<15)+(B7_Trcd<<2)+(B7_SCAN))
    .word ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)
    .word 0x32 + BURST_EN
    .word 0x30
    .word 0x30

/* 4Mx8x2 (not implemented yet) */
    .word ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))
    .word ((B7_MT<<15)+(B7_Trcd<<2)+(B7_SCAN))
    .word ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)
    .word 0x32 + BURST_EN
    .word 0x30
    .word 0x30
