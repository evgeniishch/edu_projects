//
//  main.cpp
//  error_1024
//
//  Created by user on 25.09.16.
//  Copyright © 2016 WOLFTRAX INC. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    double number = 1234567891.0;

    number *= 1000000000000000;
    number /= 1000000000000000;

    cout<<number;

    return 0;
}
