/* Copyright Dolit, Inc. All rights reserved.
 */

#ifndef AVHACKER_H
#define AVHACKER_H

typedef void* avhacker_ctx;

#define AVHACKER_ERROR_MAP(XX)\
    XX(OK, "success")\
    XX(UNKNOWN, "an unknown error occurred")\
    XX(LOAD_BOOT, "load boot file error")\
    XX(SCRIPT_EXECUTE, "script execute error")

#define AVHACKER_ERROR_GEN(n, s) AHE_##n,
typedef enum {
    AVHACKER_ERROR_MAP(AVHACKER_ERROR_GEN)
} avhacker_errno;
#undef AVHACKER_ERROR_GEN

int avhacker_create(
    const char* boot_file,
    const char* conf,
    avhacker_ctx* ctx
    );

int avhacker_parse(
    avhacker_ctx ctx,
    const char* query_info,
    char** result
    );

void avhacker_close(
    avhacker_ctx ctx
    );

void avhacker_free( 
    void* data
    );

const char* avhacker_errno_description(
    avhacker_errno error
    );

#endif
