#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lemonade-change/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives = 0
        tens = 0
        for bill in bills:
            if bill == 5:
                fives += 1
            elif bill == 10:
                if not fives: return False
                tens += 1
                fives -= 1
            elif bill == 20:
                if fives and tens:
                    fives -= 1
                    tens -= 1
                elif fives >= 3:
                    fives -= 3
                else: return False
        return True
