/* Copyright Dolit, Inc. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "include/avhacker/avhacker.h"
#include "avhacker_internal.h"

int avhacker_create(
    const char* boot_file,
    const char* conf,
    avhacker_ctx* ctx
    )
{
    int ret = AHE_OK;
    avhacker_internal* avh = (avhacker_internal*)malloc( sizeof(avhacker_internal));
    *ctx = avh;
    memset( avh, 0, sizeof(avhacker_internal));
    avh->L = luaL_newstate( );
    if ( avh->L == 0) {
        ret = AHE_UNKNOWN;
        goto cleanup;
    }
    luaL_openlibs( avh->L);
    ret = luaL_dofile( avh->L, boot_file);
    if ( ret != 0) {
        ret = AHE_LOAD_BOOT;
        goto cleanup;
    }
    lua_getglobal( avh->L, "avh_load");
    lua_pushstring( avh->L, conf);
    ret = lua_pcall( avh->L, 1, 0, 0);
    if ( ret != 0) {
        ret = AHE_SCRIPT_EXECUTE;
        goto cleanup;
    }
    ret = (int)lua_tonumber( avh->L, -1);
cleanup:
    if ( ret == AHE_OK ) {
        return ret;
    }
    if ( avh->L != 0) {
        lua_close( avh->L);
        avh->L = 0;
    }
    if ( avh) {
        free( avh);
        *ctx = 0;
    }
    return ret;
}

int avhacker_parse(
    avhacker_ctx ctx, 
    const char* query_info, 
    char** result
    )
{
    int ret = AHE_OK;
    const char* parse_result;
    avhacker_internal* avh = (avhacker_internal*)ctx;
    *result = 0;
    lua_getglobal( avh->L, "avh_parse");
    lua_pushstring( avh->L, query_info);
    ret = lua_pcall( avh->L, 1, 1, 0);
    if ( ret != 0) {
        ret = AHE_SCRIPT_EXECUTE;
        goto cleanup;
    }
    parse_result = lua_tostring( avh->L, -1);
    if ( parse_result ) {
        int len = strlen( parse_result);
        *result = malloc( len + 1);
        strcpy( *result, parse_result);
    }
    lua_pop( avh->L, 1);
cleanup:
    if ( ret != AHE_OK) {
        if ( *result) {
            free( *result);
        }
    }
    return ret;
}

void avhacker_close(
    avhacker_ctx ctx
    )
{
    avhacker_internal* avh = (avhacker_internal*)ctx;
    if ( avh->L != 0) {
        lua_close( avh->L);
        avh->L = 0;
    }
    if ( avh) {
        free( avh);
    }
}

void avhacker_free(
    void* data
    )
{
    free(data);
}

#define AVHACKER_ERROR_GEN(n, s) { "AHE_" #n, s },
static struct {
    const char *name;
    const char *description;
} avhacker_strerror_tab[] = {
    AVHACKER_ERROR_MAP(AVHACKER_ERROR_GEN)
};
#undef AVHACKER_ERROR_GEN

const char* avhacker_errno_description(
    avhacker_errno error
    )
{
    return avhacker_strerror_tab[error].description;
}
