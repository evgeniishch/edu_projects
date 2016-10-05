//
//  main.cpp
//  STEPEN'
//
//  Created by user on 18.10.15.
//  Быстрое возведение в степень
//

#include <iostream>
using namespace std;

long long func(long long x, long long y)
{ if (x==0) return 0;
  if (y==0) return 1;
  if (y==1) return x;
  if (y%2==0){ return func(x*x,y/2);} else {return x*func(x,y-1);};
}

int main(int argc, const char * argv[])
{   long long a,b;
    cin>>a>>b;
    cout<<func(a,b);
    return 0;
}
