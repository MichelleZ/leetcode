// Source: https://leetcode.com/problems/fancy-sequence/
// Author: Miao Zhang
// Date:   2021-05-24

class Fancy {
public:
    Fancy(): a(1), b(0) {

    }

    int fastModularExpo(int a, int n) {
        if (n == 0)
            return 1;
        else if (n & 1) {
            return fastModularExpo(a, n - 1) * a;
        } else {
            int tmp = fastModularExpo(a, n / 2);
            return (long long)tmp * tmp;
        }
    }

    int multiInverse(int x) {
        return fastModularExpo(x, kMod - 2);
    }

    void append(int val) {
        vals.push_back((long long) ((val - b + kMod) % kMod) * multiInverse(a) % kMod);
    }

    void addAll(int inc) {
        b = (b + inc) % kMod;
    }

    void multAll(int m) {
        a = (long long) a * m % kMod;
        b = (long long) b * m % kMod;
    }

    int getIndex(int idx) {
        if (idx >= vals.size()) {
            return -1;
        }
        cout << "getIndx" << endl;
        for (auto v: vals) cout << v << endl;
        int res = ((long long) a * vals[idx] % kMod + b) % kMod;
        return res;
    }

private:
    int kMod = 1e9 + 7;
    vector<int> vals;
    int a, b;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
