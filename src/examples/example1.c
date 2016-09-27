#include <stdio.h>
#include "avhacker/avhacker.h"

int main(int argc, char* argv[]){
    avhacker_ctx ctx;
    int ret = avhacker_create( "", &ctx);
    printf("error code : %s\n", avhacker_errno_description( ret));
    avhacker_close( ctx );
    return 0;
}
