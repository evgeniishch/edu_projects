//
//  main.cpp
//  Сумма факториалов до n
//
//  Created by user on 27.09.15.
//

#include <iostream>

int fact(int i)
{ int f=1;
    for (int j=1; j<=i; j++)
    { f*=j;}
    return f;
}





int main(int argc, const char * argv[])
{  int n, s=0;
   std::cin>>n;
    
    for (int i=1; i<=n;i++)
        s+=fact(i);
    
    std::cout<<s;
    
    return 0;
}
