#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h> // for sleep function
#include "engine_rwv.h"

void read_engine(char *file_text){

    // Define variable file
    FILE *engine_text;
    // checking the file if it exists or not
    int flag = 0;
    //printf("you are inside the function, ad you passed: %s\n",file_text);
    while(flag == 0){

        engine_text = fopen(file_text,"r");

        if(strcmp(file_text,"exit.txt")==0){ // EXIT FROM THE SIMULATION
            printf("Exit from the simulation");
            exit(1);
        }

        else if(engine_text == NULL){ // FILE NOT FOUND
         printf("Error! You typed: %s; file not found.\nTry again or type 'exit' to stop the simulation: ",file_text);
         scanf("%s",file_text);
         //printf("You typed: %s\n",strcat(file_text,".txt"));
        }

        else{ // FILE OPENED
            printf("file opened correctly!\n");
            flag = 1;
        }
    }
    fclose(engine_text);
    return;
}

db write_engine(char file_txt[20]){
    db engine;
    FILE *engine_text;
    //printf("you are inside the function, ad you passed: %s\n",file_txt);
    engine_text = fopen(file_txt,"r");
    printf("***********************************************************\n");
    // COUNTER FOR THE LONGEST ROW FROM THE FILE
    int counter_col = 1;
    int counter_row = 1;
    int max_row_length = 0;
    int row_pos = 0;

    while(!feof(engine_text)){
        while(fgetc(engine_text) != '\n'){
            counter_col++;
        }
        if (counter_col > max_row_length){
            max_row_length = counter_col + 1;
            row_pos = counter_row;
            //printf("max row length = %d\nat the row number = %d\n",max_row_length,counter_row);
        }
        counter_col = 0;
        //printf("you are at row: %d\n",counter_row);
        counter_row++;
    }
    //printf("You exit from while cycle!\nMax row lenght is: %d\nat row pos: %d",max_row_length,row_pos);
    engine.P_max_sl = 100;
    return engine;
}
