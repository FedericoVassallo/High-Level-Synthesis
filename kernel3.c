void kernel3(float hist[ARRAY_SIZE], float weight[ARRAY_SIZE],
             int index[ARRAY_SIZE]) {
    int prev_idx = -1;
    float prev_value = 0.0f;

    loop: for (int i = 0; i < ARRAY_SIZE; ++i) {
        #pragma HLS dependence variable=hist type=inter direction=RAW dependent=false
        #pragma HLS pipeline II=3 style=stp

        int idx = index[i];
        float w = weight[i];

        float old_value = (idx == prev_idx) ? prev_value : hist[idx];
        float result = old_value + w;

        hist[idx] = result;

        prev_idx = idx;
        prev_value = result;
    }
}