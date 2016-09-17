#include <stdio.h>
#include "avhacker/avhacker.h"
int main(int argc, char* argv[]){
    avhacker_init();
    avhacker_parse();
    avhacker_uninit();
    return 0;
}
