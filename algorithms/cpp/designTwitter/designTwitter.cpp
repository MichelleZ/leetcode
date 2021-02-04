// Source: https://leetcode.com/problems/design-twitter/
// Author: Miao Zhang
// Date:   2021-02-04

const size_t MaxTweets = 10;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto& tweets = user_tweets_[userId];
        if (tweets.size() == MaxTweets) {
            tweets.pop_front();
        }
        tweets.emplace_back(++time, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed(begin(user_tweets_[userId]), end(user_tweets_[userId]));
        for (int uid: user_followers_[userId]) {
            feed.insert(end(feed), 
                        begin(user_tweets_[uid]),
                        end(user_tweets_[uid]));
        }
        sort(rbegin(feed), rend(feed));
        vector<int> res;
        for (int i = 0; i < min(MaxTweets, feed.size()); i++) {
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followers_[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followers_[followerId].erase(followeeId);
    }

private:
    int time;
    unordered_map<int, deque<pair<int, int>>> user_tweets_;
    unordered_map<int, set<int>> user_followers_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
