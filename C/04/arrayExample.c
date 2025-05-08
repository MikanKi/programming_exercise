int main(void){
    int array[3][5] = {{}};

    array[0][4] = 3;
    array[0][5] = 4;
    array[1][3] = array[2][0];
    array[3][1] = array[1][3]+1;
    // array = 0;
    // array[2] = 123;
    // array[0] = array[1];
    
    return 0;
}