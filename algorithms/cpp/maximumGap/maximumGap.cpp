// Source: https://leetcode.com/problems/maximum-gap/
// Author: Miao Zhang
// Date:   2021-01-23

/*************************************************************
 * bucket sort: divide the elements to be sorted into a bucket
 * 1) scan it once, get maxval and minval
 * 2) compute the length of every bucket: each_bucket_len = (max - min) / len(arr) + 1
 * 3) compute the nums of bucket: ((max - min) / each_buckt_len) + 1
 * 4) each element corresponds to the position of the bucket: (ele - min) / each_bucket_len
*************************************************************/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max_gap = 0;
        if (nums.empty() || nums.size() < 2) {
            return max_gap;
        }
        auto mm = std::minmax_element(nums.begin(), nums.end());
        int maxval = *mm.second;
        int minval = *mm.first;
        
        int each_bucket_len = (maxval - minval) / nums.size() + 1;
        int buckets_len = (maxval - minval) / each_bucket_len + 1;
        vector<vector<int>> buckets(buckets_len, vector<int>{});
        for (auto num: nums) {
            int location = (num - minval) / each_bucket_len;
            buckets[location].push_back(num);
        }
        
        int pre_max = INT_MAX;
        for (auto bucket: buckets) {
            if (!bucket.empty() && pre_max != INT_MAX) {
                max_gap = max(max_gap, *min_element(bucket.begin(), bucket.end()) - pre_max);
            }
            if (!bucket.empty()) {
                pre_max = *max_element(bucket.begin(), bucket.end());
            }
        }
        return max_gap;
    }
};
