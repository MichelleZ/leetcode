// Source: https://leetcode.com/problems/validate-ip-address/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    string validIPAddress(string IP) {
        bool isIPv4 = true;
        bool isIPv6 = true;
        string cur;
        int seg = 0;
        for (char c: IP) {
            if (c == '.') {
                seg++;
                isIPv6 = false;
                isIPv4 &= isV4(cur);
                cur.clear();
            } else if (c == ':') {
                seg++;
                isIPv4 = false;
                isIPv6 &= isV6(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }
        isIPv4 &= isV4(cur) && seg == 3;
        isIPv6 &= isV6(cur) && seg == 7;
        return isIPv4 ? "IPv4" : (isIPv6 ? "IPv6" : "Neither");
    }

private:
    bool isV4(string n) {
        if (n.length() > 3 || n.empty()) return false;
        if (n[0] == '0' && n.size() > 1) return false;
        int a = 0;
        for (char c: n) {
            if (!isdigit(c)) return false;
            a = a * 10 + c - '0';
        }
        return a >= 0 && a <= 255;
    }

    bool isV6(string n) {
        if (n.length() > 4 || n.empty()) return false;
        std::reverse(n.begin(), n.end());
        int a = 0;
        int f = 1;
        for (char c : n) {
            if (isdigit(c))
                a += (c - '0') * f;
            else if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'Z')
                a += (tolower(c) - 'a' + 10) * f;
            else
                return false;
            f *= 16;
        }
        return a >= 0 && a < (1 << 16);
    }
};
