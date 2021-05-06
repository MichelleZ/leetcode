#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        foods = set()
        tables = set()
        for order in orders:
            foods.add(order[2])
            tables.add(int(order[1]))
        foods = sorted(foods)
        tables = sorted(tables)
        table2id = {table: i for i, table in enumerate(tables)}
        foods2id = {food: i for i, food in enumerate(foods)}

        info_int = [[table] + [0] * len(foods) for table in tables]
        for order in orders:
            foodid = foods2id[order[2]]
            tableid = table2id[int(order[1])]
            info_int[tableid][foodid + 1] += 1

        headlines = ["Table"] + foods
        res = [headlines]
        for line in info_int:
            res.append([str(x) for x in line])
        return res
