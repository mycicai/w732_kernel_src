# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.
#
# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


#
# (C) Copyright 2007 Semihalf
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundatio; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

ifeq ($(ARCH),powerpc)
LOAD_ADDR = 0x40000
endif
ifeq ($(ARCH),arm)
LOAD_ADDR = 0x1000000
endif

include $(TOPDIR)/config.mk

# Resulting ELF and binary exectuables will be named demo and demo.bin
OUTPUT-$(CONFIG_API) = $(obj)demo
OUTPUT = $(OUTPUT-y)

# Source files located in the examples/api directory
SOBJ_FILES-$(CONFIG_API) += crt0.o
COBJ_FILES-$(CONFIG_API) += demo.o
COBJ_FILES-$(CONFIG_API) += glue.o
COBJ_FILES-$(CONFIG_API) += libgenwrap.o

# Source files which exist outside the examples/api directory
EXT_COBJ_FILES-$(CONFIG_API) += lib/crc32.o
EXT_COBJ_FILES-$(CONFIG_API) += lib/ctype.o
EXT_COBJ_FILES-$(CONFIG_API) += lib/div64.o
EXT_COBJ_FILES-$(CONFIG_API) += lib/string.o
EXT_COBJ_FILES-$(CONFIG_API) += lib/time.o
EXT_COBJ_FILES-$(CONFIG_API) += lib/vsprintf.o
ifeq ($(ARCH),powerpc)
EXT_SOBJ_FILES-$(CONFIG_API) += arch/powerpc/lib/ppcstring.o
endif

# Create a list of source files so their dependencies can be auto-generated
SRCS	+= $(addprefix $(SRCTREE)/,$(EXT_COBJ_FILES-y:.o=.c))
SRCS	+= $(addprefix $(SRCTREE)/,$(EXT_SOBJ_FILES-y:.o=.S))
SRCS	+= $(addprefix $(SRCTREE)/examples/api/,$(COBJ_FILES-y:.o=.c))
SRCS	+= $(addprefix $(SRCTREE)/examples/api/,$(SOBJ_FILES-y:.o=.S))

# Create a list of object files to be compiled
OBJS	+= $(addprefix $(obj),$(SOBJ_FILES-y))
OBJS	+= $(addprefix $(obj),$(COBJ_FILES-y))
OBJS	+= $(addprefix $(obj),$(notdir $(EXT_COBJ_FILES-y)))
OBJS	+= $(addprefix $(obj),$(notdir $(EXT_SOBJ_FILES-y)))

gcclibdir := $(shell dirname `$(CC) -print-libgcc-file-name`)

CPPFLAGS += -I..

all:	$(obj).depend $(OUTPUT)

#########################################################################

$(OUTPUT):	$(OBJS)
		$(LD) -Ttext $(LOAD_ADDR) -o $@ $^ -L$(gcclibdir) -lgcc
		$(OBJCOPY) -O binary $@ $(OUTPUT).bin 2>/dev/null

# Rule to build generic library C files
$(obj)%.o: $(SRCTREE)/lib/%.c
	$(CC) -g $(CFLAGS) -c -o $@ $<

# Rule to build architecture-specific library assembly files
$(obj)%.o: $(SRCTREE)/arch/$(ARCH)/lib/%.S
	$(CC) -g $(CFLAGS) -c -o $@ $<

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
