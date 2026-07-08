//
// Created by gauss on 06/07/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

//-------------- Brute Force

int cut_rod(int p[], int n)
{
    if (n == 0) return 0;
	int q = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        q = max(q, p[i] + cut_rod(p, n - i));
    }
    return q;
}

//-------------- Dynamic Progaming

int memoized_cut_rod(int p[], int n);
int memoized_cut_rod_aux(int p[], int n, int r[]);
int bottom_up_cut_rod(int p[], int n);

 int memoized_cut_rod(int p[], int n)
{
    int r[n + 1];
     r[0] = 0;
    for (int i = 1; i <= n; i++) { r[i] = INT_MIN; }
    return memoized_cut_rod_aux(p, n, r);
}

int memoized_cut_rod_aux(int p[], int n, int r[])
{
     if (r[n] >= 0) return r[n];
     int q;
     if (n == 0){ q = 0; }
     else
     {
         q = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
        }
         r[n] = q;
     }
     return q;
}

int bottom_up_cut_rod(int p[], int n)
 {
     int r[n + 1];
     r[0] = 0;
     for (int j = 1; j <= n; j++)
     {
         int q = INT_MIN;
         for (int i = 1; i <= j; i++)
         {
             q = max(q, p[i] + r[j - i]);
         }
         r[j] = q;
     }
     return r[n];
 }

int main()
{
     int n;
     scanf("%d", &n);
     int p[n + 1];
     p[0] = 0;
     for (int i = 1; i <= n; i++)
     {
         scanf("%d", &p[i]);
     }
     int r = memoized_cut_rod(p, n);
     //int r = bottom_up_cut_rod(p, n);

     printf("Best: %d\n", r);
     return 0;
}