#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/contains-duplicate-iii/
# Author: Miao Zhang
# Date:   2021-01-27

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if k < 1 or t < 0: return False
        dic = collections.OrderedDict()
        for num in nums:
            key = num if not t else num // t
            for val in (dic.get(key - 1), dic.get(key), dic.get(key + 1)):
                if val is not None and abs(num - val) <= t:
                    return True
            if len(dic) == k:
                dic.popitem(last=False)
            dic[key] = num
        return False
