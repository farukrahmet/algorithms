//
//  main.c
//  algoritma_analizi_odev1
//
//  Created by Faruk Rahmet on 20/10/15.
//  Copyright (c) 2015 Faruk Rahmet. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 Verilen bir arrayde parametre gelen indislerdeki degerlerin yerini degistiren fonksiyon
 */
void swap(int *array, int i, int j)
{
    int tmp; //degisken atamasi yapmak icin tanimlanan degisken
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/*
 quicksort fonksiyonunun icinde gerekli sart saglandikca diziyi hangi indise gore bolecegimize karar veren fonksiyondur.
 Dizinin her zaman ilk elemanini pivot olarak secer.
 Parametreler:
 int *a = sort edilmek istenen dizi;
 int low = parametre gelen dizideki bolunmus bir parcanin en sol indisi;
 int high = parametre gelen dizideki bolunmus bir parcanin en sol indisi;
 */
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

void quicksort(int *array,int low,int high)
{
    if(high > low){
        int p = partition(array, low, high);
        quicksort(array,low,p-1);
        quicksort(array,p+1,high);
    }
}
/*
 Diziye okuma yapilan fonksiyon
 */
void read_array(int *array, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d.nci eleman : ", i);
        scanf("%d", &array[i]);
    }
}

/*
 Diziyi ekrana yazdirmamizi saglayan fonksiyon.
 */
void print_array(int *array, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
}

int main(int argc, const char * argv[]) {
    int *array;
    int n;
    int i;
    printf("Dizinin uzunlugunu giriniz : ");
    scanf("%d", &n);
    array = (int *) malloc(n * sizeof(int));
    
    //    read_array(array, n);
    int rnd;
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        rnd = rand() % (n);
        array[i] = rnd;
    }
    
    clock_t begin, end;
    double time_spent;
    
    begin = clock();
    quicksort(array, 0, n-1);
    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f s for normal quick sort\n", time_spent);
    
    //    print_array(array, n);
    for(i=n-100;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    
    free(array);
    
    return 0;
}
