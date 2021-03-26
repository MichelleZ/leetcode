#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reorder-data-in-log-files/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters = []
        nums = []
        for log in logs:
            loglist = log.split(' ')
            if loglist[1].isalpha():
                letters.append((' '.join(loglist[1:]), loglist[0]))
            else:
                nums.append(log)
        letters.sort()
        return [letter[1] + ' ' + letter[0] for letter in letters] + nums

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def f(log):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1, )
        return sorted(logs, key=f)
