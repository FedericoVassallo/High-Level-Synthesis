void kernel1 (int array[ARRAY_SIZE]) {
    #pragma HLS array_partition variable=array type=cyclic factor=6 dim=1
    loop: for(int i = 0; i < ARRAY_SIZE; i++) {
        #pragma HLS unroll factor=2
        #pragma HLS pipeline II=1 style=stp
        array[i] = (array[i] << 2) + array[i];           
    }   
}



