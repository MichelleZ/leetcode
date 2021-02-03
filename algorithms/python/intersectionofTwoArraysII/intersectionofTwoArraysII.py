#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/intersection-of-two-arrays-ii/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> count;    
    vector<int> ans;
    for (int num : nums1)
      ++count[num];
    for (int num : nums2)
      if (count.count(num) &&count[num] > 0) {
        --count[num];
        ans.push_back(num);
      }
    return ans;
  }
};
