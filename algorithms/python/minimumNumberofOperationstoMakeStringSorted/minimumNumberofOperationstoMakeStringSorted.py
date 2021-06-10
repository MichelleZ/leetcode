#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def makeStringSorted(self, s: str) -> int:
        kMod = 10 ** 9 + 7
        n = len(s)
        def power(base, exp):
            nonlocal kMod
            res = 1
            while exp:
                if exp & 1: res = (res * base) % kMod
                base = (base * base) % kMod
                exp >>= 1
            return res

        fact = [1 for _ in range(n + 1)]
        inv = [1 for _ in range(n + 1)]
        for i in range(1, n + 1):
            fact[i] = (fact[i - 1] * i) % kMod
            inv[i] = power(fact[i], kMod - 2)
        res = 0
        freq = [0 for _ in range(26)]
        for c in s: freq[ord(c) - ord('a')] += 1
        for i in range(n - 1):
            rank = 0
            for j in range(ord(s[i]) - ord('a')):
                rank += freq[j]
            cur = rank * fact[n - 1 - i] % kMod
            for j in range(26):
                cur = cur * inv[freq[j]] % kMod
            res = (res + cur) % kMod
            freq[ord(s[i]) - ord('a')] -= 1
        return res

