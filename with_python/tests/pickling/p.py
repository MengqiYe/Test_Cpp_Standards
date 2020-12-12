# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/12/7
"""
import pickling

print(dir(pickling))

initial_AVec = pickling.AVec([0 for i in range(58)])
initial_AVec_vec = pickling.AVecVec([initial_AVec])
initial_tparam_vec = pickling.TParamVec([(1. * x, 2. * x) for x in range(10)])

pickling.PrintTParamVec(initial_tparam_vec)
