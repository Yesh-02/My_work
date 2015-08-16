/*
Author : Yeshwanth D S
 Problem Statement
 
 The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm. Insertion Sort has a running time of O(N2) which isn't fast enough for most purposes. Instead, sorting in the real world is done with faster algorithms like Quicksort, which will be covered in the challenges that follow.
 
 The first step of Quicksort is to partition an array into two smaller arrays.
 
 Challenge
 You're given an array ar and a number p. Partition the array, so that all elements greater than p are to its right, and all elements smaller than p are to its left. p is called the pivot of the partition.
 
 Guideline - In this challenge, you do not need to move around the numbers 'in-place'. This means you can create two lists and combine them at the end.
 
 Input Format
 You will be given an array of integers. The number p is the first element in ar.
 
 There are two lines of input:
 
 n - the number of elements in the array ar
 the n elements of ar (including p at the beginning)
 Output Format
 Print out the numbers of the partitioned array on one line.
 
 Constraints
 
 1≤n≤1000
 −1000≤x≤1000,x∈ar
 All elements will be unique.
 Multiple answer can exists for the given test case. Print any one of them.
 Sample Input
 
 5
 4 5 3 7 2
 Sample Output
 
 3 2 4 5 7

 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/quicksort1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//-------------------->>last element as pivot<<------------------------//
int _partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
//-------------------->>first element as pivot<<------------------------//
int _partition_first (int arr[], int l, int h)
{
    int x = arr[l];
    int i = (l - 1);
    
    for (int j = l; j <= h; j++)
    {
        if (arr[j] < x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    return (i + 1);
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = _partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
void printArr(int max,int arr[])
{
    for(int i=0;i<max;i++)
        printf("%d ",arr[i]);
}
void partition(int ar_size, int *  ar) {
    quickSort(ar,0,ar_size-1);
    printArr(ar_size,ar);
}
int main(void) {
    
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    
    partition(_ar_size, _ar);
    
    return 0;
}
