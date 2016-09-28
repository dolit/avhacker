/* Copyright Dolit, Inc. All rights reserved.
 */

#ifndef AVHACKER_INTERNAL_H
#define AVHACKER_INTERNAL_H

#include "lua.h"
#include "lualib.h"
#define AVH_MAX_PATH 512;

typedef struct {
    lua_State* L;
} avhacker_internal;

#endif
