// Source: https://leetcode.com/problems/reconstruct-itinerary/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        route_.clear();
        trips_.clear();
        
        for (const auto& t: tickets) {
            trips_[t[0]].push_back(t[1]);
        }
        for (auto& t: trips_) {
            auto& dests = t.second;
            std::sort(dests.begin(), dests.end());
        }
        
        string kstart = "JFK";
        visit(kstart);
        return vector<string>(route_.crbegin(), route_.crend());
    }
private:
    // src -> {dst1, dst2, ..., dstn}
    unordered_map<string, deque<string>> trips_;
    // res
    vector<string> route_;

    void visit(string& src) {
        auto& dests = trips_[src];
        while (!dests.empty()) {
            // get the smallest
            string dest = dests.front();
            // remove
            dests.pop_front();
            // visit dest
            visit(dest);
        }
        route_.push_back(src);
    }
};
