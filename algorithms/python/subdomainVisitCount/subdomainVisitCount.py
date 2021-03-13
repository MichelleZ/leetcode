#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subdomain-visit-count/
# Author: Miao Zhang
# Date:   2021-03-13

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counter = collections.defaultdict(int)
        for cpdomain in cpdomains:
            cnt, domain = cpdomain.split(' ')
            while True:
                counter[domain] += int(cnt)
                if '.' in domain:
                    i = domain.index('.')
                else: break
                domain = domain[i + 1:]
        res = []
        for k, v in counter.items():
            res.append(str(v) + ' ' + k)
        return res
