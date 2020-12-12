# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/12/7
"""
import pickling

print(dir(pickling))

initial_chromosome = pickling.Chromosome([0 for i in range(58)])
initial_chromosome_vec = pickling.ChromosomeVector([initial_chromosome])
initial_chromosome_param_vec = [(1. * _, 2. * _)for _ in range(10)]

pickling.PrintChromosomeParamVector(initial_chromosome_param_vec)