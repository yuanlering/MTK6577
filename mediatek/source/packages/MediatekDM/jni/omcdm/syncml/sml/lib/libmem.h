/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

/*[
 *      Project:    	    OMC
 *
 *      Name:				libmem.h
 *
 *      Derived From:		Original
 *
 *      Created On:			May 2004
 *
 *      Version:			$Id: //depot/main/base/syncml/sml/lib/libmem.h#5 $
 *
 *      Coding Standards:	3.0
 *
 *      Purpose:            SyncML core code
 *
 *      (c) Copyright Insignia Solutions plc, 2004 - 2005
 *
]*/

/**
 * @file
 * Library for Memory Functions
 *
 * @target_system   ALL
 * @target_os       ALL
 * @description Header for the implementation of common memory handling functions
 */



/*
 * Copyright Notice
 * Copyright (c) Ericsson, IBM, Lotus, Matsushita Communication
 * Industrial Co., Ltd., Motorola, Nokia, Openwave Systems, Inc.,
 * Palm, Inc., Psion, Starfish Software, Symbian, Ltd. (2001).
 * All Rights Reserved.
 * Implementation of all or part of any Specification may require
 * licenses under third party intellectual property rights,
 * including without limitation, patent rights (such a third party
 * may or may not be a Supporter). The Sponsors of the Specification
 * are not responsible and shall not be held responsible in any
 * manner for identifying or failing to identify any or all such
 * third party intellectual property rights.
 *
 * THIS DOCUMENT AND THE INFORMATION CONTAINED HEREIN ARE PROVIDED
 * ON AN "AS IS" BASIS WITHOUT WARRANTY OF ANY KIND AND ERICSSON, IBM,
 * LOTUS, MATSUSHITA COMMUNICATION INDUSTRIAL CO. LTD, MOTOROLA,
 * NOKIA, PALM INC., PSION, STARFISH SOFTWARE AND ALL OTHER SYNCML
 * SPONSORS DISCLAIM ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION
 * HEREIN WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
 * SHALL ERICSSON, IBM, LOTUS, MATSUSHITA COMMUNICATION INDUSTRIAL CO.,
 * LTD, MOTOROLA, NOKIA, PALM INC., PSION, STARFISH SOFTWARE OR ANY
 * OTHER SYNCML SPONSOR BE LIABLE TO ANY PARTY FOR ANY LOSS OF
 * PROFITS, LOSS OF BUSINESS, LOSS OF USE OF DATA, INTERRUPTION OF
 * BUSINESS, OR FOR DIRECT, INDIRECT, SPECIAL OR EXEMPLARY, INCIDENTAL,
 * PUNITIVE OR CONSEQUENTIAL DAMAGES OF ANY KIND IN CONNECTION WITH
 * THIS DOCUMENT OR THE INFORMATION CONTAINED HEREIN, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH LOSS OR DAMAGE.
 *
 * The above notice and this paragraph must be included on all copies
 * of this document that are made.
 *
 */



#ifndef _LIB_MEM_H
#define _LIB_MEM_H



/*************************************************************************
 *  Definitions
 *************************************************************************/

#include <stdlib.h>
#include <syncml/sml/smldef.h>
#ifdef __ANSI_C__
#include <string.h>
#endif
#ifdef __PALM_OS__
#include <MemoryMgr.h>
#endif


/*************************************************************************
 *  External Functions for all Toolkit versions
 *************************************************************************/


#ifdef __PALM_OS__  /* we use #define to reduce heap usage */
 void *smlLibRealloc (VoidPtr_t objectP, MemSize_t constSize);
 void smlLibFree (void* objectP);
 #define	smlLibMemset(pObject,value,count)		((void)MemSet((VoidPtr_t)pObject,(MemSize_t)count,(int)value))
 #define	smlLibMemcpy(pTarget,pSource,count)		(MemMove(pTarget,(VoidPtr_t)pSource,count) ? pTarget : pTarget)
 #define	smlLibMemmove(pTarget,pSource,count)		(MemMove(pTarget,(VoidPtr_t)pSource,(MemSize_t)count) ? pTarget : pTarget)
 #define	smlLibMemcmp(pTarget,pSource,count)		(MemCmp((VoidPtr_t)pTarget,(VoidPtr_t)pSource,(MemSize_t)count))
 #define	smlLibMalloc(size)		((VoidPtr_t)MemPtrNew((MemSize_t)size))
 #define	smlLibMemsize(pObject)		((MemSize_t)MemPtrSize((VoidPtr_t)pObject))
#else
/*
 * OMC does not support this function:
 *
 * SML_API_DEF void	*smlLibRealloc(void *pObject, MemSize_t size);
 */
  SML_API_DEF void 	*smlLibMemset(void *pObject, int value, MemSize_t count);
  SML_API_DEF void 	*smlLibMemcpy(void *pTarget, const void *pSource, MemSize_t count);
  SML_API_DEF void 	*smlLibMemmove(void *pTarget, const void *pSource, MemSize_t count);
  SML_API_DEF int		smlLibMemcmp(const void *pTarget, const void *pSource, MemSize_t count);

#ifdef OMC_MEM_DEBUG
  SML_API_DEF void	smlLibFreeDB(void *pObject, char* file, int line);
  SML_API_DEF void	*smlLibMallocDB(MemSize_t size, char* file, int line);

#ifdef PROD_MIN
  #define smlLibFree(pObject)	smlLibFreeDB(pObject, NULL, 0)
  #define smlLibMalloc(size) 	smlLibMallocDB(size, NULL, 0)
#else
  #define smlLibFree(pObject)	smlLibFreeDB(pObject, __FILE__, __LINE__)
  #define smlLibMalloc(size) 	smlLibMallocDB(size, __FILE__, __LINE__)
#endif

#else /* OMC_MEM_DEBUG */

  SML_API_DEF void	smlLibFree(void *pObject);
  SML_API_DEF void	*smlLibMalloc(MemSize_t size);

#endif /* OMC_MEM_DEBUG */
#endif


#endif

