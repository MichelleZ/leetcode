#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/student-attendance-record-i/
# Author: Miao Zhang
# Date:   2021-02-21

class Solution:
    def checkRecord(self, s: str) -> bool:
        return not re.match(".*A.*A.*|.*LLL.*", s)
