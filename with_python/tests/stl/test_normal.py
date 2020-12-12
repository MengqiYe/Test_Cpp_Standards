# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/3
"""
import stl
print(dir(stl))

a = stl.Chromosome([])
stl.normal(a, 10, 0.5, 0.1)
print(a)