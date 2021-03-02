#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stickers-to-spell-word/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        cnt = collections.Counter(target)
        st = [collections.Counter(s) & cnt for s in stickers]
        for i in range(len(st) - 1, -1, -1):
            if any(st[i] & st[i] == st[j] for j in range(len(st)) if i != j):
                st.pop(i)
        stickers = [''.join(s.elements()) for s in st]
        print(stickers)

        dp = [-1] * (1 << len(target))
        dp[0] = 0
        for state in range(1 << len(target)):
            if dp[state] == -1: continue
            for sticker in stickers:
                now = state
                for s in sticker:
                    for i, c in enumerate(target):
                        if (now >> i) & 1: continue
                        if c == s:
                            now |= 1 << i
                            break
                if dp[now] == -1 or dp[now] > dp[state] + 1:
                    dp[now] = dp[state] + 1
        return dp[-1]
