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
 * (C) Copyright 2009
 * Stefan Roese, DENX Software Engineering, sr@denx.de.
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
 *
 */

#include <common.h>
#include <asm/ppc4xx_config.h>

/* NAND booting versions differ in bytes: 6, 8, 9, 11, 12 */

struct ppc4xx_config ppc4xx_config_val[] = {
	{
		"333-nor","NOR  CPU: 333 PLB: 166 OPB:  83 EBC:  83",
		{
			0x8c, 0x12, 0xec, 0x12, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
	{
		"400-133-nor", "NOR  CPU: 400 PLB: 133 OPB:  66 EBC:  66",
		{
			0x8e, 0x0e, 0xe8, 0x13, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
	{
		"400-nor", "NOR  CPU: 400 PLB: 200 OPB: 100 EBC: 100",
		{
			0x8e, 0x0e, 0xe8, 0x12, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
	{
		"533-nor", "NOR  CPU: 533 PLB: 177 OPB:  88 EBC:  88",
		{
			0x8e, 0x43, 0x60, 0x13, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
	{
		"533-nand", "NOR  CPU: 533 PLB: 177 OPB:  88 EBC:  88",
		{
			0x8e, 0x43, 0x60, 0x13, 0x98, 0x00, 0x0f, 0x00,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"600-nor", "NOR  CPU: 600 PLB: 200 OPB: 100 EBC: 100",
		{
			0x8d, 0x02, 0x34, 0x13, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
	{
		"600-nand", "NOR  CPU: 600 PLB: 200 OPB: 100 EBC: 100",
		{
			0x8d, 0x02, 0x34, 0x13, 0x98, 0x00, 0x0f, 0x00,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"666-nor", "NOR  CPU: 666 PLB: 222 OPB: 111 EBC: 111",
		{
			0x8d, 0x03, 0x78, 0x13, 0x98, 0x00, 0x0a, 0x00,
			0x40, 0x08, 0x23, 0x50, 0x00, 0x05, 0x00, 0x00
		}
	},
};

int ppc4xx_config_count = ARRAY_SIZE(ppc4xx_config_val);