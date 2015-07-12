/*
 Author : Yeshwanth D S
 Problem Statement:
 
 Sherlock Holmes is getting paranoid about Professor Moriarty, his arch-enemy. All his efforts to subdue Moriarty have been in vain. These days Sherlock is working on a problem with Dr. Watson. Watson mentioned that the CIA has been facing weird problems with their supercomputer, 'The Beast', recently.
 
 This afternoon, Sherlock received a note from Moriarty, saying that he has infected 'The Beast' with a virus. Moreover, the note had the number N printed on it. After doing some calculations, Sherlock figured out that the key to remove the virus is the largest Decent Number having N digits.
 
 A Decent Number has the following properties:
 
 3, 5, or both as its digits. No other digit is allowed.
 Number of times 3 appears is divisible by 5.
 Number of times 5 appears is divisible by 3.
 
 Meanwhile, the counter to the destruction of 'The Beast' is running very fast. Can you save 'The Beast', and find the key before Sherlock?
 
 Input Format
 The 1st line will contain an integer T, the number of test cases. This is followed by T lines, each containing an integer N. i.e. the number of digits in the number.
 
 Output Format
 Largest Decent Number having N digits. If no such number exists, tell Sherlock that he is wrong and print −1.
 
 Constraints
 1≤T≤20
 1≤N≤100000
 
 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/sherlock-and-the-beast
 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void findPossibility(int n)
{
    int n3=0,n5=0;
    for(int i=n;i>=0;i--)
        if(i%3==0 && (n-i)%5==0)
        {
            n5=i;
            n3=n-i;
            break;
        }
    if(n5==0 && n3==0)
    {
        printf("-1\n");
        return;
    }
    for(int i=0;i<n5;i++)
        printf("5");
    for(int i=0;i<n3;i++)
        printf("3");
    printf("\n");
    return;
}

int main() {
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int n;
        scanf("%d\n",&n);
        findPossibility(n);
    }
    return 0;
}