#ifndef ELICA_SIMULATION_H
#define ELICA_SIMULATION_H

void lettura_file_elica(char *testo);
void scrittura_file_elica(double *database_cost, double *database_CSI, double *database_RD,
                          double *database_CHAD, double *database_BA, char testo[20]);

#endif
