void kernel2 (int array[ARRAY_SIZE]) {
    int previous0 = array[0];
    int previous1 = array[1];
    int previous2 = array[2];

    loop: for(int i = 3; i < ARRAY_SIZE; i++) {
        #pragma HLS pipeline II=3 style=stp
        int result = previous2 + previous1 * previous0; 
        array[i] = result;

        previous0 = previous1;
        previous1 = previous2;
        previous2 = result;
    }
}