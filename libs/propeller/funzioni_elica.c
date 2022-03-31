#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "libreria_elica.h"

void lettura_file_elica(char *nome_file){
    printf("****************************LETTURA DEL FILE*******************************\n");

    FILE *file_di_testo;
    int flag = 0;// Definizione variabile per uscire dal while

    while(flag == 0){

        file_di_testo = fopen(nome_file,"r");

        if(strcmp(nome_file,"exit.txt")==0){ // Confronto stringa per uscire dalla simulazione
            printf("Sei uscito dalla simulazone!");
            exit(1);
        }

//        else if(strcmp(nome_file,"engine.txt") == 0 || strcmp(nome_file,"dba.txt") == 0 ){
//            printf("inserito file errato, leggere prima 'engine'!\n Inserire il nome: ");
//            scanf("%s",nome_file);
//            strcat(nome_file,".txt");
//        }

        else if(file_di_testo == NULL){ // File non trovato
         printf("Errore! Il file %s non e' stato trovato o non estste.\nProvare ancora o scrivere 'exit' per fermare la simulazione: ",nome_file);
         scanf("%s",nome_file);
         strcat(nome_file,".txt");
        }

        else{ // file aperto
            printf("file aperto correttamente!\n");
            flag = 1;// uscita dal ciclo while
        }
    }
    fclose(file_di_testo);
    return;
}

void scrittura_file_elica(double *datipropeller, double *CSI, double *RD, double *CHAD, double *BA, char nome_file[20]){

    FILE *file_di_testo;
    file_di_testo = fopen(nome_file,"r");

    printf("****************************CONTATORE LUNGHEZZA MASSIMA DELLA RIGA*******************************\n");

    int conta_caratteri = 1;
    int conta_righe = 1;
    int max_lunghezza_riga = 0;
    char ch;

    while((ch = fgetc(file_di_testo)) != EOF){
        //putchar(ch); // utile per scrivere l'intero file di testo se si vuole.
        //sleep(0.8);
        if(ch == '\n'){
            if (conta_caratteri > max_lunghezza_riga){
                max_lunghezza_riga = conta_caratteri;
            }
            conta_caratteri = 0;
            conta_righe++;
        }
        else{
            conta_caratteri++;
        }
    }
    printf("Lunghezza massima della riga: %d\n",max_lunghezza_riga);
    rewind(file_di_testo);


    printf("****************************SCRITTURA DEL DATABASE*******************************\n");
    //mi assicuro di leggere e salvare intere stringhe nel file
    max_lunghezza_riga = max_lunghezza_riga*10;
    char stringa[max_lunghezza_riga]; //Vettore che registra la riga del file come una stringa
    printf("Lunghezza di sicurezza della stringa: %d\n",(max_lunghezza_riga));

    printf("Database costante dell'elica:\n");

    // scrivo il database
    int indice = 0; //indice del database

    while (fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<11){
        if(stringa[0] != '*' && stringa[0] != '\n'){
                sscanf(stringa,"%lf", &datipropeller[indice]);
                printf("posizione: %d -> valore: %.10lf\n",indice,datipropeller[indice]);
                indice++;
        }
    }
    indice = 0;
    printf("Database variabile dell'elica:\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<60){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf", &CSI[indice],&RD[indice],&CHAD[indice],&BA[indice]);
            printf("posizione: %d -> valore: %.10lf %.10lf %.10lf %.10lf\n",indice,CSI[indice],RD[indice],CHAD[indice],BA[indice]);
            indice++;
        }
    }
    fclose(file_di_testo);
    return;
}
