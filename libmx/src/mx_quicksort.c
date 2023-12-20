#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int max_left = left;
    int max_right = right;
    char *swap_var;
    if(!arr) {
        return -1;
    }
    int s_operations = 0;
    int mid = (left + right) / 2;
    while((right - left) > 0) {
        while(mx_strlen(arr[mid]) > mx_strlen(arr[left])) left++;
        while(mx_strlen(arr[right]) > mx_strlen(arr[mid])) right--;
        if(mx_strlen(arr[left]) != mx_strlen(arr[right])) {
            swap_var = arr[left];
            arr[left] = arr[right];
            arr[right] = swap_var;
            s_operations++;
        }            
        left++;
        right--;
    }
    if(max_right > max_left) {
        s_operations += mx_quicksort(arr, max_left, right);
        s_operations += mx_quicksort(arr, left, max_right);
    }
    return s_operations;
}
