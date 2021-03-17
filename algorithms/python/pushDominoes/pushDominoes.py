#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/push-dominoes/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        l = [float('inf')] * n
        r = [float('inf')] * n
        for i in range(n):
            if dominoes[i] == 'L':
                l[i] = 0
                j = i - 1
                while j >= 0 and dominoes[j] == '.':
                    l[j] = l[j + 1] + 1
                    j -= 1
            elif dominoes[i] == 'R':
                r[i] = 0
                j = i + 1
                while j < n and dominoes[j] == '.':
                    r[j] = r[j - 1] + 1
                    j += 1
        d = list(dominoes)
        for i in range(n):
            if l[i] < r[i]: d[i] = 'L'
            elif l[i] > r[i]: d[i] = 'R'
        return ''.join(d)
