//
//  main.cpp
//  INTROSORT
//
//  Created by user on 28.02.16.
//  Интроспективная сортировка. Интросорт.
//

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


void quicksort(int Arr[],int left, int right){
    int i=left,j=right;
    int temp;
    int middle = Arr[(left+right)/2];
    
    while (i<=j){
        while (Arr[i]>middle)i++;
        while (Arr[j]<middle)j--;
        
        if(i<=j){
            temp=Arr[i];
            Arr[i]=Arr[j];
            Arr[j]=temp;
            i++;j--;
        }
        
    }
    
    if(left<j)
        quicksort(Arr,left,j);
    if(i<right)
        quicksort(Arr,i,right);
}

void MAX_HEAPIFY(int a[], int i, int n)
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if((r<=n)&&(a[r]>a[largest]))
        largest=r;
    if(largest!=i)
    {
        loc=a[i];
        a[i]=a[largest];
        a[largest]=loc;
        MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(int a[], int n)
{
    
    BUILD_MAX_HEAP(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}

int recursion=0;
int n;

void introsort(int Arr[],int left, int right){
    recursion++;
    int i=left,j=right;
    int temp;
    int middle = Arr[(left+right)/2];
    
    while (i<=j){
        while (Arr[i]>middle)i++;
        while (Arr[j]<middle)j--;
        
        if(i<=j){
            temp=Arr[i];
            Arr[i]=Arr[j];
            Arr[j]=temp;
            i++;j--;
        }
        
    }
    
    if(left<j && recursion < log(n))
    { introsort(Arr,left,j);}else {HEAPSORT(Arr, j-i);};
    if(i<right && recursion < log(n))
    {introsort(Arr,i,right);} else {HEAPSORT(Arr, j-i);};
}



int main(int argc, const char * argv[]) {
    clock_t time1;
    cin>>n;
    cout<<"Logarifm: "<<log(n)<<endl;
    int *arr = new int[n];
    //for(int i=0;i<n;i++){arr[i]=i;}//cout<<arr[i]<<" ";}; //     заполнение массива порядковыми номерами по возрастанию
     for(int i=n;i>=0;i--){arr[i]=rand()%10000;}//cout<<arr[i]<<" ";}; // заполнение массива рандомными числами
    cout<<endl;
    
    cout<<"Sort started"<<endl;
    
    time1 = clock();
    quicksort(arr, 0, n-1); //сортируем по убыванию
    //introsort(arr, 0, n-1); //сортируем по убыванию
    time1 = clock() - time1;
    cout<<"Sort finished"<<endl;
    cout<< "First: "<<arr[0]<<" Last: "<<arr[n-1]<<endl;
    
    bool badSorted=false; for(int i=0;i<n-1;i++){if(arr[i]<arr[i+1])badSorted=true;};
    
    cout<<"Runtime: "<<time1<<endl;
    cout<<"Recursion: "<<recursion<<endl;
    if(badSorted==true){cout<<"Sorted bad";}else{cout<<"Sorted good";};
    cout<<endl;
    
}
