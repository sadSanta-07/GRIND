class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // graph adjecency list
        vector<vector<int>> adj(n); // u-> ngbr1 , ngbr2
        vector<int> indegree(n, 0);
        vector<bool> suspicious(n, false);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // bfs
        queue<int> qu;
        qu.push(k);
        suspicious[k] = true;

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();

            for (int& ngbr : adj[curr]) {
                indegree[ngbr]--;
                if (!suspicious[ngbr]) {
                    qu.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }
        vector<int> result;
        bool canotremov = false;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && indegree[i] > 0) {
                // we canot remove anything . just 0,1,2,3,....n-1
                canotremov = true;
                break;
            }
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        if (canotremov) {
            vector<int> vec(n);
            for (int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};