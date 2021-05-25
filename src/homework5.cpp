// ** Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы используя указатели на функции.
//

#include <cstdarg.h>
#include <iostream>
#include "arr_change.h"
#include "arr_fill.h"
#include "balance.h"
#include "shift.h"
#include "print.h"
using namespace std;
using namespace pvt;

extern int arr[10];

void (*fptr_arr_change)(int*, int) = pvt::arr_change;

// Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
int arr2[8];
void (*fptr_arr_fill)(int*, int)=pvt::arr2_fill;

bool (*fptr_checkBalance)(int *, int) = pvt::checkBalance;
// fptr_checkBalance = pvt::checkBalance;

// тестовые данные для checkBalance
int arr3[5]={1, 1, 1, 2, 1};
int arr4[5]={2, 1, 1, 2, 1};
int arr5[5]={10, 1, 2, 3, 4};

void (*fptr_array_shift)(int*,int,int)=pvt::array_shift;
int test_array[5]={0,1,2,3,4};

/// Эту функцию через указатель не оформляю, как я и предполагал, в телеграм выяснил, что указатель на такую ф-ю это UB.
// ** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
// уточнение в телеграм:
// написать функцию выводящую инверсию аргумента (1 в 0 и 0 в 1) для произвольного количества параметров принимающих значение 0 или 1 .
void print_inversion(int count, ...) {
    va_list arg_ptr;
    va_start(arg_ptr,count);
    for(int i=0;i<count;i++) {
        int arg=va_arg(arg_ptr,int);
        printf("%d ", !arg);
    }
    cout << endl;
    va_end(arg_ptr);
}

void (* fptr_print_int_array)(int *, size_t )=pvt::print_int_array;

int main() {
    cout << "Before:\n";
    fptr_print_int_array(arr,10);
    fptr_arr_change(arr,10);
    cout << "After:\n";
    fptr_print_int_array(arr,10);

    fptr_arr_change=pvt::arr_change2;
    fptr_arr_change(arr,10);
    cout << "Another inversion(2):\n";
    fptr_print_int_array(arr,10);

    fptr_arr_change=pvt::arr_change3;
    fptr_arr_change(arr,10);
    cout << "Another inversion (3):\n";
    fptr_print_int_array(arr,10);

    fptr_arr_fill(arr2,8);
    cout << "Required values:\n1 4 7 10 13 16 19 22\n";
    cout << "Filled values:\n";
    fptr_print_int_array(arr2,8);

    cout << "Требуемое: checkBalance([1, 1, 1, || 2, 1]) → true\n";
    printf("Мой код на этих данных даёт: %s\n",fptr_checkBalance(arr3,5)?"true":"false");
    cout << "Требуемое: checkBalance ([2, 1, 1, 2, 1]) → false\n";
    printf("Мой код на этих данных даёт: %s\n",fptr_checkBalance(arr4,5)?"true":"false");
    cout << "Требуемое: checkBalance ([10, || 1, 2, 3, 4]) → true \n";
    printf("Мой код на этих данных даёт: %s\n",fptr_checkBalance(arr5,5)?"true":"false");

    fptr_print_int_array(test_array,5);
    cout << "fptr_array_shift(test_array,5,-2);" << endl;
    fptr_array_shift(test_array,5,-2);
    fptr_print_int_array(test_array,5);

    cout << "print_inversion(3,1,0,1);" << endl;
    print_inversion(3,1,0,1);
    cout <<"Вариант с предыдущего дз уже с двумя диагоналями:\n";
    int hw4[6][6]={0};
    int matrix_size=6;
    // к тому моменту как написал этот вариант вы показали как это сократить в один цикл,
    // так что просто оставил тут вариант на двух циклах - не перебивать же с вебинара %)
    for(int i=0;i<matrix_size;i++)
        for(int j=0;j<matrix_size;j++) {
	    if (i==j){
	        hw4[i][j]=1;
	        continue;
	    }
	    if (j == matrix_size-(i+1))
	        hw4[i][j]=1;
	}
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++)
            printf("%d ", hw4[i][j]);
        printf("\n");
    }
}
