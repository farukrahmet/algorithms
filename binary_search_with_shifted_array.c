//
//  Created by Faruk Rahmet on 16/10/16.
//  Copyright © 2016 Faruk Rahmet. All rights reserved.
//

// All algorithmic complex must be O(log(n)) !!


#include <stdio.h>

int min(int *array, int a, int b) {
    if(array[a] > array[b])
        return b;
    return a;
}

// Find shifted array's head
int findHead(int *array, int n, int head, int last) {
    if(head >= last)
        return head;
    else {
        return min(array, findHead(array, n, head, (head + last)/2), findHead(array, n, (head + last)/2 + 1, last));
    }
}

int binarySearch(int *array, int n, int wanted, int head) {
    int last;
    int k = head;
    if(head == 0)
        last = n - 1;
    else
        last = head - 1;
    
    int mid = ((head - k + n) % n + (last - k + n) % n + k) % n;
    int head_mirror = (head - k + n) % n;
    int last_mirror = (last - k + n) % n;
    
    while( head_mirror < last_mirror && array[mid] != wanted) {
        if(wanted < array[mid])
            last = (mid - 1 + n) % n;
        else
            head = (mid + 1) % n;
        head_mirror = (head - k + n) % n;
        last_mirror = (last - k + n) % n;
        mid = (head_mirror + last_mirror + k) % n;
    }
    
    if(array[mid] == wanted)
        return mid;
    
    return -1;
}

int test_binary_search_with_shifted_array(int *array, int n, int wanted) {
    int head = head = findHead(array, n, 0, n-1);
    return binarySearch(array, n, wanted, head);
}
int main(int argc, const char * argv[]) {
    int n = 6;
    int array[6] = {27, 29, 35, 42, 5, 15};
    printf("Test minimum element find :");
    if(test_binary_search_with_shifted_array(array, n, 5) == 4)
        printf("OK");
    else
        printf("WRONG");
    printf("\n");
    printf("Test maximum element find :");
    if(test_binary_search_with_shifted_array(array, n, 42) == 3)
        printf("OK");
    else
        printf("WRONG");
    printf("\n");
    printf("Test common element find :");
    if(test_binary_search_with_shifted_array(array, n, 29) == 1)
        printf("OK");
    else
        printf("WRONG");
    printf("\n");
    printf("Test unknown element find :");
    if(test_binary_search_with_shifted_array(array, n, 33) == -1)
        printf("OK");
    else
        printf("WRONG");
    printf("\n");
    return 0;
}
