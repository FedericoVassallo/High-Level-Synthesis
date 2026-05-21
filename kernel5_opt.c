float kernel5 (float bound, float a[ARRAY_SIZE], float b[ARRAY_SIZE]) {
    int i = 0;
    float sum = 0;

    while (sum < bound && i < ARRAY_SIZE) {
        
        sum = a[i] + b[i];
        i++;
    }

    return sum;
}

