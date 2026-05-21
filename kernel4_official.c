void kernel4(int array[ARRAY_SIZE], int index[ARRAY_SIZE], int offset) {

    int result = array[offset];
    int currentarray = array[offset + 1];

    loop: for (int i = offset + 1; i < ARRAY_SIZE - 1; ++i) {
        #pragma HLS pipeline II=1 style=stp
        int nextarray = array[i + 1];
        result = result + index[i] * (nextarray - currentarray);
        currentarray = nextarray;
    }

    array[offset] = result;
}

