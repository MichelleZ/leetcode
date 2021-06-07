#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-items-matching-a-rule/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        dic = {"type": 0, "color": 1, "name": 2}
        return sum(item[dic[ruleKey]] == ruleValue for item in items)
