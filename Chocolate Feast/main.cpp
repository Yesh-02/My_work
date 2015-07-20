/*
 Author : Yeshwanth D S
 Problem Statement
 
 Little Bob loves chocolate, and he goes to a store with $N in his pocket. The price of each chocolate is $C. The store offers a discount: for every M wrappers he gives to the store, he gets one chocolate for free. How many chocolates does Bob get to eat?
 
 Input Format:
 The first line contains the number of test cases, T.
 T lines follow, each of which contains three integers, N, C, and M.
 
 Output Format:
 Print the total number of chocolates Bob eats.
 
 Constraints:
 1≤T≤1000
 2≤N≤105
 1≤C≤N
 2≤M≤N
 
 Sample input
 
 3
 10 2 5
 12 4 4
 6 2 2
 Sample Output
 
 6
 3
 5
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/chocolate-feast
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        // Computer answer
        answer = floor(n/c);
        int choc_covers = answer;
        while(choc_covers>=m)
        {
            int extra_choc = floor(choc_covers/m);
            int remainder = choc_covers%m;
            answer+=extra_choc;
            choc_covers = extra_choc + remainder;
        }
        cout<<answer<<endl;
    }
    return 0;
}