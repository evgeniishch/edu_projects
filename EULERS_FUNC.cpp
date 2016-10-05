//
//  main.cpp
//  Функция Эйлера
//
//  Created by user on 27.09.15.
//

#include <iostream>

int eulers (int n)
{
  int phi = n;
  for (int i=2; i*i<=n; i++)
    if (n % i == 0)
     {
        while (n % i == 0)
                n /= i;
            phi -= phi / i;
     }

    if (n > 1)
        phi -= phi / n;
    return phi;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin>>n;
    std::cout<<eulers(n);

    return 0;
}
