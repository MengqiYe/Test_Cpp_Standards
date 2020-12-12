# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/12
"""
import ref
print(type(ref), dir(ref))



class ScopeTwo:
    def __init__(self):
        self.dog = None


class Scope:
    def __init__(self):
        self.dog = None

    def init_dog(self):
        self.dog = ref.Dog('Poodle')

    def print(self):
        print(self.dog, s.dog.species())


if __name__ == '__main__':
    s = Scope()
    s.init_dog()
    s.print()

    s2 = ScopeTwo()
    s2.dog = s.dog

    del s
    print(s2.dog.species())