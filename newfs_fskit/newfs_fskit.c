/*
 * Copyright (c) 2024 Apple Computer, Inc. All rights reserved.
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

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../disklib/fskit_support.h"


#define DEFAULT_EXIT_CODE 1 /* Standard Error exit code for newfs */

static void usage();

static void usage(void) {
    fprintf(stderr, "Usage: newfs_fskit [-t fstype] <options> device\n");
    exit(DEFAULT_EXIT_CODE);
}

int main(int argc, const char * argv[]) {

    int ret;
    bool typeOptionFound = false;
    bool typeValueFound = false;

    if (argc < 4) {
        usage();
    }

    // We are only supporting `newfs_fskit -t fstype <otheroptions> someDisk`, different filesystem use different options, so we are going
    // to leave the option parsing to FSKit.

    if (strcmp(argv[1], "-t") == 0) {
        typeOptionFound = true;
    }
    if (strncmp("-", argv[2], 1) != 0) {
        typeValueFound = true;
    }

    if(!typeOptionFound || !typeValueFound) {
        errx(1, "No file system type was provided");
    }

    // invoke_tool_from_fskit expects arguments to look like "fstype <other_options> disk", so we are ignoring `fsck_fskit` and `-t` arguments.
    argc -= 2;
    argv += 2;

    ret = invoke_tool_from_fskit(format_fs_op, 0, argc, argv);
    exit(ret);

}
