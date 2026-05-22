void kernel3(float hist[ARRAY_SIZE], float weight[ARRAY_SIZE],
             int   index[ARRAY_SIZE]) {
    static float partial_hist[5][ARRAY_SIZE] = {0};
    #pragma HLS array_partition variable=partial_hist type=complete dim=1

    int current_line = 0;
    main_loop: for (int i = 0; i < ARRAY_SIZE; i++) {
        #pragma HLS pipeline II=1
        partial_hist[current_line][index[i]] = partial_hist[current_line][index[i]] + weight[i];
        current_line = (current_line == 4) ? 0 : current_line + 1;
    }

    merge_loop: for (int k = 0; k < ARRAY_SIZE; k++) {
        #pragma HLS pipeline II=3

        float original_hist  = hist[k];
        float line0 = partial_hist[0][k];
        float line1 = partial_hist[1][k];
        float line2 = partial_hist[2][k];
        float line3 = partial_hist[3][k];
        float line4 = partial_hist[4][k];

        float p0 = original_hist  + line0;     
        float p1 = line1 + line2;
        float p2 = line3 + line4;
        float q0 = p0 + p1;     
        float result  = q0 + p2;    

        hist[k] = result;            
    }
}