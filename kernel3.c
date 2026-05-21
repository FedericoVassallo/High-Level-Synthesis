void kernel3(float hist[ARRAY_SIZE], float weight[ARRAY_SIZE],
             int index[ARRAY_SIZE]) {
    int prev_idx = -1;
    float prev_value = 0.0f;

    loop: for (int i = 0; i < ARRAY_SIZE; ++i) {
        #pragma HLS dependence variable=hist type=inter direction=RAW dependent=false
        #pragma HLS pipeline II=3 style=stp

        float old_value = (index[i] == prev_idx) ? prev_value : hist[index[i]];
        float result = old_value + weight[i];;

        hist[index[i]] = result;

        prev_idx = index[i];
        prev_value = result;
    }
}