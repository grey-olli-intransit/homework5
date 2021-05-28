namespace pvt {

    // * Написать функцию, в которую передается не пустой одномерный целочисленный массив, 
    //   функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. 
    //   Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
    //            checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
    bool checkBalance(int * array, int array_size) {
        int summ_right=0,summ_left=0;
        for(int j=0;j<array_size-1;j++) {
            summ_right=0;
            for(int i=j+1;i<array_size;i++)
                summ_right = summ_right + *(array+i);
            summ_left = summ_left + *(array+j);
	    if (summ_left == summ_right) return true;
        }
        return false;
    }

}
