#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n = len(students)
        cnt = [0] * 2
        for i in range(n):
            cnt[students[i]] += 1
        for i in range(n):
            cnt[sandwiches[i]] -= 1
            if cnt[sandwiches[i]] < 0:
                return n - i
        return 0
