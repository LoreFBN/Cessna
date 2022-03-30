#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libs/engine/engine_rwv.h"

int main(){
    char filename[20]= "engine";
    //printf("inserire il nome del file di testo:");
    //scanf("%s",filename);
    read_engine(strcat(filename,".txt"));
    return 0;
}