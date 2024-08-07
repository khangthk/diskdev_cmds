/*
 * Copyright (c) 1999-2018, 2023 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*-
 * Copyright (c) 1980, 1989, 1993, 1994
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *  This product includes software developed by the University of
 *  California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/mount.h>
#include <sys/param.h>
#include "mount_flags.h"

/*
 * This file is intended to be compiled into whichever projects need
 * to access the MNT_* bit => string mappings.  It could be made into a
 * library but that's unnecessary at present.
 */

const mountopt_t optnames[] = {
    { MNT_ASYNC,        "asynchronous", "async",        },
    { MNT_EXPORTED,     "NFS exported", NULL,           },
    { MNT_LOCAL,        "local",        NULL,           },
    { MNT_NODEV,        "nodev",        "nodev",        },
    { MNT_NOEXEC,       "noexec",       "noexec",       },
    { MNT_NOSUID,       "nosuid",       "nosuid",       },
    { MNT_QUOTA,        "with quotas",  NULL,           },
    { MNT_RDONLY,       "read-only",    "rdonly",       },
    { MNT_SYNCHRONOUS,  "synchronous",  "sync",         },
    { MNT_UNION,        "union",        "union",        },
    { MNT_AUTOMOUNTED,  "automounted",  NULL,           },
    { MNT_JOURNALED,    "journaled",    NULL,           },
    { MNT_DEFWRITE,     "defwrite",     NULL,           },
    { MNT_IGNORE_OWNERSHIP, "noowners", "noowners",     },
    { MNT_NOATIME,      "noatime",      "noatime",      },
    { MNT_STRICTATIME,  "strictatime",  "strictatime",  },
    { MNT_QUARANTINE,   "quarantine",   "quarantine",   },
    { MNT_DONTBROWSE,   "nobrowse",     "nobrowse",     },
    { MNT_CPROTECT,     "protect",      "protect",      },
    { 0,                NULL,           NULL,           }, // must be last
};

const mountopt_t extoptnames[] = {
    { MNT_EXT_ROOT_DATA_VOL,    "root data",    NULL,           },
    { MNT_EXT_FSKIT,            "fskit",        NULL,           },
    { 0,                        NULL,           NULL,           }, // must be last
};

