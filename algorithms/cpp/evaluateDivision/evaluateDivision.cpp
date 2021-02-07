// Source: https://leetcode.com/problems/evaluate-division/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //g[A][B] = k -> A/B = k
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            graph[a][b] = v;
            graph[b][a] = 1.0 / v;
        }

        vector<double> res;
        for (auto q: queries) {
            string x = q[0];
            string y = q[1];
            if (!graph.count(x) || !graph.count(y)) {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(divide(x, y, graph, visited));
        }
        return res;
    }

private:
    double divide(string &a, string &b,
                  unordered_map<string, unordered_map<string, double>> &graph,
                  unordered_set<string> &visited) {
        if (a == b) return 1.0;
        visited.insert(a);
        for (auto p: graph[a]) {
            string c = p.first;
            if (visited.count(c)) continue;
            double d = divide(c, b, graph, visited);
            if (d > 0) return d * graph[a][c];
        }
        return -1.0;
    }
