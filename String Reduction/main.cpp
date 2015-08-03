/*
 Author : Yeshwanth D S
 Problem Statement
 
 String Reduction (25 Points)
 
 Given a string consisting of letters, a, b and c, we can perform the following operation: Take any two adjacent distinct characters and replace them with the third character. For example, if 'a' and 'c' are adjacent, they can replaced by 'b'. Find the smallest string which we can obtain by applying this operation repeatedly?
 
 Input:
 The first line contains the number of test cases T. T test cases follow. Each test case contains the string you start with.
 
 Output:
 Output T lines, one for each test case, containing the smallest length of the resultant string after applying the operations optimally.
 
 Constraints:
 1 <= T <= 100
 The string will have at most 100 characters.
 
 Sample Input:
 3
 cab
 bcab
 ccccc
 
 Sample Output:
 2 
 1 
 5
 

 Source : hackerrank.com
 
 Problem Link : https://www.hackerrank.com/challenges/string-reduction
 */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/* Head ends here */

int stringReduction(char a[]) {
    int count[3]={0},size = strlen(a);
    for(int i=0;i<size;i++)
        count[a[i]-'a']++;
    if(count[0] == size || count[1] == size || count[2] == size)
        return size;
    else if((count[0]%2==0 && count[1]%2==0 && count[2]%2==0) || (count[0]%2!=0 && count[1]%2!=0 && count[2]%2!=0))
        return 2;
    else
        return 1;
}

int main() {
    int res, t, i;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res=stringReduction(a);
        printf("%d\n",res);
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
