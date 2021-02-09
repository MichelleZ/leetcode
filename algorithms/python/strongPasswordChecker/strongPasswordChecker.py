#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/strong-password-checker/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        res = 0
        n = len(password)
        lower = 1
        upper = 1
        digit = 1
        v = [0] * n
        i = 0
        while i < n:
            if password[i] >= 'a' and password[i] <= 'z': lower = 0
            if password[i] >= 'A' and password[i] <= 'Z': upper = 0
            if password[i] >= '0' and password[i] <= '9': digit = 0
            j = i
            while i < n and password[i] == password[j]: i+= 1
            v[j] = i - j
        missing = (lower + upper + digit)
        if n < 6:
            diff = 6 - n
            res += diff + max(0, missing - diff)
        else:
            over = max(n - 20, 0)
            left = 0
            res += over
            for k in range(1, 3):
                if over > 0:
                    for i in range(n):
                        if v[i] < 3 or v[i] % 3 != (k - 1): continue
                        v[i] -= min(over, k);
                        over -= k;
            for i in range(n):
                if v[i] >= 3 and over > 0:
                    need = v[i] - 2
                    v[i] -= over
                    over -= need
                if v[i] >= 3: left += v[i] // 3
            res += max(missing, left);
        return res
