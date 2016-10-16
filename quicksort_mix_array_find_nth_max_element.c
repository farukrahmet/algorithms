//  Created by Faruk Rahmet on 16/10/16.
//  Copyright © 2016 Faruk Rahmet. All rights reserved.
//

#include <stdio.h>

void swap(int *array, int i, int j)
{
    int tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(int *a, int low, int high)
{
    int left, right;
    int pivot_item;
    left = low;
    pivot_item = a[low];
    right = high;
    while(left < right)
    {
        while(a[left] <= pivot_item  && left<right)left++;
        while(a[right] > pivot_item)right--;
        if(left < right)swap(a,left,right);
    }
    a[low] = a[right];
    a[right] = pivot_item;
    return right;
}

int quicksort_find_nth_max_element(int *array, int size, int head, int last, int k) {
    if(last >= head) {
        int p = partition(array, head, last);
        if(p == size - k)
            return p;
        else if(size - k < p)
            return quicksort_find_nth_max_element(array, size, head, p-1, k);
        else
            return quicksort_find_nth_max_element(array, size, p+1, last, k);
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int size = 6;
    int array[6] = {22, 11, 9, 35, 5, 15};
    
    printf("%d\n", array[quicksort_find_nth_max_element(array, size, 0, size-1, 0)]);
    
    return 0;
}
