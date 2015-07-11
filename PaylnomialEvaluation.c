//Evaluation of polynomial..
//eg: 2x^2+x+1
#include<stdio.h>

int power(int x, int y);

int main()
{
    /*write your code here*/
	int n,x,i,sum=0;
	scanf("%d %d",&n,&x);
	int a[n];
	for(i=n;i>=0;i--)
	{
		scanf("%d",&a[i]);
	}
	i=0;
	while(i<=n)
	{
		sum+=a[i]*power(x,i);
		i++;
	}
	printf("%d",sum);
    return 0;
}

 int power(int x, int y)
 {
   int result = x;

   if(y == 0) return 1;
   if(x < 0 || y < 0) return 0;

   for(int i = 1; i < y; ++i)
   result *= x;

   return result;
}