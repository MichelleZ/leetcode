#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/camelcase-matching/
# Author: Miao Zhang
# Date:   2021-04-03

class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        pattern = '[a-z]*' + '[a-z]*'.join(list(pattern)) + '[a-z]*'
        return [re.match(f'^{pattern}$',s) for s in queries]

