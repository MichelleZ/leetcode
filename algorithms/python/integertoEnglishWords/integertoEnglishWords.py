#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/integer-to-english-words/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def numberToWords(self, num: int) -> str:
        '''
        num = 1234567
        nums = [567, 234, 1]
        1 million 234 thousand 567
        '''
        if num == 0:
            return 'Zero'
        nums = []
        res = []
        levels = ['', 'Thousand ', 'Million ', 'Billion ']
        while num > 0:
            nums.append(num % 1000)
            num //= 1000
        for i in range(len(nums)):
            cur = self.convert(nums[i])
            if nums[i] != 0:
                cur += levels[i]
            res.append(cur)
        return ''.join(reversed(res)).rstrip(' ')
    
    def convert(self, n: int) -> str:
        less_than_20 = ['Zero', 'One ', 'Two ', 'Three ', 'Four ', 'Five ', 
                        'Six ', 'Seven ', 'Eight ', 'Nine ', 'Ten ', 
                        'Eleven ', 'Twelve ', 'Thirteen ', 'Fourteen ', 
                        'Fifteen ', 'Sixteen ', 'Seventeen ', 
                        'Eighteen ', 'Nineteen ']
        less_than_100 = ['Twenty ', 'Thirty ', 'Forty ', 'Fifty ', 
                         'Sixty ', 'Seventy ', 'Eighty ', 'Ninety ']
        
        cur = ''
        if n == 0:
            return ''
        if n < 20:
            cur += less_than_20[n]
        elif n < 100:
            cur += less_than_100[n // 10 - 2]
            cur += self.convert(n % 10)
        else:
            cur += less_than_20[n // 100] + 'Hundred '
            cur += self.convert(n % 100)
        return cur
