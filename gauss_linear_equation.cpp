//
//  main.cpp
//  GAUSS_LINEAR_EQUATION
//
//  Created by user on 01.10.16.
//  Copyright © 2016 WOLFTRAX INC. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

float **a, *b, *x;
int N;

void initialize(){
    //выделяем память
    x = new float[N];
    b = new float[N];
    a = new float*[N];
    
    for(int i=0; i<N; i++){
        a[i] = new float[N];
        if(a[i]==NULL){
            cout<<"Недостаточно места для "<<N<<" уравнений!"<<endl;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            a[i][j]=0;
        }
        b[i]=0;
        x[i]=0;
    }
}

void readmatrix(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
        cin>>b[i];
    }
}

void printmatrix(){
    cout<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<b[i]<<endl;
    }
    cout<<endl;
}

void diagonal(){
    int i, j, k;
    float temp=0;
    for(i=0; i<N; i++){
        if(a[i][i]==0){
            for(j=0; j<N; j++){
                if(j==i) continue;
                if(a[j][i] !=0 && a[i][j]!=0){
                    for(k=0; k<N; k++){
                        temp = a[j][k];
                        a[j][k] = a[i][k];
                        a[i][k] = temp;
                    }
                    temp = b[j];
                    b[j] = b[i];
                    b[i] = temp;
                    break;
                }
            }
        }
    }
}

void printSolutions(){
    cout<<"x("<<N<<")= "<<b[N-1]/a[N-1][N-1]<<endl;
    x[N-1]=b[N-1]/a[N-1][N-1];
    for(int i=N-2;i>=0;i--){
        float sum = b[i];
        for(int j=N-1; j>i;j--){
            sum -= a[i][j]*x[j];
        }
        cout<<"x("<<i+1<<") = "<<sum/a[i][i]<<endl;
        x[i]=sum/a[i][i];
    }
}


int main(){
    
    cout<<"Введите размерность матрицы: ";
    cin>>N;

    initialize();
    readmatrix();
    
    //Проверяем есть ли на диагонали нули и переставляем строки
    diagonal();

    printmatrix();
  
    //Обработка строк
    for(int k=0; k<N; k++){
        for(int i=k+1; i<N; i++){
            if(a[k][k]==0){
                cout<<"Нет решений"<<endl;
                return 0;
            }
            float M = a[i][k] / a[k][k];
            for(int j=k; j<N; j++){
                a[i][j] -= M * a[k][j];
            }
            b[i] -= M*b[k];
        }
    }
    
    printmatrix();
    
    printSolutions();

    return 0;
}









