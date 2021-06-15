// Source: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
// Author: Miao Zhang
// Date:   2021-06-15

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num: nums2) {
            cnt[num]++;
        }
    }

    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int num: nums1) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                res += cnt[rest];
            }
        }
        return res;
    }

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
