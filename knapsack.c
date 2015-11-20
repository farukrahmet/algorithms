//
//  main.c
//  knapsnack problem
//
//  Created by Faruk Rahmet on 12/11/15.
//  Copyright (c) 2015 Faruk Rahmet. All rights reserved.
//

#include <stdio.h>

int maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void print_mtr(int n, int m, int mtr[n][m])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
    
}

int knapsack(int *value, int *weight, int is, int max_w)
{
    int mtr[is][max_w+1];
    int i,j;
    
    for(i=0;i<is+1;i++)
        mtr[i][0] = 0;
    for(j=0;j<max_w;j++)
        mtr[0][j] = 0;
    
    for(i=1; i<is+1;i++)
    {
        for(j=1; j<max_w+1; j++)
        {
            if(weight[i-1]<=j && value[i-1] + mtr[i-1][j-weight[i-1]] > mtr[i-1][j])
            {
                mtr[i][j] = value[i-1] + mtr[i-1][j-weight[i-1]];
            }
            else
            {
                mtr[i][j] = mtr[i-1][j];
            }
            
        }
    }
    
//    print_mtr(is+1, max_w+1, mtr);
    return mtr[is][max_w];
}

int main(int argc, const char * argv[]) {
    
    int is, i;
    int max_w;
    
    printf("Kac item var :\n");
    scanf("%d", &is);
    
    printf("Max weight :\n");
    scanf("%d", &max_w);
    
    int value[is], weight[is];
    for(i=0;i<is;i++)
    {
        printf("%d. itemin value : \n", i+1);
        scanf("%d", &value[i]);
        printf("%d. itemin weight : \n", i+1);
        scanf("%d", &weight[i]);
    }
    int sonuc = knapsack(value, weight, is, max_w);
    printf("Sonuc : %d", sonuc);
    
    return 0;
}
