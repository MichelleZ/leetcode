#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/random-pick-with-blacklist/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        self.wlen = N - len(blacklist)
        self.dic = collections.defaultdict(int)
        st = set()
        for i in range(self.wlen, N):
            st.add(i)
        for n in blacklist:
            st.discard(n)
        
        it = iter(st)
        for n in blacklist:
            if n < self.wlen:
                self.dic[n] = next(it)    

    def pick(self) -> int:
        k = random.randint(0, self.wlen - 1)
        return self.dic[k] if k in self.dic else k


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
