#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/incremental-memory-leak/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        for i in range(1, 2 ** 30):
            if max(memory1, memory2) < i:
                return [i, memory1, memory2]
            elif memory1 >= memory2:
                memory1 -= i
            else:
                memory2 -= i
        return None
