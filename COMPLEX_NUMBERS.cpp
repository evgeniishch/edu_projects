#include <iostream>
#include <cmath>

using namespace std;

class C {
private:
    double real;
    double imaginary;
    double r;
    double phi;

    friend double Re(C z);
    friend double Im(C z);
    friend double mod(C z);


public:
    //constructors
    C (double realPart, double imaginaryPart){
        this->imaginary = imaginaryPart;
        this->real = realPart;
        this->r = sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
        this->phi = (asin(imaginaryPart/r) * 180.0) / M_PI;
    }

    C (double realPart){
        this->real = realPart;
        this->imaginary = 0;
    }

    void printTrig(){
        cout<<r<<"(cos("<<phi<<") + i*sin("<<phi<<"))";
    }

    void printExp(){
        cout<<r<<"*e^(i*"<<phi<<")";
    }

};

//friendly functions Re(z) & Im(z)

double Re (C z){
    return z.real;
}

double Im (C z){
    return z.imaginary;
}

double mod (C z){
    return sqrt(Re(z)*Re(z) + Im(z)*Im(z));
}

//overloaded operators

C operator +(C a, C b){
    return C (Re(a) + Re(b), Im(a) + Im(b));
}

C operator -(C a, C b){
    return C (Re(a) - Re(b), Im(a) - Im(b));
}

C operator *(C a, C b){
    return C (Re(a)*Re(b) - Im(a)*Im(b), Im(a)*Re(b) + Re(a)*Im(b));
}

C operator /(C a, C b){
    return C ((Re(a)*Re(b) + Im(a)*Im(b))/(Re(b)*Re(b) + Im(b)*Im(b)), (Re(b)*Im(a) - Re(a)*Im(b))/(Re(b)*Re(b) + Im(b)*Im(b)));
}

bool operator ==(C a, C b){
    return (Re(a)==Re(b) && Im(a)==Im(b));
}

bool operator !=(C a, C b){
    return !(Re(a)==Re(b) && Im(a)==Im(b));
}

ostream& operator <<(ostream & os, C z){
    os<<Re(z)<<" + "<<Im(z)<<"i";
    return os;
}

int main() {
    C number1 = C(1,5);
    C number2 = C(4);
    C number3 = number1 + number2;

    cout<<number1<<endl<<number2<<endl<<number3<<endl;

    cout<<Re(number3)<<" "<<Im(number3)<<" "<<mod(number3)<<endl;

    if(number1!=number2){
        number3.printTrig();
        cout<<endl;
        number3.printExp();
    }

    return 0;
}