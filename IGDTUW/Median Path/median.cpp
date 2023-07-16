// For the Tree Median Question

// Divide it into two problems:

// A standard DFS from root of a tree
// Finding median of a continuous stream of integers.
// Both of these subproblems are already present on leetcode. Combining both I came up with this solution.

// What I did is I started doing a DFS from the root and while I am visiting nodes I am calculating median till current using the 2 priority queues if sum of sizes of the 2 priority queues is odd.

#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<int> &c, int parent, priority_queue<int, vector<int>, greater<int>> &minPQ, priority_queue<int> &maxPQ) {
    int value = c[node];

    //Store the original state of the heaps
    priority_queue<int, vector<int>, greater<int>> minPQCopy = minPQ;
    priority_queue<int> maxPQCopy = maxPQ;

    if(minPQ.size() == maxPQ.size()) {
        if(minPQ.empty() || value >= maxPQ.top()) {
            minPQ.push(value);
        } else if(value < maxPQ.top()) {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
            maxPQ.push(value);
        }
    } else if(minPQ.size() > maxPQ.size()) {
        if(value < minPQ.top()) {
            maxPQ.push(value);
        } else {
            maxPQ.push(minPQ.top());
            minPQ.pop();
            minPQ.push(value);
        }
    } else {
        if(value > maxPQ.top()) {
            minPQ.push(value);
        } else {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
            maxPQ.push(value);
        }
    }

    int medianSums = 0;
    if(minPQ.size() == maxPQ.size() + 1) {
        medianSums = minPQ.top();
    }

    for(int adjNode: adj[node]) {
        if(adjNode != parent) {
            medianSums += dfs(adjNode, adj, c, node, minPQ, maxPQ);
        }
    }

    //Restore the original state of the heaps
    minPQ = minPQCopy;
    maxPQ = maxPQCopy;

    return medianSums;
}

void solve(int n, vector<int> &c, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for(auto &it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);
    priority_queue<int, vector<int>, greater<int>> minPQ;
    priority_queue<int> maxPQ;
    int res = dfs(0, adj, c, -1, minPQ, maxPQ);
    cout << res << endl;
}

//driver code
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for(int &i: c) {
            cin >> i;
        }
        vector<vector<int>> edges;
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u - 1, v - 1});
        }
        solve(n, c, edges);
    }
}