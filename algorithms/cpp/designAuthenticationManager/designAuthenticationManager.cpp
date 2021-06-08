// Source: https://leetcode.com/problems/design-authentication-manager/
// Author: Miao Zhang
// Date:   2021-06-08

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : ttl_(timeToLive) {

    }

    void generate(string tokenId, int currentTime) {
        clear(currentTime);
        tokens_[tokenId] = currentTime + ttl_;
    }

    void renew(string tokenId, int currentTime) {
        clear(currentTime);
        if (!tokens_.count(tokenId)) return;
        tokens_[tokenId] = currentTime + ttl_;
    }

    int countUnexpiredTokens(int currentTime) {
        clear(currentTime);
        return tokens_.size();
    }

private:
    unordered_map<string, int> tokens_;
    int ttl_;

    void clear(int currentTime) {
        vector<string> ids;
        for (auto& [id, t]: tokens_) {
            if (t <= currentTime) ids.push_back(id);
        }
        for (string& id: ids) {
            tokens_.erase(id);
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
