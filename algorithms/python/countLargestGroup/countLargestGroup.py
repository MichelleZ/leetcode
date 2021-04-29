#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-largest-group/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def countLargestGroup(self, n: int) -> int:
        cnt = collections.Counter()
        for i in range(1, n + 1):
            sums = 0
            x = i
            while x:
                sums += x % 10
                x //= 10
            cnt[sums] += 1
        res = 0
        cnt = cnt.most_common()
        for k, v in cnt:
            if v == cnt[0][1]:
                res += 1
            else:
                break
        return res
