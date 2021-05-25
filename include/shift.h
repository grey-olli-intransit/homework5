namespace pvt {

// * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом функция должна циклически сместить все элементы массива на n позиций. 
 void array_shift(int * array, int array_size, int shift) {
    if (shift > 0) {

     while(shift) {
         int tmp;
         shift--;
         if (array_size==2) {
           tmp=*(array + 0);
           *(array + 0) = *(array + 1);
           *(array + 1) = tmp;
         } 
         else if (array_size == 1)
             return;
         else {
	     int max_index = array_size - 1;
             tmp =*(array + 0);
             *(array + 0) = *(array + max_index);
	     int i=0;
	     while(max_index  - i > 0) { 
                 *(array + max_index - i)=*(array + max_index - i - 1);
                 i++;
	     }
	     *(array + 1)=tmp;
         }
    
     } // while    
     return;
    
    } // shift > 0
    else if (shift == 0)
	    return;
    else {
         shift=-shift;
    
         while(shift) {
             int tmp;
             shift--;
             if (array_size==2) {   // при длине массива в 2 всё равно вправо или влево сдвигать,
                  tmp=*(array + 0); // так что код остаётся тот же.
                  *(array + 0) = *(array + 1);
                  *(array + 1) = tmp;
             } 
             else if (array_size == 1)
                 return;
             else {
	         int max_index = array_size - 1;
                 tmp =*(array + max_index);
                 *(array + max_index) = *(array + 0);

	         int i=0;
	         while(i < max_index - 1) { 
                     *(array + i)=*(array + i + 1);
                     i++;
	         }
	         *(array + max_index - 1)=tmp;
             }
    
     } // while    
     return;
    
    } // else


 } // array_shift


} // namespace
