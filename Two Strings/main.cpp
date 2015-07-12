/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given two strings, A and B. Find if there is a substring that appears in both A and B.
 
 Input Format
 
 Several test cases will be given to you in a single file. The first line of the input will contain a single integer T, the number of test cases.
 
 Then there will be T descriptions of the test cases. Each description contains two lines. The first line contains the string A and the second line contains the string B.
 
 Output Format
 
 For each test case, display YES (in a newline), if there is a common substring. Otherwise, display NO.
 
 Constraints
 
 All the strings contain only lowercase Latin letters.
 1<=T<=10
 1<=|A|,|B|<=105
 Sample Input
 
 2
 hello
 world
 hi
 world
 Sample Output
 
 YES
 NO

 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/two-strings
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string findCommon(string str1,string str2)
{
    int count[26]={0};
    for(int i=0;i<str1.length();i++)
        if(count[str1[i]%97] == 0)count[str1[i]%97]++;
    for(int i=0;i<str2.length();i++)
        count[str2[i]%97]=-(count[str2[i]%97]);
    for(int i=0;i<26;i++)
        if(count[i] < 0)
            return "YES";
    return "NO";
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout<<findCommon(str1,str2)<<endl;
    }
    return 0;
}