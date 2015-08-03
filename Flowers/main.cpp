/*
 Author : Yeshwanth D S
 Problem Statement
 
 You and your K-1 friends want to buy N flowers. Flower number i has cost ci. Unfortunately the seller does not want just one customer to buy a lot of flowers, so he tries to change the price of flowers for customers who have already bought some flowers. More precisely, if a customer has already bought x flowers, he should pay (x+1)*ci dollars to buy flower number i.
 You and your K-1 friends want to buy all N flowers in such a way that you spend the least amount of money. You can buy the flowers in any order.
 
 Input:
 
 The first line of input contains two integers N and K (K <= N). The next line contains N space separated positive integers c1,c2,...,cN.
 
 Output:
 
 Print the minimum amount of money you (and your friends) have to pay in order to buy all N flowers.
 
 Constraints
 
 1≤N,K≤100
 Any ci is not more than 106
 Result is guaranteed to be less than 231
 
 Sample input #00
 
 3 3
 2 5 6
 Sample output #00
 
 13
 Sample input #01
 
 3 2
 2 5 6
 Sample output #01
 
 15
 
 Source : Hackerrank.com
 
 Problem Link : https://www.hackerrank.com/challenges/flowers
 */

/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
using namespace std;
long long getSum(long long sum[],int max)
{
    long long ret=0;
    for(int i=0; i < max;i++)
        ret+=sum[i];
    return ret;
}
int main(void){
    
    
    //Helpers for input and output
    
    int N, K;
    cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    sort(C, C+N, greater<int>());
    long long sum[K]={0},j=0;
    int count[N]={0};
    for(int i=0;i<N;i++)
    {
        sum[j]+=C[i]*(count[j]+1);
        count[j]++;
        j++;
        j%=K;
    }
    long long result = getSum(sum,K);
    
    cout << result << "\n";
    
    return 0;
}
