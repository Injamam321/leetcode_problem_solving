// 2467. Most Profitable Path in a Tree
// cpp Solution! problem-2467

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> bobPath;
    unordered_map<int, int> profit;
    vector<int> amount;
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amn)
    {
        int n = edges.size() + 1;
        amount = amn;
        vector<int> parent;
        parent.reserve(n);
        vector<int> visit(n, 0);
        vector<vector<int>> g(n);
        for (auto &edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        parent[0] = -1;
        dfs(g, 0, visit, parent);
        int bobstep = 0;
        while (bob >= 0)
        {
            bobPath[bob] = bobstep;
            bob = parent[bob];
            bobstep++;
        }
        for (int i = 0; i < n; i++)
        {
            visit[i] = 0;
        }
        dfs_profit(g, 0, visit, 0, 0);
        int result = INT_MIN;
        for (auto pr : profit)
        {
            if (pr.first != 0 && g[pr.first].size() == 1)
                result = max(result, pr.second);
        }
        return result;
    }

    void dfs_profit(vector<vector<int>> &g, int node, vector<int> &visit, int lvl, int prf)
    {
        if (bobPath.find(node) != bobPath.end())
        {
            if (bobPath[node] < lvl)
            {
                profit[node] = prf;
            }
            else if (bobPath[node] == lvl)
            {
                profit[node] = prf + amount[node] / 2;
            }
            else
            {
                profit[node] = prf + amount[node];
            }
        }
        else
        {
            profit[node] = prf + amount[node];
        }
        visit[node] = 1;
        for (auto adjNode : g[node])
        {
            if (visit[adjNode] == 0)
            {
                dfs_profit(g, adjNode, visit, lvl + 1, profit[node]);
            }
        }
    }
    void dfs(vector<vector<int>> &g, int node, vector<int> &visit, vector<int> &parent)
    {
        visit[node] = 1;
        for (int adjNode : g[node])
        {
            if (visit[adjNode] == 0)
            {
                parent[adjNode] = node;
                dfs(g, adjNode, visit, parent);
            }
        }
    }
};