#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libs/engine/engine_rwv.h"

int main(){
    char filename[20];
    printf("Type the text file: ");
    scanf("%s",filename);
    //printf("You typed: %s\n",strcat(filename,".txt"));
    read_engine(&filename[0]);
    //printf("correct filename updated in the main: %s\n",filename);
    db engine = write_engine(filename);
    //printf("you modified engine as: %f",engine.P_max_sl);
    return 0;
}
