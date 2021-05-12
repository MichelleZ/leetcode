#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reformat-date/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def reformatDate(self, date: str) -> str:
        dic = {"Jan": "01", "Feb": "02", "Mar": "03", 
               "Apr": "04", "May": "05", "Jun": "06", 
               "Jul": "07", "Aug": "08", "Sep": "09", 
               "Oct": "10", "Nov": "11", "Dec": "12"}
        datelist = date.split()
        day = datelist[0][:-2]
        if len(day) == 1:
            day = '0' + day
        return datelist[2] + '-' + dic[datelist[1]] + '-' + day
