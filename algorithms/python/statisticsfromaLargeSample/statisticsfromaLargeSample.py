#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/statistics-from-a-large-sample/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        import bisect
        minval = 255
        maxval = 0
        mode = -1
        modecnt = 0
        sums = 0
        m = collections.defaultdict(int)
        cnt = 0
        for i in range(256):
            if not count[i]: continue
            minval = min(minval, i)
            maxval = max(maxval, i)
            sums += i * count[i]
            if count[i] > modecnt:
                mode = i
                modecnt = count[i]
            cnt += count[i]
            m[cnt] = i
        keys = sorted(m)
        idx = bisect.bisect_left(keys, (cnt + 1) // 2)
        median = m[keys[idx]]
        if cnt % 2 == 0 and idx + 1 != len(keys) and keys[idx] == cnt // 2:
            median = (median + m[keys[idx + 1]]) / 2
        return [minval, maxval, sums / cnt, median, mode]
