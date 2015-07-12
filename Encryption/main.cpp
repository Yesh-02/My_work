/*
 Author : Yeshwanth D S
 
 Problem Statement
 
 An English text needs to be encrypted using the following encryption scheme.
 First, the spaces are removed from the text. Let L be the length of this text.
 Then, characters are written into a grid, whose rows and columns have the following constraints:
 
 ⌊L‾‾√⌋≤rows≤column≤⌈L‾‾√⌉, where ⌊x⌋ is floor function and ⌈x⌉ is ceil function
 For example, the sentence if man was meant to stay on the ground god would have given us roots after removing spaces is 54 characters long, so it is written in the form of a grid with 7 rows and 8 columns.
 
 ifmanwas
 meanttos
 tayonthe
 groundgo
 dwouldha
 vegivenu
 sroots
 Ensure that rows×columns≥L
 If multiple grids satisfy the above conditions, choose the one with the minimum area, i.e. rows×columns.
 The encoded message is obtained by displaying the characters in a column, inserting a space, and then displaying the next column and inserting a space, and so on. For example, the encoded message for the above rectangle is:
 
 imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau
 
 You will be given a message in English with no spaces between the words. The maximum message length can be 81 characters. Print the encoded message.
 
 Here are some more examples:
 
 Sample Input:
 
 haveaniceday
 Sample Output:
 
 hae and via ecy
 Sample Input:
 
 feedthedog
 Sample Output:
 
 fto ehg ee dd
 Sample Input:
 
 chillout
 Sample Output:
 
 clu hlt io
 
 Source : hackerrank.com
 
 Problem Link : https://www.hackerrank.com/challenges/encryption
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string str;
    cin>>str;
    int i=1,j=1,mini=0,minj=0,size=str.length(),min=82,c=ceil(sqrt(size)),k=0;
    for(i=1;i<=c;i++)
        for(j=i;j<=c;j++)
        {
            if(i*j>=size)
            {
                if(min>size)
                {
                    min=size;
                    mini = i;
                    minj = j;
                }
            }
        }
    cout<<mini<<' '<<minj<<endl;
    char matrix[mini][minj];
    for(i = 0;i<mini;i++)
    {
        for(j=0;j<minj;j++)
        {
            matrix[i][j]='0';
        }
        cout<<' ';
    }
    for(i = 0;i<mini;i++)
        for(j=0;j<minj;j++)
        {
            if(k<size)
            {
                matrix[i][j]=str[k];
                k++;
            }
            else
                break;
        }
    for(i = 0;i<mini;i++)
    {
        for(j=0;j<minj;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<' ';
    }
    cout<<endl;
    for(j = 0;j<minj;j++)
    {
        for(i=0;i<mini;i++)
        {
            if(matrix[i][j] != '0')
            cout<<matrix[i][j];
        }
        cout<<' ';
    }
    return 0;
}

