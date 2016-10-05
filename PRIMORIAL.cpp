//
//  main.cpp
//  праймариал
//
//  Created by user on 20.09.15.
//

#include <iostream>
#include <math.h>

int proverka(unsigned long n)
{
    unsigned long i, j, border;
    if (n == 2 || n == 3 || n == 5)
        return 1;
    if (n%2 == 0 || n%3 == 0 || n%5 == 0)
        return 0;
    border = sqrt((double)n);
    i = 7; j = 11;
    while (j <= border && n%j && n%i)
    {
        i += 6; j += 6;
    }
    if (j <= border || (i <= border && n%i == 0))
        return 0;
    return 1;
}


int main(int argc, const char * argv[]) {
unsigned long n,n1, pr=1;
using namespace std;
    std::cout<<"Введите N"<<std::endl;
    std::cin>>n1;
    n=1;
    while (n<=n1)
    {
        if (proverka(n)==1||n==1) {pr=pr*n;n++;} else {n++;n1+=1;};
    }
    std::cout<<pr;

}
