// Source: https://leetcode.com/problems/online-election/
// Author: Miao Zhang
// Date:   2021-03-24

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> votes(persons.size() + 1);
        int last_lead = persons.front();
        for (int i = 0; i < persons.size(); i++) {
            if (++votes[persons[i]] >= votes[last_lead]) {
                last_lead = persons[i];
            }
            leads_[times[i]] = last_lead;
        }
    }

    int q(int t) {
        return prev(leads_.upper_bound(t))->second;
    }
private:
    map<int, int> leads_; // time->lead
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
