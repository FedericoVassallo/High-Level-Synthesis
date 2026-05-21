#include <stdbool.h>

float kernel5(float bound, float a[ARRAY_SIZE], float b[ARRAY_SIZE]) {
    float result = 0.0f;
    bool found = false;
    float tmp = 0.0f;

loop: for (int i = 0; i < ARRAY_SIZE; ++i) {
        #pragma HLS pipeline II=1 style=stp
        tmp = a[i] + b[i];

        result = (!found) ? tmp : result;
        found  = found || (tmp >= bound);
    }

    return result;
}