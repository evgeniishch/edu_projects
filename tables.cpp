
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <iomanip>

using namespace std;

struct Column {
    Column () {}
    Column (double nx, double ny) {
        x = nx;
        y = ny;
    }
    double x;
    double y;
};

double dist(vector<Column> &columns, double v1, double v2) {
    return sqrt((columns[v1].x - columns[v2].x)*(columns[v1].x - columns[v2].x) + (columns[v1].y - columns[v2].y)*(columns[v1].y - columns[v2].y));
}

bool dfs (vector<vector<double>> &graph, double maxD, int vertex, int rightWallIndex, vector<bool> &visited) {
    stack <int> s;
    s.push(vertex);

    while(!s.empty()) {
        int v = s.top();
        visited[v] = true;
        s.pop();

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[v][i] < maxD && !visited[i]) {
                if (i == rightWallIndex) {
                    return true;
                }
                s.push(i);
            }
        }
    }
    return false;
}


bool isWay(vector<vector<double>> &graph, double maxD) {

    vector <bool> visited(graph.size(), false);
    vector <vector<int>> components;

    int leftWallIndex = graph.size() - 2;
    int rightWallIndex = graph.size() - 1;

    return dfs(graph, maxD, leftWallIndex, rightWallIndex, visited);
}

double binSearch(vector<vector<double>> &graph, double maxD) {
    double left = 0;
    double right = maxD;
    double mid = 0;

    while (right - left > 0.00000001) {
        mid = (right + left) / 2;
        if (isWay(graph, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {

    double xl = 0, xr = 0;
    cin >> xl >> xr;
    double r = 0;
    cin >> r;
    unsigned long n = 0;
    cin >> n;

    vector <Column> columns;

    //Reading vertices
    double newx = 0, newy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> newx >> newy;
        columns.emplace_back(Column(newx, newy));
    }

    // INITIALIZING GRAPH
    vector<vector<double>> graph(n + 2);
    for (int i = 0; i < n + 2; ++i) {
        graph[i].resize(n + 2, 0);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double d = dist(columns, i, j) - 2 * r;
                graph[i][j] = d;
                graph[j][i] = d;
            }
        }
    }

    double leftWallIndex = n;
    double rightWallIndex = n + 1;

    for (int i = 0; i < n; ++i) {
        graph[leftWallIndex][i] = columns[i].x - xl - r;
        graph[i][leftWallIndex] = columns[i].x - xl - r;

        graph[i][rightWallIndex] = xr - columns[i].x - r;
        graph[rightWallIndex][i] = xr - columns[i].x - r;
    }

    graph[leftWallIndex][rightWallIndex] = xr - xl;
    graph[rightWallIndex][leftWallIndex] = xr - xl;

    double ans = round(binSearch(graph, xr - xl)*1000);

    cout.precision(3);
    cout << fixed << ans/1000 << endl;

    return 0;
}
