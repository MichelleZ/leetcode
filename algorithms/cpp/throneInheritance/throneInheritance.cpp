// Source: https://leetcode.com/problems/throne-inheritance/
// Author: Miao Zhang
// Date:   2021-05-19

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king_(kingName) {

    }

    void birth(string parentName, string childName) {
        order_[parentName].push_back(childName);
    }

    void death(string name) {
        dead_.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        function<void(string)> dfs = [&] (string king) {
            if (!dead_.count(king)) {
                res.push_back(king);
            }
            for (auto child: order_[king]) {
                dfs(child);
            }
        };
        dfs(king_);
        return res;
    }

private:
    string king_;
    unordered_map<string, vector<string>> order_;
    unordered_set<string> dead_;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
