// Source: https://leetcode.com/problems/employee-importance/
// Author: Miao Zhang
// Date:   2021-03-01

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> dic;
        for (auto e: employees) dic[e->id] = e;
        return dfs(id, dic);
    }

private:
    int dfs(int id, unordered_map<int, Employee*>& dic) {
        auto e = dic.at(id);
        int sums = e->importance;
        for (int rid: e->subordinates) {
            sums += dfs(rid, dic);
        }
        return sums;
    }
};
