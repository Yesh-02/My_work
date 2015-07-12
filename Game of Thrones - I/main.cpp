/*
Author : Yeshwanth D S
 Problem Statement
 
 Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.
 
 door
 
 But, to lock the door he needs a key that is an anagram of a certain palindrome string.
 
 The king has a string composed of lowercase English letters. Help him figure out whether any anagram of the string can be a palindrome or not.
 
 Input Format
 A single line which contains the input string.
 
 Constraints
 1≤ length of string ≤105
 Each character of the string is a lowercase English letter.
 
 Output Format
 A single line which contains YES or NO in uppercase.
 
 Sample Input : 01
 
 aaabbbb
 Sample Output : 01
 
 YES

 Source : hackerrank.com
 Problem link : https://www.hackerrank.com/challenges/game-of-thrones
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int isPal(string s)
{
    int count[26]={0},odd=0;
    for(int i=0;i<s.length();i++)
        count[s[i]%97]++;
    for(int i=0;i<26;i++)
        if(count[i]%2 !=0)
            odd++;
    if(odd == 1||odd == 0)
        return 1;
    else
        return 0;
}

int main() {
    
    string s;
    cin>>s;
    
    int flag = 0;
    flag=isPal(s);
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}