// Source: https://leetcode.com/problems/top-k-frequent-words/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for (auto& w: words) dict[w]++;
        vector<pair<string, int>> res(dict.begin(), dict.end());
        sort(res.begin(), res.end(), [](const pair<string, int>& a, const pair<string, int>& b){
            if (a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        });
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for (const string& word : words)
            dict[word]++;

        Compare comparator = [](const Node& a, const Node& b) {
            if (a.second == b.second)
                return  a.first < b.first;
            return a.second > b.second;
        };

        priority_queue<Node, vector<Node>, Compare> q(comparator);

        // O(n*logk)
        for (const auto& kv : dict) {
            q.push(kv);
            if (q.size() > k) {
                cout << q.top().first << endl;
                q.pop();
            }
        }

        vector<string> res;

        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }

        reverse(res.begin(), res.end());
        return res;

    }

private:
    typedef pair<string, int> Node;
    typedef function<bool(const Node&, const Node&)> Compare;
};
