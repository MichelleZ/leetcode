#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sentence-similarity-iii/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        w1 = deque(sentence1.split())
        w2 = deque(sentence2.split())
        while w1 and w2 and w1[0] == w2[0]:
            w1.popleft()
            w2.popleft()
        while w1 and w2 and w1[-1] == w2[-1]:
            w1.pop()
            w2.pop()
        return len(w1) * len(w2) == 0

