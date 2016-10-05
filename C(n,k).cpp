//
//  main.cpp
//  RAZMESHCHENYA
//
//  Created by user on 17.04.16.
//

#include "iostream"
#include "vector"

using namespace std;

vector<int>K(10000000);
vector<int>A(10000000);

int factorial(int n)
{
    int p=1.;
    for(int i=2;i<=n;i++)
        p*=i;
    return p;
}

int permutation(int n,int k)
{
    return factorial(n)/factorial(n-k);
}

void permutations (int n, int k, int s)
{
    if ((s+1)<k){
        for (int j=0; j<n; j++){
            int x=0;
            for (int i=0; i<s; i++){
                if (K[i] == A[j])
                    x=1;
            }
            if (x == 0){
                K[s] = A[j];
               permutations(n,k,s+1);
            }
        }
    }
    else {
        for (int j=0; j<n; j++){
            int x=0;
            for (int i=0; i<s; i++) {
                if (K[i] == A[j])
                    x=1;
            } 
            if (x == 0) {
                K[s] = A[j]; 
                for (int i=0; i<k; i++)
                cout << K[i] << " ";
                cout<<endl;
            } 
        } 
    } 
}

int main()
{
    int n,k;
    cout<<"Enter N: ";cin>>n;
    cout<<"Enter k: ";cin>>k;
    int p = permutation(n,k);
    
    cout<<"There are "<<p<<" permutations from "<<n<<" of "<<k<<":"<<endl;
 
    K.resize(k);
    A.resize(n);
    
    for (int i=0; i<n; i++)
        A[i]=i+1;
    
    permutations(n,k,0);
    
    return 0; 
}