#ifndef FILE_RW_H
#define FILE_RW_H

void lettura_file_dba(char *testo);
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
                        double *Cmom    ,double *Cnom ,char testo[20]);

#endif
