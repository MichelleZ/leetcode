#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/online-majority-element-in-subarray/
# Author: Miao Zhang
# Date:   2021-04-13

class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.dic = collections.defaultdict(list)
        for idx, val in enumerate(arr):
            self.dic[val].append(idx)
        self.freq = sorted([(len(idxs), val) for val, idxs in self.dic.items()], reverse=True)

    def query(self, left: int, right: int, threshold: int) -> int:
        for freq, val in self.freq:
            if freq < threshold: break
            idxs = self.dic[val]
            low = bisect.bisect_left(idxs, left)
            high = bisect.bisect_right(idxs, right)
            if high - low >= threshold:
                return val
        return -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
