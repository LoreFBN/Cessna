#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "libreria_dba.h"

void lettura_file_dba(char *nome_file){
    printf("****************************LETTURA DEL FILE*******************************\n");

    FILE *file_di_testo;
    int flag = 0;// Definizione variabile per uscire dal while

    while(flag == 0){

        file_di_testo = fopen(nome_file,"r");

        if(strcmp(nome_file,"exit.txt")==0){ // Confronto stringa per uscire dalla simulazione
            printf("Sei uscito dalla simulazone!");
            exit(1);
        }

//        else if(strcmp(nome_file,"engine.txt") == 0 || strcmp(nome_file,"propeller.txt") == 0 ){
//            printf("inserito file errato, inserire 'dba'!\n Inserire il nome: ");
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

void scrittura_file_dba(double *vehicledescription, double *deflectionlimit, double *fuelmass, double *alpha, double *CX,
                        double *CY      ,double *CZ   ,double *Cl   ,double *Cm   ,double *Cn  ,double *CXA,
                        double *CXAP    ,double *CXU  ,double *CXQ  ,double *CXB  ,double *CXP ,double *CXR,
                        double *CYB     ,double *CYBP ,double *CYP  ,double *CYR  ,double *CYA ,double *CYQ,
                        double *CZALPHA ,double *CZAP ,double *CZU  ,double *CZQ  ,double *CZB ,double *CZP,
                        double *CZR     ,double *ClB  ,double *ClBP ,double *ClP  ,double *ClR ,double *ClA,
                        double *ClQ     ,double *CmA  ,double *CmAP ,double *CmU  ,double *CmQ ,double *CmB,
                        double *CmP     ,double *CmR  ,double *CnB  ,double *CnBP ,double *CnP ,double *CnR,
                        double *CnA     ,double *CnQ  ,double *CXde ,double *CXdle,double *CZde,double *CZdle,
                        double *CYda    ,double *CYdr ,double *Clda ,double *Cldr ,double *Cmde,double *Cmdle,
                        double *Cnda    ,double *Cndr ,double *CXom ,double *CYom ,double *CZom,double *Clom,
                        double *Cmom    ,double *Cnom ,char nome_file[20]){

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

    printf("Database Aerodinamco:\n");

    // scrivo il database
    printf("Vehicle description\n");
    int indice = 0; //indice del database
    while (fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<22){
        if(stringa[0] != '*' && stringa[0] != '\n'){
                sscanf(stringa,"%lf", &vehicledescription[indice]);
                printf("posizione: %d -> valore: %.4lf\n",indice,vehicledescription[indice]);
                indice++;
        }
    }
    system("pause");
    printf("deflection limit\n");
    indice = 0;
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<6){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf", &deflectionlimit[indice]);
            printf("posizione: %d -> valore: %.4lf\n",indice,deflectionlimit[indice]);
            indice++;
        }
    }
    system("pause");
    printf("fuel mass\n");
    indice = 0;
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<2){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf", &fuelmass[indice]);
            printf("posizione: %d -> valore: %.4lf\n",indice,fuelmass[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CX \t  CY \t CZ \t Cl \t Cm \t Cn\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CX[indice],&CY[indice],&CZ[indice],&Cl[indice],&Cm[indice],&Cn[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],CX[indice],CY[indice],CZ[indice],Cl[indice],Cm[indice],Cn[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CXA \t  CXAP \t CXU \t CXQ \t CXB \t CXP \t CXR\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CXA[indice],&CXAP[indice],&CXU[indice],&CXQ[indice],&CXB[indice],&CXP[indice],&CXR[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf %.4f\n",indice,alpha[indice],CXA[indice],CXAP[indice],CXU[indice],CXQ[indice],CXB[indice],CXP[indice],CXR[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CYB \t  CYBP \t CYP \t CYR \t CYA \t CYQ\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CYB[indice],&CYBP[indice],&CYP[indice],&CYR[indice],&CYA[indice],&CYQ[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],CYB[indice],CYBP[indice],CYP[indice],CYR[indice],CYA[indice],CYQ[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CZALPHA \t  CZAP \t CZU \t CZQ \t CZB \t CZP \t CZR\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CZALPHA[indice],&CZAP[indice],&CZU[indice],&CZQ[indice],&CZB[indice],&CZP[indice],&CZR[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf %.4f\n",indice,alpha[indice],CZALPHA[indice],CZAP[indice],CZU[indice],CZQ[indice],CZB[indice],CZP[indice],CZR[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t ClB \t  ClBP \t ClP \t ClR \t ClA \t ClQ\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&ClB[indice],&ClBP[indice],&ClP[indice],&ClR[indice],&ClA[indice],&ClQ[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],ClB[indice],ClBP[indice],ClP[indice],ClR[indice],ClA[indice],ClQ[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CmA \t  CmAP \t CmU \t CmQ \t CmB \t CmP \t CmR\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CmA[indice],&CmAP[indice],&CmU[indice],&CmQ[indice],&CmB[indice],&CmP[indice],&CmR[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf %.4lf\n",indice,alpha[indice],CmA[indice],CmAP[indice],CmU[indice],CmQ[indice],CmB[indice],CmP[indice],CmR[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CnB \t  CnBP \t CnP \t CnR \t CnA \t CnQ\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CnB[indice],&CnBP[indice],&CnP[indice],&CnR[indice],&CnA[indice],&CnQ[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],CnB[indice],CnBP[indice],CnP[indice],CnR[indice],CnA[indice],CnQ[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CXde \t  CXdle \t CZde \t CZdle \t CYda \t CYdr\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CXde[indice],&CXdle[indice],&CZde[indice],&CZdle[indice],&CYda[indice],&CYdr[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],CXde[indice],CXdle[indice],CZde[indice],CZdle[indice],CYda[indice],CYdr[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t Clda \t  Cldr \t Cmde \t Cmdle \t Cnda \t Cndr\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&Clda[indice],&Cldr[indice],&Cmde[indice],&Cmdle[indice],&Cnda[indice],&Cndr[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],Clda[indice],Cldr[indice],Cmde[indice],Cmdle[indice],Cnda[indice],Cndr[indice]);
            indice++;
        }
    }
    system("pause");
    indice = 0;
    printf("\t \t \t alpha \t CXom \t  CYom \t CZom \t Clom \t Cmom \t Cnom\n");
    while(fgets(stringa,(max_lunghezza_riga),file_di_testo) != NULL && indice<126){
        if (stringa[0] != '*' && stringa[0] != '\n'){
            sscanf(stringa,"%lf %lf %lf %lf %lf %lf %lf",&alpha[indice],&CXom[indice],&CYom[indice],&CZom[indice],&Clom[indice],&Cmom[indice],&Cnom[indice]);
            printf("posizione: %d -> valore: %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf\n",indice,alpha[indice],CXom[indice],CYom[indice],CZom[indice],Clom[indice],Cmom[indice],Cnom[indice]);
            indice++;
        }
    }
    fclose(file_di_testo);
    return;
}
