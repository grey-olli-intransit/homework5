namespace pvt {

// Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
    void arr2_fill(int * array, int arr_size) {
        *(array)=1;
        for(int i=1;i<arr_size;i++)
            *(array +i) = *(array + i - 1) + 3;

    }


}
