/*
 Author : Yeshwanth D S
 Problem Statement
 
 Julius Caesar protected his confidential information from his enemies by encrypting it. Caesar rotated every letter in the string by a fixed number K. This made the string unreadable by the enemy. You are given a string S and the number K. Encrypt the string and print the encrypted string.
 
 For example:
 If the string is middle-Outz and K=2, the encoded string is okffng-Qwvb. Note that only the letters are encrypted while symbols like - are untouched.
 'm' becomes 'o' when letters are rotated twice,
 'i' becomes 'k',
 '-' remains the same because only letters are encoded,
 'z' becomes 'b' when rotated twice.
 
 Input Format
 
 Input consists of an integer N equal to the length of the string, followed by the string S and an integer K.
 
 Constraints
 1≤N≤100
 0≤K≤100
 S is a valid ASCII string and doesn't contain any spaces.
 
 Output Format
 
 For each test case, print the encoded string.
 
 Sample Input
 
 11
 middle-Outz
 2
 Sample Output
 
 okffng-Qwvb
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/caesar-cipher-1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    int n,k,temp;
    scanf("%d",&n);
    char ch,str[n];
    scanf("%s",str);
    scanf("%d",&k);
    k%=26;
    for(int i=0;i<n;i++)
    {
        if(isalpha(str[i]))
        {
            temp=str[i]+k;
            if(str[i]<=90)
            {
                if(temp>90)
                    temp='A'+(temp%90)-1;
            }
            else
            {
                if(temp>122)
                    temp='a'+(temp%122)-1;
            }
            str[i]=temp;
        }
    }
    printf("%s",str);
    return 0;
}