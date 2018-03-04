// дополнение до сильносвязного
#include <iostream>
#include <vector>

using namespace std;

class Solver {

public:
    Solver () {}
    void readGraph();
    int solve ();

private:
    void dfs(vector<vector<int>> &graph, vector <bool> &visited, vector<int> &vectorToBeFilled, int v);
    void findComps();
    int countOutgoingEdges(vector<vector<int>> &graph);

    int numberOfVertices;
    int numberOfEdges;

    vector<vector<int>> graph;
    vector<vector<int>> transpose;
    vector<vector<int>> components;
    vector <int> componentMap;

};

void Solver::readGraph() {
    cin >> numberOfVertices;
    cin >> numberOfEdges;

    graph.resize(numberOfVertices);
    transpose.resize(numberOfVertices);
    componentMap.resize(numberOfVertices);

    for (int i = 0; i < numberOfVertices; ++i) {
        graph[i].resize(numberOfVertices, 0);
        transpose[i].resize(numberOfVertices, 0);
    }

    int from = 0, to = 0;

    for (int i = 0; i < numberOfEdges; ++i) {
        cin >> from >> to;
        graph[from - 1][to - 1] = 1;
        transpose[to - 1][from - 1] = 1;
    }
}

int Solver::solve() {
    findComps();

    for (int i = 0; i < components.size(); ++i) {
        for (int j = 0; j < components[i].size(); ++j) {
            componentMap[components[i][j]] = i;
        }
    }

    int numberOfSinks = 0, numberOfNotSinks = 0;

    numberOfSinks = countOutgoingEdges(graph);
    numberOfNotSinks = countOutgoingEdges(transpose);

    if (components.size() == 1){
        return 0;
    } else {
        return max(numberOfSinks, numberOfNotSinks);
    }
}

void Solver::dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &vectorToBeFilled, int v) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if(!visited[i] && graph[v][i] == 1) {
            dfs(graph, visited, vectorToBeFilled, i);
        }
    }
    vectorToBeFilled.push_back(v);
}

void Solver::findComps() {

    vector<int> order;
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, order, i);
        }
    }

    for (int i = 0; i < visited.size(); ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < graph.size(); ++i) {
        int v = order[graph.size() - i - 1];
        if (!visited[v]) {
            vector <int> newComponent;
            dfs(transpose, visited, newComponent, v);
            components.push_back(newComponent);
            newComponent.clear();
        }
    }
}

int Solver::countOutgoingEdges(vector<vector<int>> &graph) {
    int number = 0;
    for (int i = 0; i < components.size(); i++) {
        bool hasOutgoingEdge = false;
        for (int j = 0; j < components[i].size(); ++j) {
            for (int k = 0; k < graph.size(); ++k) {
                if (graph[components[i][j]][k] == 1 && componentMap[k] != i ) {
                    hasOutgoingEdge = true;
                }
            }
        }
        if(!hasOutgoingEdge ) {
            number++;
        }
    }
    return number;
}

int main () {
    Solver s;
    s.readGraph();
    cout << s.solve();
    return 0;
}
