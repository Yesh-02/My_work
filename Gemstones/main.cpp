/*
 Author : Yeshwanth D S
 Problem Statement
 
 John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lower-case Latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a gem-element if it occurs at least once in each of the rocks.
 
 Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.
 
 Input Format
 
 The first line consists of an integer, N, the number of rocks.
 Each of the next N lines contains a rock's composition. Each composition consists of lower-case letters of English alphabet.
 
 Constraints
 1≤N≤100
 Each composition consists of only lower-case Latin letters ('a'-'z').
 1≤ length of each composition ≤100
 Output Format
 
 Print the number of gem-elements that are common in these rocks. If there are none, print 0.
 
 Sample Input
 
 3
 abcdde
 baccd
 eeabg
 Sample Output
 
 2

 Source : hackerrank.com
 
 Problem link : https://www.hackerrank.com/challenges/gem-stones
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void printSum(int count[],int num)
{
    int i = 0,sum=0;
    while(i<26)
    {
        if(count[i]==num)
            sum++;
        i++;
    }
    cout<<sum;
}
void findNum(string str,int n,int num,int count[26])
{
    
    int i=0,limit[26]={0};
    while(i<str.length())
    {
        if(count[str[i]%97]<n  && limit[str[i]%97] == 0)
        {
            count[str[i]%97]++;
            limit[str[i]%97]++;
        }
        i++;
    }
    if(n == num) printSum(count,num);
}
int main() {
    int n,i=1,num,count[26]={0};
    string str;
    cin>>n;
    num = n;
    while(i<=n)
    {
        cin>>str;
        findNum(str,i,num,count);
        i++;
    }
    return 0;
}