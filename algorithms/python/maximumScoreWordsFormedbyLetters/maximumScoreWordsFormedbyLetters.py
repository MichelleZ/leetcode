#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        cnt = collections.Counter(letters)
        scores = [0] * len(words)
        for i, w in enumerate(words):
            for c in w:
                scores[i] += score[ord(c) - ord('a')]
        res = 0

        def dfs(start, cur):
            nonlocal res
            res = max(res, cur)
            for i in range(start, len(words)):
                valid = True
                for c in words[i]:
                    cnt[c] -= 1
                    valid &= cnt[c] >= 0
                if valid:
                    dfs(i + 1, cur + scores[i])
                for c in words[i]:
                    cnt[c] += 1

        dfs(0, 0)
        return res
