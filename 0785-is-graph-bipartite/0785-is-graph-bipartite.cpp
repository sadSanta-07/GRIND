
class Solution {
public:
    bool chkbidfs(vector<vector<int>>& adj, int curr, vector<int>& color,
                  int currcolor) {

        color[curr] = currcolor;

        for (int v : adj[curr]) {

            // Same color on adjacent nodes = not bipartite
            if (color[v] == color[curr])
                return false;

            // If not colored, assign opposite color
            if (color[v] == -1) {
                int colorofv = 1 - currcolor;

                if (chkbidfs(adj, v, color, colorofv) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (chkbidfs(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
