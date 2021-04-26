// Source: https://leetcode.com/problems/tweet-counts-per-frequency/
// Author: Miao Zhang
// Date:   2021-04-26

class TweetCounts {
public:
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) {
        record[tweetName][time]++;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int f = 1;
        if (freq == "minute") {
            f *= 60;
        } else if (freq == "hour") {
            f *= 60 * 60;
        } else {
            f *= 60 * 60 * 24;
        }

        vector<int> res;
        int t = startTime;
        while (t <= endTime) {
            auto begin = record[tweetName].lower_bound(t);
            auto end = record[tweetName].upper_bound(min(t + f - 1, endTime));
            int cnt = 0;
            for (auto it = begin; it != end; it++) {
                cnt += it->second;
            }
            res.push_back(cnt);
            t += f;
        }
        return res;
    }

private:
    unordered_map<string, map<int, int>> record;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
