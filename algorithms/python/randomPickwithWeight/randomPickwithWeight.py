#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/random-pick-with-weight/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:

    def __init__(self, w: List[int]):
        self.sums = list(itertools.accumulate(w))

    def pickIndex(self) -> int:
        return bisect.bisect_left(self.sums, random.randint(1, self.sums[-1]))


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
