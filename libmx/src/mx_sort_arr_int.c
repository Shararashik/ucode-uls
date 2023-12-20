#include "../inc/libmx.h"

void mx_sort_arr_int(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[i]) {
                int min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
        }
    }
}



