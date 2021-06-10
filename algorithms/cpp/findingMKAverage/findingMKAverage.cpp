// Source: https://leetcode.com/problems/finding-mk-average/
// Author: Miao Zhang
// Date:   2021-06-10

class MKAverage {
public:
    MKAverage(int m, int k) : m(m), k(k), n(m - 2 * k), sums(0) {

    }

    void addElement(int num) {
        if (q.size() == m) {
            remove(q.front());
            q.pop();
        }
        q.push(num);
        add(num);
    }

    int calculateMKAverage() {
        return (q.size() < m) ? -1 : sums / n;
    }

private:
    void add(int x) {
        left.insert(x);
        if (left.size() > k) {
            auto it = prev(end(left));
            sums += *it;
            mid.insert(*it);
            left.erase(it);
        }
        if (mid.size() > n) {
            auto it = prev(end(mid));
            sums -= *it;
            right.insert(*it);
            mid.erase(it);
        }
    }

    void remove(int x) {
        if (x <= *rbegin(left)) {
            left.erase(left.find(x));
        } else if (x <= *rbegin(mid)) {
            sums -= x;
            mid.erase(mid.find(x));
        } else {
            right.erase(right.find(x));
        }
        if (left.size() < k) {
            auto it = begin(mid);
            sums -= *it;
            left.insert(*it);
            mid.erase(it);
        }
        if (mid.size() < n) {
            auto it = begin(right);
            sums += *it;
            mid.insert(*it);
            right.erase(it);
        }
    }

    queue<int> q;
    multiset<int> left, mid, right;
    long sums;
    const int m;
    const int k;
    const int n;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
