//
//  main.cpp
//  KOMPONENTA_SVYAZNOSTY
// Поиск компонент связности в графе
//
//  Created by user on 21.11.15.
//

#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> g;
vector<int> comp;

/*int stepen(int v1){
    int v=v1-1;
    int stepen=0;
    for (int i=0; i<n; i++){
        if(g[v][i]==1) stepen+=1;
    }
    return stepen;
} */


void dfs (int v, vector<vector<int>> g, int n1, bool used[]) {
    used[v] = true;
    comp.push_back (v);
    for (int i=0; i<n1; i++) {
        int next = g[v][i];
        if (next==1 && used[i]==false)
            dfs (i,g,n1,used);
        }
}


void find_comps(vector<vector<int>> g, int n1, bool used[]) {
    for (int i=0; i<n1; ++i)
        used[i] = false;
    for (int i=0; i<n1; ++i)
        if (! used[i]) {
            comp.clear();
            dfs(i,g,n1,used);

            cout << "Component:";
            for (size_t j=0; j<comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl;
        }
}


int main(int argc, const char * argv[]) {
    int n,r,a,b;
    bool *used = new bool[n];
   cin>>n>>r;

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
    
    for (int i =0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    
 //  cout<<stepen(3);
   find_comps(g,n,used);
    return 0;
}
