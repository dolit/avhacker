#include <stdio.h>
#include "include/avhacker/avhacker.h"

int avhacker_create(
    const char* init_path,
    avhacker_ctx* ctx
    )
{

    return AHE_OK;
}

int avhacker_parse(
    avhacker_ctx ctx, 
    const char* query_info, 
    char** result
    )
{
    return AHE_OK;
}

void avhacker_close(
    avhacker_ctx ctx
    )
{

}

void avhacker_free(
    void* data
    )
{

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
