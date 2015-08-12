/*
 Author : Yeshwanth D S
 Problem Statement
 
 Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations.
 
 If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
 If N is a power of 2, reduce the counter by half of N.
 The resultant value is the new N which is again used for subsequent operations.
 The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins.
 
 Given N, your task is to find the winner of the game.
 
 Update If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.
 
 Input Format
 The first line contains an integer T, the number of testcases.
 T lines follow. Each line contains N, the initial number set in the counter.
 
 Constraints
 
 1 ≤ T ≤ 10
 1 ≤ N ≤ 264 - 1
 
 Note: Range of N is larger than long long int, consider using unsigned long long int.
 
 Output Format
 
 For each test case, print the winner's name in a new line. So if Louise wins the game, print "Louise". Otherwise, print "Richard". (Quotes are for clarity)
 
 Sample Input
 
 1
 6
 Sample Output
 
 Richard
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/counter-game
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long int getClosest(unsigned long long int Counter)
{
    unsigned long long int num=1;
    if(Counter > ((1LL<<63)))
        return ((1LL<<63));
    while(num*2 < Counter)
        num*=2;
    return num;
}
int findWinner(unsigned long long int Counter , int winner){
    unsigned long long int i = getClosest(Counter);
    if(i == Counter)
        Counter /= 2;
    else
        Counter -= i;
    if(Counter == 1)
        return winner;
    winner++;
    return findWinner(Counter, winner%2);
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int winner;
        unsigned long long int N;
        cin>>N;
        if(N == 1)
            cout<<"Richard"<<endl;
        else {
            winner = findWinner(N,0);
            if(winner == 1)
                cout<<"Richard"<<endl;
            else if(winner == 0)
                cout<<"Louise"<<endl;
        }
    }
    return 0;
}