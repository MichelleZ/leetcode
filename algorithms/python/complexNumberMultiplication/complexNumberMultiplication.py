#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/complex-number-multiplication/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        m = a
        n = b
        m=m.replace('i','j')
        n=n.replace('i','j')
        res=complex(eval(m))*complex(eval(n))
        return (str(int(res.real))+'+'+str(int(res.imag))+'i')
