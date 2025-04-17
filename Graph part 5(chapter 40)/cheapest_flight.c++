#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    class Info {
    public:
        int u;
        int cost;
        int stops;

        Info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        q.push(Info(src, 0, -1));  // Changed -1 to 0 for stops

        while (q.size() > 0) {
            Info curr = q.front();
            q.pop();

            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == curr.u) {  // Fixed '=' to '=='
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if (dist[v] > curr.cost + wt && curr.stops <= k) {
                        dist[v] = curr.cost + wt;
                        q.push(Info(v, dist[v], curr.stops + 1));
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX) {  // Fixed '=' to '=='
            return -1;
        }
        return dist[dst];
    }
};

// Example main function
int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };
    int src = 0, dst = 3, k = 1;

    int result = sol.findCheapestPrice(V, flights, src, dst, k);
    cout << "Cheapest price: " << result << endl;

    return 0;
}
