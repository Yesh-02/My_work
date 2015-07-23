/*
 Author : Yeshwanth D S
 Problem Statement
 
 Given a word w, rearrange the letters of w to construct another word s in such a way that s is lexicographically greater than w. In case of multiple possible answers, find the lexicographically smallest one.
 
 Input Format
 
 The first line of input contains t, the number of test cases. Each of the next t lines contains w.
 
 Constraints
 1≤t≤105
 1≤|w|≤100
 w will contain only lower-case English letters and its length will not exceed 100.
 
 Output Format
 
 For each testcase, output a string lexicographically bigger than w in a separate line. In case of multiple possible answers, print the lexicographically smallest one, and if no answer exists, print no answer.
 
 Sample Input
 
 5
 ab
 bb
 hefg
 dhck
 dkhc
 Sample Output
 
 ba
 no answer
 hegf
 dhkc
 hcdk
 
 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/bigger-is-greater
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    string str,ans;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        int n = str.length();
        int j, k;
        for (j = n - 2; j >= 0; j--)
        {
            for (k = n - 1; k > j && str[k] <= str[j]; k--)
                ;
            if (k == j)
                continue;
            char tmp = str[k];
            str[k] = str[j];
            str[j] = tmp;
            sort(str.begin() + j + 1, str.end());
            break;
        }
        if (j < 0)
            cout << "no answer" << endl;
        else
            cout << str << endl;
    }
    return 0;
}
