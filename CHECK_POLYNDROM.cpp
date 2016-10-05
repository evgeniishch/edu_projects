//
//  main.cpp
//  polyndrom
//
//  Created by user on 04.10.15.
//  Проверка строки на полиндромность
//

#include <iostream>


int kolvo (char s[])
{
    int kol=0;
    int i=0;
    while(s[i]!='\0'){kol++; i++;}
   
    return kol;

}

int readline(char s[])
{
    int j=0;
    char l;
    do {std::cin.get(l);
        if (l!=' '){
        s[j]=l;
            j++;}} while (l!='\n');
    s[j-1]='\0';
    return 0;
}


int main()
{std::cout<<"Check with: a roza upala na lapu azora"<<std::endl;
    char s[100];bool flag = 1;
    readline(s);
    std::cout<<kolvo(s)<<" symbols"<<std::endl;
    
    if((kolvo(s))%2==0)
    {
        int nach=0;
        int konec=kolvo(s)-1;
        while (nach!=kolvo(s)/2)
        { if(s[nach]==s[konec]){nach++;konec--;} else {flag=0;break;};
        }
        
    }
    
    else {
        
        int nach=0;
        int konec=kolvo(s)-1;
        while (nach!=(kolvo(s)-1)/2)
        { if(s[nach]==s[konec]){nach++;konec--;} else {flag=0;break;};
        }
        
        
        
         };
    
    if (flag==1){ std::cout<<"Polindrom"<<std::endl;}
    
    else {std::cout<<"not Polindrom"<<std::endl;};

    return 0;
}