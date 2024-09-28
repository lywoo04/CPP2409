#include <stdio.h>
#include <stdlib.h>
//234106 임연우

void merge(int A[], int l, int m, int h)    {
    int i = l;
    int j = m+1;

    int k = 0;
    int B[h - l + 1];

    while (i <= m && j <= h)    {
        if (A[i] <= A[j])   {
            B[k++] = A[i++];   
        }
        else    {
            B[k++] = A[j++];    
        }

    }

    while (i <= m) {
        B[k++] = A[i++];
    }
    while (j <= h) {
        B[k++] = A[j++];
    }


    for (i = l, k = 0; i <= h; i++, k++)    {
        A[i] = B[k];
    }

}

void MS(int A[], int l, int h)   {
    if (l < h)  {
        int m = (l + h)/2;

        MS(A, l, m);
        MS(A, m+1, h);

        merge(A, l, m ,h);
    }


}

int main()  {
    int A[] = {3,2,5,7,4,8,6,9,1};
    int A_size = sizeof(A) / sizeof(int);

    MS(A, 0, A_size-1);

    for ( int o = 0; o < A_size; o++)   {
        printf("%d", A[o]);
        if (o != A_size-1)    {
            printf(", ");
        }
    }
}
