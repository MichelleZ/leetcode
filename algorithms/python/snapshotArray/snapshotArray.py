#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/snapshot-array/
# Author: Miao Zhang
# Date:   2021-04-13

class SnapshotArray:

    def __init__(self, length: int):
        self.id = 0
        self.vals = [{0 : 0} for _ in range(length)]

    def set(self, index: int, val: int) -> None:
        self.vals[index][self.id] = val

    def snap(self) -> int:
        self.id += 1
        return self.id - 1

    def get(self, index: int, snap_id: int) -> int:
        dic = self.vals[index]
        k = list(dic.keys())
        i = bisect.bisect_right(k, snap_id)
        if i == 0: return 0
        return dic[k[i - 1]]

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
