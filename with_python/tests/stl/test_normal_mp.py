# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/3
"""
from multiprocessing import Pool, cpu_count

import stl
print(dir(stl))

def main_mp(x):
    a = stl.Chromosome([])
    stl.normal(a, 10, 0.5, 0.1)
    print(a)


def main():
    a = stl.Chromosome([])
    stl.normal(a, 10, 0.5, 0.1)

    with Pool(cpu_count() - 10) as pool:
        pool.map(
            main_mp,
            [x for x in range(100)]
        )


if __name__ == '__main__':
    main()