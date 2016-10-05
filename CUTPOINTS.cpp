//
//  main.cpp
//  CUTPOINTS
//
//  Created by user on 24.12.15.
//  Поиск шарниров в графе.
//

#include <iostream>

using namespace std;
int f = 0;




void cutpoints(int** g, bool* iscutpoint, int* next, int* tin, int* ch, int* used, int time, int v, int n)
{
    used[v] = 1;
    time++;
    tin[v] = time;
    next[v] = n + 1;
    for (int u = 0; u < n; u++)
    {
        if (g[v][u] == 1)
        {
            if (used[u] == 0)
            {
                if (v == 0) f ++;
                ch[v]++;
                cutpoints(g, iscutpoint, next, tin, ch, used, time, u, n);
                next[v] = min(next[v], next[u]);
                if (next[u] >= tin[v]) iscutpoint[v] = true;
            }
            else next[v] = min(next[v], tin[u]);
        }
    }
}
int main() {
    
    int n,m,a,b;
    cin >> n>>m;
    
    int **g;
    g = new int*[n];
    for(int i = 0; i < n; i++)
        g[i] = new int [n];
    bool *iscutpoint = new bool [n];
    int *next = new int [n];
    int *tin = new int [n];
    int *ch = new int [n];
    int *used = new int [n];
  
    
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }
    
    for (int i=0; i<m;i++){
        cin>>a>>b; g[a][b]=1; g[b][a]=1;
        cout<<a<<" and "<<b<<" connected!"<<endl;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            //cin >> g[i][j];
            iscutpoint[i] = false;
            next[i] = 0;
            tin[i] = 0;
            ch[i] = 0;
            used[i] = 0;
   }
 int time = 0;
    for (int v = 0; v < n; v++)
    {
        if (used[v] == 0)
        {
            cutpoints(g, iscutpoint, next, tin, ch, used, time, v, n);
            if (ch[v] > 1) iscutpoint[v] = true;
        }
    }
    if (f >= 2) iscutpoint[0] = true;
    else iscutpoint[0] = false;
    for (int i = 0; i < n; i++)
    {
        if (iscutpoint[i] == true) cout << i << ' ';
    }
    return 0;
}
