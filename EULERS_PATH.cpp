//
//  main.cpp
//  EULERS_PATH
//
//  Created by user on 24.12.15.
//  Поиск Эйлерова пути в графе.
//

#include <iostream>
#include <vector>
using namespace std;
vector <vector<int>> g;
int start;


void dfs (int l, vector <vector<int>> g, int* V, int n) // обход в глубину
{
    V[l] = 1;
    for (int j = 1; j < n; j++)
    {
        if ((g[l][j] == 1) && (V[j] == 0))  dfs(j, g, V, n);
    }
}



int proverka(vector <vector<int>> g, int n) // проверяет степени вершин выводит 1, если все степени четны, выводит 2, если 2 вершины нечет степени, 3 если более 2х верш неч ст
{
    int *St = new int [n]; // массив степеней
    for (int i = 1; i < n; i++) // заполнение массива степеней вершин
    {
        int k = 0;
        for(int j = 1; j < n; j++) if (g[i][j] == 1) k++;
        St[i] = k;
    }
    int kol_nech = 0;
    for (int i = 1; i < n; i++)
    {
        if (St[i] % 2 == 1)
        {
            kol_nech++;
            start = i;
        }
    }
    if (kol_nech == 0) return 1;
    else if (kol_nech == 2) return 2;
    else return 3;
}
void poisk_puti(int** Zapas, int n, int a) // поиск пути
{
    for(int i = 1; i < n; i++)
    {
        if (Zapas[i][a] == 1)
        {
            Zapas[i][a] = 0;
            Zapas[a][i] = 0;
            poisk_puti(Zapas, n, i);
        }
    }
    cout << a << ' ';
}

int main()
{
    //создание динамических массивов
    int n,r,a,b;
    cin >>n>>r;
 //   n++;
   // int **Ar;
   // Ar = new int*[n];
  //  for(int i = 0; i < n; i++)
 //       Ar[i] = new int [n];
    int *V = new int[n];
    
    
    //ввод матрицы смежности // графа
    /* for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            cin >> Ar[i][j];
            V[i]=0;
        }*/
    
    g.resize(n);
    for (int i=0; i<n;i++){
        g[i].resize(n);
    }
    
    
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }
    
    for (int i=0; i<r;i++){
        cin>>a>>b; g[a][b]=1; g[b][a]=1;
        cout<<a<<" and "<<b<<" connected!"<<endl;
    }
    
    
    
    int k = 0;
    int **Zapas; // копирование массива
    Zapas = new int*[n];
    for(int i = 0; i < n; i++)
        Zapas[i] = new int [n];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            Zapas[i][j] = g[i][j];
        }
    
    
    
    for (int i = 1; i < n; i++) // подсчет компонент связности
    {
        if (V[i] == 0)
        {
            dfs(i,g,V,n);
            k++;
        }
    }
    
    if (k != 1) cout << "graf ne svyazniy";
    else 
    {
        int prov = proverka(g, n);
        if (prov == 3) cout << "net ehjlerova puti & cikla";
        if (prov == 1)
        {
            cout << "sushchestvuet ehjlerov cikl:" << endl;
            poisk_puti(Zapas, n, 1);
        }
        if (prov == 2)
        {
            cout << "sushchestvuet ehjlerov put:" << endl;
            poisk_puti(Zapas, n, start);
        }
    } 
    return 0;
}