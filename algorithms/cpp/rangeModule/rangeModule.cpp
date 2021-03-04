// Source: https://leetcode.com/problems/range-module/
// Author: Miao Zhang
// Date:   2021-03-03

class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        it l, r;
        getOverlapRanges(left, right, l, r);
        if (l != r) {
            auto last = r;
            --last;
            left = min(left, l->first);
            right = max(right, last->second);
            ranges_.erase(l, r);
        }
        ranges_[left] = right;
    }

    bool queryRange(int left, int right) {
        it l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) return false;
        return l->first <= left && l->second >= right;
    }

    void removeRange(int left, int right) {
        it l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) return;
        auto last = r; --last;
        int start = min(left, l->first);
        int end = max(right, last->second);
        ranges_.erase(l, r);
        if (start < left) ranges_[start] = left;
        if (end > right) ranges_[right] = end;
    }

private:
    typedef map<int, int>::iterator it;
    map<int, int> ranges_;

    void getOverlapRanges(int left, int right, it& l, it& r) {
        l = ranges_.upper_bound(left);
        r = ranges_.upper_bound(right);
        if (l != ranges_.begin()) {
            if ((--l)->second < left) l++;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
