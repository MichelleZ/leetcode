#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/making-file-names-unique/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        res = []
        m = collections.defaultdict(int)
        for name in names:
            uniquename = name
            i = m[name]
            if i > 0:
                uniquename = name + '(' + str(i) + ')'
                while uniquename in m:
                    i += 1
                    uniquename = name + '(' + str(i) + ')'
                m[name] = i
            m[uniquename] = 1
            res.append(uniquename)
        return res
