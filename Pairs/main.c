/*
 Author : Yeshwanth D S
 Problem Statement
 
 Given N integers, count the number of pairs of integers whose difference is K.
 
 Input Format
 The first line contains N and K.
 The second line contains N numbers of the set. All the N numbers are unique.
 
 Output Format
 An integer that tells the number of pairs of integers whose difference is K.
 
 Constraints:
 N≤105
 0<K<109
 Each integer will be greater than 0 and at least K smaller than 231−1.
 
 Sample Input #00:
 
 5 2
 1 5 3 4 2
 Sample Output #00:
 
 3
 Sample Input #01:
 
 10 1
 363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793
 Sample Output #01:
 
 0
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/pairs
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */
void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
        
    }
    
}
int pairs(int a_size, int* a, int k) {
    
    int ans;
    
    /* Write your code here */
    quicksort(a,0,a_size-1);
    /*for(int i=0;i<a_size;i++)
     printf("%d ",a[i]);*/
    int i=0,j=1;ans = 0;
    while(j<a_size )
    {
        if((a[j]-a[i])==k)
        {
            ans++;
            j++;
        }
        else if((a[j]-a[i])<k)
            j++;
        else
            i++;
    }
    
    return ans;
}

/* Tail starts here (Provided already..)*/
int main() {
    int res;
    
    int _a_size,_a_i,_k;
    scanf("%d %d", &_a_size,&_k);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) {
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    res=pairs(_a_size,_a,_k);
    printf("%d\n",res);
    return 0;
}