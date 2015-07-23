/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not. Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.
 
 Note Suppose a, b, and c are three different people, then (a,b) and (b,c) are counted as two different teams.
 
 Input Format
 
 The first line contains two integers, N and M, separated by a single space, where N represents the number of people, and M represents the number of topics. N lines follow.
 Each line contains a binary string of length M. If the ith line's jth character is 1, then the ith person knows the jth topic; otherwise, he doesn't know the topic.
 
 Constraints
 2≤N≤500
 1≤M≤500
 
 Output Format
 
 On the first line, print the maximum number of topics a 2-person team can know.
 On the second line, print the number of 2-person teams that can know the maximum number of topics.
 
 Sample Input
 
 4 5
 10101
 11100
 11010
 00101
 Sample Output
 
 5
 2
 
 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/acm-icpc-team
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int getMaxTopics(string person1,string person2,int m)
{
    int ans[m],sum=0;
    for(int i=0;i<m;i++)
    {
        ans[i]=((person1[i]-'0')^(person2[i]-'0'))+((person1[i]-'0')&(person2[i]-'0'));
        sum+=ans[i];
    }
    return sum;
}

int main() {
    int m,n;
    cin>>n>>m;
    string per[n];
    for(int i=0;i<n;i++)
        cin>>per[i];
    int cur_max_top,max_max_top=0,no_max_top=0;
    for(int i = 0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            cur_max_top = getMaxTopics(per[i],per[j],m);
            if(cur_max_top > max_max_top)
            {
                max_max_top = cur_max_top;
                no_max_top = 0;
            }
            if(cur_max_top == max_max_top)
                no_max_top++;
        }
    cout<<max_max_top<<'\n'<<no_max_top;
    return 0;
}