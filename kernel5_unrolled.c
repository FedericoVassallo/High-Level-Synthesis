float kernel5(float bound, float a[ARRAY_SIZE], float b[ARRAY_SIZE]) {
    #pragma HLS array_partition variable=a type=cyclic factor=2 dim=1
    #pragma HLS array_partition variable=b type=cyclic factor=2 dim=1

    float result = 0.0f;
    bool found = false;

loop: for (int i = 0; i + 1 < ARRAY_SIZE; i += 2) {
        #pragma HLS pipeline II=1 style=stp

        float sum1 = a[i]     + b[i];
        float sum2 = a[i + 1] + b[i + 1];

        bool crossed1 = (sum1 >= bound);
        bool crossed2 = (sum2 >= bound);

        if (!found) {
            result = crossed1 ? sum1 : sum2;
            found = crossed1 || crossed2;
        }
    }

    if ((ARRAY_SIZE % 2) == 1 && !found) {
        result = a[ARRAY_SIZE - 1] + b[ARRAY_SIZE - 1];
    }

    return result;
}

