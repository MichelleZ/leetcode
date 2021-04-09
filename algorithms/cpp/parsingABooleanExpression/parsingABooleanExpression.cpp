// Source: https://leetcode.com/problems/parsing-a-boolean-expression/
// Author: Miao Zhang
// Date:   2021-04-09

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int s = 0;
        return parse(expression, s);
    }

private:
    bool parse(string& expression, int& s) {
        char ch = expression[s++];
        if (ch == 'f') return false;
        if (ch == 't') return true;
        if (ch == '!') {
            bool res = !parse(expression, ++s);
            ++s;
            return res;
        }
        bool isand = (ch == '&');
        bool res = isand;
        ++s;
        while (true) {
            if (isand) res &= parse(expression, s);
            else res |= parse(expression, s);
            if (expression[s++] == ')') break;
        }
        return res;
    }
};
