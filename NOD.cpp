//
//  main.cpp
//  НОД
//
//  Created by user on 27.09.15.
//

#include <iostream>
using namespace std;

int evkl(int n, int m)
{ int r;
    if (n%m==0){return m;} else
    { cout<<n<<"="<<m<<"*"<<(n/m)<<"+"<<n-m*(n/m)<<endl;
       r=n%m;
       n=m;
       m=r;
       return(evkl(n,m));
    }
}

int main()
{  int n;//к
   int m;//l
    cin>>n>>m;
    cout<<evkl(n,m);
    return 0;
}