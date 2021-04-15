#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        
        def freq(s: str) -> int:
            cnt = collections.Counter(s)
            return cnt[min(cnt.keys())]
        
        wcnt = sorted(list(map(freq, words)))
        qcnt = list(map(freq, queries))
        
        res = []
        for q in qcnt:
            idx = bisect.bisect_right(wcnt, q)
            res.append(len(wcnt) - idx)
        return res
