#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subarrays-with-k-different-integers/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        
        def subarrays(k):
            cnt = [0] * (len(A) + 1)
            res = 0
            i = 0
            j = 0
            while j < len(A):
                if cnt[A[j]] == 0:
                    k -= 1
                cnt[A[j]] += 1
                while k < 0:
                    cnt[A[i]] -= 1
                    if cnt[A[i]] == 0:
                        k += 1
                    i += 1
                res += j - i + 1
                j += 1
            return res
        
        return subarrays(K) - subarrays(K - 1)
