/* Copyright Dolit, Inc. All rights reserved.
 */

#include <stdio.h>
#include "avhacker/avhacker.h"

int main( int argc, char* argv[] ) {

    avhacker_ctx ctx;
    int ret = AHE_OK;
    char* parse_result = 0;
    ret = avhacker_create( "E:\\other\\avhacker\\test\\test.lua", "test", &ctx);
    if ( ret != AHE_OK || ctx == 0) {
        goto cleanup;
    }
    ret = avhacker_parse( ctx, "http://v.youku.com/v_show/id_XMTczOTY0MTM2MA==.html?spm=a2hww.20023042.m_223465.5~5~5~5~5~5~A&from=y1.3-idx-beta-1519-23042.223465.1-1", &parse_result);
    if ( ret != AHE_OK) {
        goto cleanup;
    }
    if ( parse_result == 0) {
        goto cleanup;
    }

    printf( "parse result: %s\n", parse_result);

    //int ret = avhacker_create( "/mnt/e/other/avhacker/test/test.lua", "", &ctx);
cleanup:
    if ( ret != AHE_OK) {
        printf("error code : %s\n", avhacker_errno_description( ret));
    }
    if ( parse_result != 0) {
        avhacker_free( parse_result);
    }
    if ( ctx != 0) {
        avhacker_close( ctx );
    }
    return ret;
}
