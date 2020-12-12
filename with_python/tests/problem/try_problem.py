# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/12
"""

import problem

print(type(problem), dir(problem))


class Scope:
    def __init__(self):
        self.pet = None

    def init_pet(self):
        self.pet = problem.Pet("Dreamy", "Golden Retriever")
        self.pet_decoder = problem.Pet_Decoder(self.pet)

    def step(self):
        self.pet_decoder.decode()


if __name__ == '__main__':
    s = Scope()
    s.init_pet()
    s.step()
