float kernel5 (float bound, float a[ARRAY_SIZE], float b[ARRAY_SIZE]) {
    int i = 0;
    float sum = 0;

    loop: while (sum < bound && i < ARRAY_SIZE) {
        #pragma HLS pipeline II=4 style=stp
        sum = a[i] + b[i];
        i++;
    }

    return sum;
}

