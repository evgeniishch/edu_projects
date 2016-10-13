//
//  main.cpp
//  COMPARE_RECTANGLES_AND_MONTE_CARLO
//
//  Created by user on 13.10.16.
//  Сравнение численного интегрирования методами нижних прямоугольников и методом Монте-Карло

#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

struct dot{
    double x;
    double y;
    
    dot(){};
    dot(double x1, double y1){
        x = x1;
        y = y1;
    }
    
};

double exactIntegral(double a,double b){

    return 0.25*log(abs(b*b*b*b+2*b*b+2))-atan(b*b+1) - 0.25*log(abs(a*a*a*a+2*a*a+2))+atan(a*a+1) ;
}

double exactFunction(double x){
    
    return (x*x*x-x)/(x*x*x*x + 2*x*x +2);
}



double MonteKarlo(int n_dots, double a, double b){

    dot *dots = new dot[n_dots];
    
    srand(time(0));
    
    for(int i=0; i<n_dots; i++){
        
        dots[i].x = double(rand()%int(b*10000 - a*10000) + a*10000)/100000;
        dots[i].y = (double(rand() % 27000))*0.00001; // 0.27 - максимальная величина генерации OY.
                                                      //В данном случае подобрана специально под функцию.
        
    }
    
    double sum = 0;
    
    for (int i=0; i<n_dots; i++) {
        if(dots[i].y <= (-1)*exactFunction(dots[i].x)) sum+=1;
    }
    
    return sum/n_dots;
}


double rectangles(int n_segments, double a, double b){
    
    double segment = (b-a)/n_segments;
    double sum = 0;
    
    for(int i=0; i<n_segments-1; i++){
        sum += exactFunction(a + segment*i)*segment;
    }
    
    return sum;
}



int main(int argc, const char * argv[]) {
 
    int n_dots, n_segments;
    double a, b;
    
    cout<<"Введите количество отрезков для метода прямугольников:  ";
    cin>>n_segments;
    
    cout<<"Введите количество точек для метода Монте-Карло: ";
    cin>>n_dots;
    
    cout<<"Введите координаты отрезка для приближения определенного интеграла: "<<endl;
    cout<<"a = "; cin>>a;
    cout<<"b = "; cin>>b;
    
    cout<<"Точное значение определенного интеграла: "<<exactIntegral(a,b)<<endl;
    cout<<"Приближение методом ниж прямоугольников: "<<rectangles(n_segments,a,b)<<endl;
    cout<<"Приближение методом Монте - Карло:   "<<MonteKarlo(n_dots,a,b)<<endl;
    
    return 0;
}
