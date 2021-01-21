// Source: https://leetcode.com/problems/clone-graph/
// Author: Miao Zhang
// Date:   2021-01-20

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> dicts;
        queue<Node*> q;
        q.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* cur_node = q.front();
                q.pop();
                Node* copy_node = new Node(cur_node->val);
                dicts[cur_node] = copy_node;
                for (auto neighbor: cur_node->neighbors) {
                    if (visited.count(neighbor) == 0) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
        
        for (auto it = dicts.begin(); it != dicts.end(); it++) {
            for (auto neighbor: it->first->neighbors) {
                it->second->neighbors.push_back(dicts[neighbor]);
            }
        }
        return dicts[node];
    }
};
