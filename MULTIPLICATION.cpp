//
//  main.cpp
//  UMNOZHENIE
//
//  Created by user on 18.10.15.
//  Длинная арифметика. Умножение.
//

#include <iostream>
#include <stdlib.h>

using namespace std;
int length_a = 0;
int length_b = 0;
int length;

int vvod_char_a(char a[])           //ввод строки для числа а
{ int i =0;
    char l;
    do {cin.get(l);
        a[i]=l;
        i++; length_a++;} while (l !='\n');
    a[i-1]='\0';
    length_a-=1;
    return length_a;
    
}

int vvod_char_b(char b[])        //ввод строки для числа b
{ int i =0;
    char l;
    do {cin.get(l);
        b[i]=l;
        i++; length_b++;} while (l !='\n');
    b[i-1]='\0';
    length_b-=1;
    return length_b;
    
}


int proizv_length(int *x[], int *y[])        //определение длины массива summa
{
    length = length_a+length_b;
    return length;
}


int *proizv = new int[length];


int umnozh (int* x,int* y)    //умножение чисел a b и запись резульатата в массив summa
{   int razriad_proizv = length-1;
    int razriad_a = length_a-1;
    int razriad_b= length_b-1;
    int h=0;
    
    do {
        proizv[razriad_proizv]=((x[razriad_a])*(y[razriad_b])+h)%10;
        h=((x[razriad_a])*(y[razriad_b])+h)/10;
        
        razriad_proizv--; razriad_a--; razriad_b--;
        
    } while (razriad_proizv > 0);
    proizv[0]=h;
    
    return 0;
}



int main()
{
    char a[10000],b[10000];
    // int x[10000], y[10000];
    
    
    
    
    //передел из строки в массив чисел
    
    vvod_char_a(a);                  //передел из строки "a" в массив чисел "x"
    int *x = new int[length_a];
    
    
    for(int i=0; i<length_a; i++)
    {
        x[i]=(a[i])-48;
    }
    
    
    vvod_char_b(b);                  //передел из строки "b" в массив чисел "y"
    int *y = new int[length_b];
    
    
    for(int i=0; i<length_b; i++)
    {
        y[i]=(b[i])-48;
    }
    
    proizv_length(&x,&y);
    umnozh(x,y);
    
    std::cout<<"Произведение: ";
    for(int i=0; i<length; i++)
    {
        std::cout<<proizv[i];
    }
    
    
    
    
    delete [] proizv;
    delete [] x;
    delete [] y;
    return 0;
}
