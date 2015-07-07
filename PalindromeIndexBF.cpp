/* 
 Program : Palindrome Index (Hackerrank.com)
 Author : Yeshwanth D S
 Description : Find the index to be removed, so that the string becomes a palindrome..
 problem statement link : https://www.hackerrank.com/challenges/palindrome-index
 Poor complexity.. will not solve all the test cases..
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int isPalindrome(string str, int skip)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(i == skip)
            i+=1;
        else if(j==skip)
            j-=1;
        if(str[i]!=str[j])
            return -1;
        i++;
        j--;
    }
    return 1;
}

int main() {
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        if(isPalindrome(str,-1) == 1)
            cout<<"-1"<<endl;
        else
        {
            for(int i = 0; i< str.length();i++)
            {
                if(isPalindrome(str,i)==1)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}