/*
 Author : Yeshwanth D S
 Problem Statement
 
 In this challenge you need to print the data that accompanies each integer in a list. In addition, if two strings have the same integers, you need to print the strings in their original order. Hence, your sorting algorithm should be stable, i.e. the original order should be maintained for equal elements.
 
 Insertion Sort and the simple version of Quicksort were stable, but the faster in-place version of Quicksort was not (since it scrambled around elements while sorting).
 
 In cases where you care about the original order, it is important to use a stable sorting algorithm. In this challenge, you will use counting sort to sort a list while keeping the order of the strings (with the accompanying integer) preserved.
 
 Challenge
 In the previous challenge, you created a "helper array" that contains information about the starting position of each element in a sorted array. Can you use this array to help you create a sorted array of the original list?
 
 Hint: You can go through the original array to access the strings. You can then use your helper array to help determine where to place those strings in the sorted array. Be careful about being one off.
 
 Details and a Twist
 You will be given a list that contains both integers and strings. Can you print the strings in order of their accompanying integers? If the integers for two strings are equal, ensure that they are print in the order they appeared in the original list.
 
 The Twist - Your clients just called with an update. They don't want you to print the first half of the original array. Instead, they want you to print a dash for any element from the first half. So you can modify your counting sort algorithm to sort the second half of the array only.
 
 Input Format
 - n, the size of the list ar.
 - n lines follow, each containing an integer x and a string s.
 
 Output Format
 Print the strings in their correct order.
 
 Constraints
 1≤n≤1000000
 n is even
 1≤ length(s) ≤10
 0≤x<100,x∈ar
 The characters in every string in lowercase.
 
 Sample Input
 
 20
 0 ab
 6 cd
 0 ef
 6 gh
 4 ij
 0 ab
 6 cd
 0 ef
 6 gh
 0 ij
 4 that
 3 be
 0 to
 1 be
 5 question
 1 or
 2 not
 4 is
 2 to
 4 the
 
 Sample Output
 
 - - - - - to be or not to be - that is the question - - - -
 
 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/countingsort4
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    long N;
    cin>>N;
    map <int ,vector <string> > list;
    for(long i = 1; i<=N ; i++)
    {
        int x;
        string s;
        cin>>x>>s;
        if(i <= N/2)
            list[x].push_back("-");
        else
            list[x].push_back(s);
    }
    map< int,vector<string> > :: iterator it;
    for (it=list.begin(); it!=list.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
    }
    return 0;
}