// Source: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> tables;
        set<string> foods;
        for (const auto& order: orders) {
            tables[stoi(order[1])][order[2]]++;
            foods.insert(order[2]);
        }
        vector<vector<string>> res;
        res.push_back({{"Table"}});
        res.back().insert(end(res.back()), begin(foods), end(foods));
        for (auto& [table, m]: tables) {
            vector<string> line{to_string(table)};
            for (const auto& food: foods) {
                line.push_back(to_string(m[food]));
            }
            res.push_back(move(line));
        }
        return res;
    }
};
