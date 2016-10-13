//
//  main.cpp
//  LAGRANGE_POLYNOMIAL
//
//  Created by user on 01.10.16.
//  Построение полинома Лагранжа. Вывод коэффициентов.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


#include <iostream>

using namespace std;


void lagrange (vector<double> x_values, vector<double>y_values, int n){
    
    vector <double> coefficients = *new vector<double>(n+1);
    vector <double> curValues = *new vector<double>(n+1);
    double currCoef,u; int k;
    
    for (int i=1;i<=n;i++)
    {
        coefficients[i]=0;
    }
    
    for (int i=1;i<=n;i++)
    {
        currCoef=1;
        curValues[1]=1;
        k=1;
        
        for (int j=1; j<=n; j++)
            if (i!=j)
            {
                currCoef*=(x_values[i]-x_values[j]); //перемножаем разности числителя
                curValues[k+1]=1;
                if (k>1)
                    for (int a=k ; a>=2;a--)
                        curValues[a]=curValues[a-1]-curValues[a]*x_values[j];
                curValues[1]=-curValues[1]*x_values[j];
                k++;
            }
        u=y_values[i]/currCoef;
        for (int m=1; m<=n;m++)
            coefficients[m]=coefficients[m]+curValues[m]*u;
    }
    
    cout <<"Многочлен Лагрнжа:"<<endl;
    for (int i=n;i>=1;i--)
        cout<<coefficients[i]<<" ";

    
    
}

int main()
{
    int n,k;
    cout<<"Введите количество известных точек:  ";
    cin>>n;
    
    vector <double> x_values = *new vector<double>(n+1);
    vector <double> y_values = *new vector<double>(n+1);
   
    for(int i=1;i<=n;i++) {
        cout<<"x["<<i<<"]= ";
        cin>>x_values[i];
        cout<<"y["<<i<<"]= ";
        cin>>y_values[i];
    }
    
    lagrange(x_values,y_values,n);

    
    return 0;
}





