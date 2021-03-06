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

#ifdef MTK_DSPIRDBG
/*dsp logger*/
X_CON_SCE(CON_SCE_SS_FCORE_LOGGING, 0x8008590A, 0x80805001, 0x01005010, 0x1818500A, 0x20205003, 0x40405013)
#endif

/* video telephonly */
X_CON_SCE(CON_SCE_VT, 0x8008590E, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405015)

/* video record */
X_CON_SCE(CON_SCE_VIDEO_REC, 0x80085903, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405024)

/* camera capture */
X_CON_SCE(CON_SCE_CAM_CAP, 0x80085900, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x4040501E)

/* camera preview */
X_CON_SCE(CON_SCE_CAM_PREVIEW, 0x80085900, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405015)

/* video playback with TV-out (Play mode: LCM(Menu) / TV(Video, No HDMI)) */
X_CON_SCE(CON_SCE_PLAYBACK_WITH_TVOUT, 0x8008590E, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405017)

/* video playback without TV-out */
X_CON_SCE(CON_SCE_PLAYBACK_WITHOUT_TVOUT, 0x8008590E, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405016)

/* normal */
X_CON_SCE(CON_SCE_NORMAL, 0x8008590A, 0x80805001, 0x01005010, 0x18185004, 0x20205003, 0x40405013)

