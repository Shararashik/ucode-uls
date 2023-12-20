#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) {
        return -1;
    }
    int swaps = 0;
    int count = 0;
    int r2 = right;
    int l2 = left;
    int pivot_length = mx_strlen(arr[(l2 + r2) / 2]);
    while (l2 <= r2) {
        while (mx_strlen(arr[l2]) < pivot_length) {
            l2++;
        }
        while (mx_strlen(arr[r2]) > pivot_length) {
            r2--;
        }
        if (l2 <= r2) {
            if (mx_strlen(arr[r2]) != mx_strlen(arr[l2])) {
                char *temp = arr[l2];
                arr[l2] = arr[r2];
                arr[r2] = temp;
            }            
            count++;
            l2++;
            r2--;
        }
    }    
    if (left < right) {
        swaps += (l2 - left - 1);
        swaps += (right - l2 - 1);
        swaps += mx_quicksort(arr, left, l2 -1);
        swaps += mx_quicksort(arr, l2, right);
    }
    return count;
}



