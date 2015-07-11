#include<iostream>
using namespace std;
int sum(int num)
{
	int s=0;
	while(num>=10)
	{
		s+=num%10;
		num/=10;
	}
	s+=num;
	return s;
}
int main()
{
	int num,result;
	cin>>num;
	result=num;
	while(result>=10)
	{
		result=sum(result);
	}
	cout<<result;
}
