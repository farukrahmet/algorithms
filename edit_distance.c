//
//  main.c
//  edit_distance
//
//  Created by Faruk Rahmet on 12/11/15.
//  Copyright (c) 2015 Faruk Rahmet. All rights reserved.
//

#include <stdio.h>

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

int min(int a, int b, int c)
{
    if(a<=b && a<=c)
        return a;
    
    if(b<=a && b<=c)
        return b;
    
    else
        return c;
}

int edit_distance(char *kelime1, char *kelime2, int n, int m)
{
    int mtr[n][m];
    int i,j;
    
    for(i=0;i<n;i++)
    {
        mtr[i][0] = i;
    }
    
    for(j=0;j<m;j++)
    {
        mtr[0][j] = j;
    }
    
//    print_mtr(n,m, mtr);
    
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(kelime1[i-1] == kelime2[j-1])
            {
                mtr[i][j] = mtr[i-1][j-1];
            }
            else
            {
                mtr[i][j] = min(
                                mtr[i-1][j-1]+1,
                                mtr[i][j-1]+1,
                                mtr[i-1][j]+1);
            }
        }
    }
    
//    print_mtr(n,m, mtr);
    
    return mtr[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    int k1_len, k2_len;
    printf("Word1 length: \n");
    scanf("%d", &k1_len);
    printf("Word2 length: \n");
    scanf("%d", &k2_len);
    
    char kelime1[k1_len];
    char kelime2[k2_len];
    
    printf("Word1 : \n");
    scanf("%s", kelime1);
    
    printf("Word2 : \n");
    scanf("%s", kelime2);
    
    int sonuc = edit_distance(kelime1, kelime2, k1_len, k2_len);
    printf("Sonuc : %d\n", sonuc);
    
//    printf("%s-%s", kelime1, kelime2);
    return 0;
}
