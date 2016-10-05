//
//  main.cpp
//  проверка чиcла на простоту
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
    // insert code here...
    unsigned long n,border,f = 0;
    std::cout << "Введите число\n";
    std::cin>>n;
    
    if (n==1||n==0){std::cout<<"Число простое";} else {
    
    if (proverka(n)==0) {std::cout<<"Число не простое";} else {std::cout<<"Число простое";};
    }
        return 0;
}
