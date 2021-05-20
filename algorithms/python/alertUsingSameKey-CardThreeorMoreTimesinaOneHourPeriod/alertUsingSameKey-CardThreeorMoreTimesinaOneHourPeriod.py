#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        dic = collections.defaultdict(list)
        for i in range(len(keyName)):
            dic[keyName[i]].append(int(keyTime[i][0: 2]) * 60 + int(keyTime[i][3:]))
        res = []
        for k, v in dic.items():
            v.sort()
            for i in range(2, len(v)):
                if v[i] - v[i - 2] <= 60:
                    res.append(k)
                    break
        res.sort()
        return res
