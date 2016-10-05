//
//  main.cpp
//  SHORTESTWAY2
//
//  Created by user on 22.11.15.
//  Поиск кратчайшего пути между двуми вершинами в графе. 
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void wsf(int s, int toexact, vector<vector<int>> g, vector<bool> used, vector<int> p, vector<int> d, int n1){
    queue <int> q;
    q.push(s);
 
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<n1; i++) {
            int to = g[v][i];
            if (!used[i]&&to==1) {
                used[i] = true;
                q.push(i);
                d[i] = d[v] + 1;
                p[i] = v;
            }
            
        }
    }
    
     if (used[toexact]==false)
       cout << "No path!";
    else {
        vector<int> path;
        for (int v = toexact; v!=-1; v=p[v])
            path.push_back (v);
        reverse (path.begin(), path.end());
        cout << "Path: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i]/*+ 1 */ << " ";
    }
    
}


int main(int argc, const char * argv[]) {
    
    int n,a,b,r;
    vector<vector<int>> g;
    vector<bool> used (n);
    vector<int> d (n), p (n);

    cin>>n>>r;
    used.resize(n); d.resize(n); p.resize(n);
    
    for (int i=0; i<n; ++i)
        used[i] = false;
    
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

    int s; int toexact;
 cout<<"Enter starting vertex: ";
    cin>>s;
    cout<<"Enter destination vertex: ";
    cin>>toexact;
    wsf(s, toexact,g, used, p,d,n);
    return 0;
}
