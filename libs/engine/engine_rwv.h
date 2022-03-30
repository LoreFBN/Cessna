#ifndef ENGINE_CHECK_H
#define ENGINE_CHECK_H

void read_engine(char string[20]);

typedef struct database {
    float P_max_sl;
    float sigma;
    float rpm_max;
    float rpm_min;
    float reduction_ratio;
    float efficiency;
    float spec_consumption;
} db;

db write_engine(char [20]);
void validation_engine(db engine);

#endif