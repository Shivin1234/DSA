#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Disjoint {
public:
    int n;
    vector<int> par;
    vector<int> rank;

    Disjoint(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);  // path compression
    }

    void unionbyrank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) return;  // already connected

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }
};

// Edge: {weight, {u, v}}
int kruskal(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end());  // sort by weight
    Disjoint dsu(V);

    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    for (auto& edge : edges) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unionbyrank(u, v);
            mstWeight += wt;
            mstEdges.push_back({u, v});
        }
    }

    // Output the MST edges (optional)
    cout << "Edges in MST:\n";
    for (auto& edge : mstEdges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return mstWeight;
}

// Example usage
int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {10, 0, 1},
        {15, 0, 2},
        {5, 1, 2},
        {20, 1, 3},
        {30, 2, 3}
    };

    int mstCost = kruskal(V, edges);
    cout << "Total weight of MST: " << mstCost << endl;

    return 0;
}
