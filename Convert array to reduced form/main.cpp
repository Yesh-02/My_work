/*
 Author : Yeshwanth D.S
 
 Problem Description: 
 
 Given an array with n distinct elements, convert the given array to a form where all elements are in range from 0 to n-1. The order of elements is same, i.e., 0 is placed in place of smallest element, 1 is placed for second smallest element, … n-1 is placed for largest element.
 
 Input:  arr[] = {10, 40, 20}
 Output: arr[] = {0, 2, 1}
 
 Input:  arr[] = {5, 10, 40, 30, 20}
 Output: arr[] = {0, 1, 4, 3, 2}
 
 Expected time complexity is O(n Log n).
 
 Problem Source : http://www.geeksforgeeks.org/
 
 Problem link : http://www.geeksforgeeks.org/convert-array-reduced-form/
 */
 

#include<iostream>
#include<map>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void minimizeArray(int arr[], int size)
{
    int temp[size];
    
    for(int i = 0; i < size; i++)
        temp[i] = arr[i];
    
    sort(temp, temp + size);
    
    map<int ,int > mp;
    
    for(int i = 0; i < size; i++)
        mp[temp[i]] = i;
    
    for(int i = 0; i < size; i++)
        arr[i] = mp[arr[i]];
}

int main()
{
    int arr[] = {1, 2, 30, 4, 50, 6};
    printArray(arr, sizeof(arr)/ sizeof(arr[0]));
    minimizeArray(arr, sizeof(arr)/ sizeof(arr[0]));
    printArray(arr, sizeof(arr)/ sizeof(arr[0]));
    return 0;
}