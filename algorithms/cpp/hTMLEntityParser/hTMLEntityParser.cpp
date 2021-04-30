// Source: https://leetcode.com/problems/html-entity-parser/
// Author: Miao Zhang
// Date:   2021-04-30

class Solution {
public:
    string entityParser(string text) {
        map<string, string> m{{"&quot;", "\""}, {"&apos;", "'"},
                              {"&amp;", "&"}, {"&gt;", ">"},
                              {"&lt;", "<"}, {"&frasl;", "/"}};
        string res;
        string buf;
        for (char& c: text) {
            buf += c;
            if (buf.back() != ';') continue;
            int buflen = buf.size();
            for (const auto& [k, v]: m) {
                int klen = k.length();
                if (buflen >= klen && buf.substr(buflen - klen) == k) {
                    res += buf.substr(0, buflen - klen) + v;
                    buf.clear();
                    break;
                }
            }
        }
        return res + buf;
    }
};
