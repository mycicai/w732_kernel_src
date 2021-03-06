/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef __TVROT_REG_H__
#define __TVROT_REG_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
    unsigned FLAG0        : 1;
    unsigned FLAG1        : 1;
    unsigned rsv_2        : 3;
    unsigned FLAG5        : 1;
    unsigned rsv_6        : 10;
    unsigned FLAG0_IRQ_EN : 1;
    unsigned FLAG1_IRQ_EN : 1;
    unsigned rsv_18       : 3;
    unsigned FLAG5_IRQ_EN : 1;
    unsigned rsv_22       : 10;
} TVR_REG_IRQ_FLAG, *PTVR_REG_IRQ_FLAG;


typedef struct
{
    unsigned FLAG0_CLR    : 1;
    unsigned FLAG1_CLR    : 1;
    unsigned rsv_2        : 3;
    unsigned FLAG5_CLR    : 1;
    unsigned rsv_6        : 26;
} TVR_REG_IRQ_FLAG_CLR, *PTVR_REG_IRQ_FLAG_CLR;


typedef struct
{
    unsigned AUTO_LOOP    : 1;
    unsigned rsv_1        : 3;
    unsigned DOUBLE_BUF   : 1;
    unsigned rsv_5        : 2;
    unsigned MODE         : 1;
    unsigned QUEUE_DEPTH  : 4;
    unsigned rsv_12       : 5;
    unsigned SEG1EN       : 1;
    unsigned SEG2EN       : 1;
    unsigned SEG3EN       : 1;
    unsigned SEG4EN       : 1;
    unsigned SEG5EN       : 1;
    unsigned SEG6EN       : 1;
    unsigned SEG7EN       : 1;
    unsigned SEG8EN       : 1;
    unsigned SEG9EN       : 1;
    unsigned rsv_26       : 6;
} TVR_REG_CFG, *PTVR_REG_CFG;


typedef struct
{
    unsigned HARD_RESET  : 1;
    unsigned WARN_RESET  : 1;
    unsigned rsv_2       : 30;
} TVR_REG_RESET, *PTVR_REG_RESET;


typedef struct
{
    unsigned OK             : 1;
    unsigned BUSY           : 1;
    unsigned EMPTY          : 1;
    unsigned rsv_3          : 1;
    unsigned VIRTUAL_EMPTY  : 1;
    unsigned rsv_5          : 3;
    unsigned RPT            : 4;
    unsigned RPT_WRAP       : 1;
    unsigned rsv_13         : 19;
} TVR_REG_QUEUE_RSTA, *PTVR_REG_QUEUE_RSTA;


typedef struct
{
    unsigned OK             : 1;
    unsigned BUSY           : 1;
    unsigned FULL           : 1;
    unsigned rsv_3          : 1;
    unsigned VIRTUAL_FULL   : 1;
    unsigned rsv_5          : 3;
    unsigned WRT            : 4;
    unsigned WRT_WRAP       : 1;
    unsigned rsv_13         : 19;
} TVR_REG_QUEUE_WSTA, *PTVR_REG_QUEUE_WSTA;


typedef struct
{
    unsigned SLOW_EN        : 1;
    unsigned rsv_1          : 15;
    unsigned SLOW_CNT       : 16;
} TVR_REG_SLOW_DOWN, *PTVR_REG_SLOW_DOWN;


typedef struct
{
    unsigned WIDTH  : 16;
    unsigned HEIGHT : 16;
} TVR_REG_SIZE, *PTVR_REG_SIZE;


typedef struct
{
    unsigned X : 16;
    unsigned Y : 16;
} TVR_REG_OFS, *PTVR_REG_OFS;


typedef struct
{
    unsigned OUTPUT_FORMAT  : 3;
    unsigned rsv_3          : 1;
    unsigned PERF_MODE      : 1;// recommend to set as 0.
    unsigned RESAMPLE       : 1;
    unsigned rsv_6          : 21;
    unsigned ROT_ANGLE      : 2;
    unsigned FLIP           : 1;
    unsigned NOP            : 1;
    unsigned INT_EN         : 1;
} TVR_REG_CON, *PTVR_REG_CON;


typedef struct
{
    unsigned THRESHOLD          : 4;
    unsigned rsv_4              : 12;
    unsigned MAIN_LB_S_IN_LINE  : 7;
    unsigned rsv_23             : 1;
    unsigned FIFO_MODE          : 1;
    unsigned rsv_25             : 7;
} TVR_REG_PERF, *PTVR_REG_PERF;


typedef struct
{
    unsigned LINE_SIZE      : 17;
    unsigned BLOCK_WIDTH    : 15;
} TVR_REG_BUF_SIZE, *PTVR_REG_BUF_SIZE;


typedef struct
{
    TVR_REG_IRQ_FLAG      IRQ_FLAG;          // 0000
    UINT32                rsv_0004;          // 0004
    TVR_REG_IRQ_FLAG_CLR  IRQ_FLAG_CLR;      // 0008
    UINT32                rsv_000C[3];       // 000C

    TVR_REG_CFG           CFG;               // 0018
    UINT32                rsv_001C;          // 001C
    UINT32                DROP_INPUT;        // 0020
    UINT32                rsv_0024;          // 0024
    UINT32                STOP;              // 0028
    UINT32                rsv_002C;          // 002C
    UINT32                ENABLE;            // 0030
    UINT32                rsv_0034;          // 0034
    TVR_REG_RESET         RESET;             // 0038
    UINT32                LOCK;              // 003C
    TVR_REG_QUEUE_RSTA    QUEUE_RSTA;        // 0040
    UINT32                rsv_0044;          // 0044

    UINT32                RD_BASE;           // 0048
    UINT32                rsv_004C;          // 004C
    UINT32                RDP_ADV;           // 0050
    UINT32                rsv_0054;          // 0054
    TVR_REG_QUEUE_WSTA    QUEUE_WSTA;        // 0058
    UINT32                rsv_005C;          // 005C
    UINT32                WR_BASE;           // 0060
    UINT32                rsv_0064;          // 0064
    UINT32                WRP_ADV;           // 0068
    UINT32                rsv_006C;          // 006C
    UINT32                QUEUE_DATA;        // 0070
    UINT32                rsv_0074;          // 0074
    UINT32                QUEUE_BASE;        // 0078
    UINT32                rsv_007C;          // 007C
    UINT32                EXEC_CNT;          // 0080
    UINT32                rsv_0084[159];     // 0084..02FC

    TVR_REG_SLOW_DOWN     SLOW_DOWN;         // 0300
    UINT32                rsv_0304;          // 0304
    UINT32                BUF_BASE_ADDR0;    // 0308
    UINT32                rsv_030C;          // 030C
    UINT32                BUF_BASE_ADDR1;    // 0310
    UINT32                rsv_0314;          // 0314
    UINT32                Y_DST_STR_ADDR;    // 0318
    UINT32                rsv_031C[5];       // 031C..032C

    TVR_REG_SIZE          SRC_SIZE;          // 0330
    UINT32                rsv_0334;          // 0334
    TVR_REG_SIZE          CLIP_SIZE;         // 0338
    UINT32                rsv_033C;          // 033C
    TVR_REG_OFS           CLIP_OFFSET;       // 0340
    UINT32                rsv_0344;          // 0344
    UINT32                DST_WIDTH_IN_BYTE; // 0348
    UINT32                rsv_034C[7];       // 034C..0364

    TVR_REG_CON           CON;               // 0368
    TVR_REG_PERF          PERF;              // 036C
    TVR_REG_BUF_SIZE      MAIN_BUF_SIZE;     // 0370
    TVR_REG_BUF_SIZE      SUB_BUF_SIZE;      // 0374
    UINT32                rsv_0378[2];       // 0378..037C

    UINT32                BUF_BASE_ADDR2;    // 0380
    UINT32                rsv_0384;          // 0384
    UINT32                BUF_BASE_ADDR3;    // 0388
    UINT32                rsv_038C;          // 038C

} volatile TVR_REGS, *PTVR_REGS;

STATIC_ASSERT(0x0048 == offsetof(TVR_REGS, RD_BASE));
STATIC_ASSERT(0x0300 == offsetof(TVR_REGS, SLOW_DOWN));
STATIC_ASSERT(0x0330 == offsetof(TVR_REGS, SRC_SIZE));
STATIC_ASSERT(0x0368 == offsetof(TVR_REGS, CON));
STATIC_ASSERT(0x0380 == offsetof(TVR_REGS, BUF_BASE_ADDR2));
STATIC_ASSERT(0x0390 == sizeof(TVR_REGS));

extern PTVR_REGS const TVR_REG;

#ifdef __cplusplus
}
#endif

#endif // __TVROT_REG_H__

