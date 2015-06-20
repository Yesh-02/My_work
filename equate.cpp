#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int p=1,q=1,r=1,l,b,h,found = 0;
    cin>>l>>b>>h;
    int a1=l*b,b1=b*h,c1=h*l;
    for(p=1;p<=b1;p++)
    {
        for(q=1;q<=c1;q++)
        {
            for(r=1;r<=a1;r++)
            {
                if(((p*l) == (q*b)) && ((q*b) == (r*h)) && ((r*h) == (p*l)))
                {
                    found = 1;
                    break;
                }
                else if(((q*b) < (r*h)) && ((r*h) > (p*l)))
                    break;
            }
            if(found == 1)
                break;
            else if(((p*l) < (q*b)) && ((q*b) > (r*h)))
                break;
        }
        if(found ==1)
            break;
        else if(((p*l) > (q*b)) && ((r*h) < (p*l)))
            break;
    }
    if(found ==1)
        cout<<"Found"<<endl;
    cout<<p<<' '<<q<<' '<<r<<endl;
    cout<<p*l<<' '<<q*b<<' '<<r*h<<endl;
    return 0;
}