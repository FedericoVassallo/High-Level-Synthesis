void kernel4 (int array[ARRAY_SIZE], int index[ARRAY_SIZE], int offset) {

    int result = array[offset];
    int nextarray = array[offset + 2];
    int currentarray = array[offset + 1];

    loop: for (int i = offset + 1; i < ARRAY_SIZE - 2; ++i) {
        #pragma HLS pipeline II=1 style=stp
        result = result + index[i] * (nextarray - currentarray);
        currentarray = nextarray;
        nextarray = array[i + 2];
    }
    array[offset] = result + index[ARRAY_SIZE - 2] * (nextarray - currentarray);    // we can just store it at the end of the loop since we keep it updated
}

