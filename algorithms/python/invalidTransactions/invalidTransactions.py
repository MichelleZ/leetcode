#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/invalid-transactions/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        dic = collections.defaultdict(list)
        for i, t in enumerate(transactions):
            name, time, amount, city = t.split(',')
            dic[name].append([name, int(time), int(amount), city, i])
        
        data = set()
        for name, item in dic.items():
            curitem = sorted(item, key = lambda x: x[1])
            for i in range(len(curitem)):
                if curitem[i][2] > 1000:
                    data.add(curitem[i][4])
                for j in range(i + 1, len(curitem)):
                    if abs(curitem[j][1] - curitem[i][1]) > 60:
                        break
                    if curitem[j][3] != curitem[i][3]:
                        data.add(curitem[j][4])
                        data.add(curitem[i][4])
        return [transactions[i] for i in data]
