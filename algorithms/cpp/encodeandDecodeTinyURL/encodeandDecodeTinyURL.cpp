// Source: https://leetcode.com/problems/encode-and-decode-tinyurl/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)) {
            return "http://tinyurl.com/" + long2short[longUrl];
        }

        string randstr;
        for (int i = 0; i < 6; i++) randstr.push_back(dict[rand() % 62]);
        int idx = 0;
        while (short2long.count(randstr)) {
            randstr[idx] = dict[rand() % 62];
            idx = (idx + 1) % 6;
        }
        short2long[randstr] = longUrl;
        long2short[longUrl] = randstr;
        return "http://tinyurl.com/" + randstr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randstr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randstr) ? short2long[randstr] : shortUrl;
    }

private:
    unordered_map<string, string> short2long, long2short;
    string dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
