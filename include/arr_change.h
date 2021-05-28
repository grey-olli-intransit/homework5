// Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0 (** без применения if-else, switch, () ? :);
int arr[10]={ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

namespace pvt {


    void arr_change(int * array, int arr_size) {
        for(int i=0;i<arr_size;i++)
    	    *(array +i)=!(*(array +i));
    }

    void arr_change2(int * array, int arr_size) {
        for(int i=0;i<arr_size;i++) {
	    unsigned int val=(unsigned int)*(array +i);
	    val = ~val; 
	    val = val << (sizeof(int)*8-1);
	    val = val >> (sizeof(int)*8-1);
    	    *(array +i)=(int)val ;
	}
    }

    void arr_change3(int * array, int arr_size) {
        for(int i=0;i<arr_size;i++) {
	    int val=*(array + i);
            // val = -(val - 1); у меня было до подсказки, оставил более оптимальный вариант (возможно компилятор сократил бы до него):
	    val = 1 - val;
    	    *(array +i)=val;
	}
    }
    
    // больше трёх вариантов инверсии у меня не получилось.
}
