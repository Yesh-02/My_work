#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;

queue<int> Q1;
queue<int> Q2;

void Push(int data)
{
    Q1.push(data);
}

int Pop()
{
    if(Q1.size()==0)
        return -1;
    while(Q1.size() != 1)
    {
        Q2.push(Q1.front());
        Q1.pop();
    }
    int temp = Q1.front();
    Q1.pop();
    queue<int> t = Q1;
    Q1 = Q2;
    Q2 = t;
    return temp;
}

int main(void)
{
    Push(10);
    Push(20);
    Push(30);
    printf("%d\n",Pop());
    Push(40);
    printf("%d\n",Pop());
    printf("%d\n",Pop());
    printf("%d\n",Pop());
    printf("%d\n",Pop());
    Push(60);
    printf("%d\n",Pop());
    return 0;
}