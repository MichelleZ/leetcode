#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/time-based-key-value-store/
# Author: Miao Zhang
# Date:   2021-03-30

from bisect import bisect_right
class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dic[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        val = self.dic.get(key, None)
        if val is None: return ''
        i = bisect.bisect_right(val, (timestamp, chr(127)))
        return val[i - 1][-1] if i else ''


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
