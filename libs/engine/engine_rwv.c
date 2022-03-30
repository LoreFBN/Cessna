#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "engine_rwv.h"

void read_engine(char file_text[20]){

    // Define variable file
    FILE *engine_text;

    engine_text = fopen(file_text,"r");
    // checking the file if it exists or not
      if(engine_text == NULL){
         printf("Error! File not found, try again: ");
         scanf("%s",file_text);
      }
      else{
         printf("file aperto correttamente!");
      }
    return; 
}