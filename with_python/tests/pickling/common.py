# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi.Ye on 2020/12/7
"""
import pickle
from os import mkdir
from os.path import join, exists

PICKLE_DIR = './w_pickle/'


def check_dir():
    if not exists(PICKLE_DIR):
        mkdir(PICKLE_DIR)


def save(name, obj):
    check_dir()
    picklefile = open(join(PICKLE_DIR, str(name) + '.pickle'), 'wb')
    pickle.dump(obj, picklefile)
    picklefile.close()


def load(name):
    check_dir()
    picklefile = open(join(PICKLE_DIR, str(name) + '.pickle'), 'rb')
    o = pickle.load(picklefile)
    picklefile.close()
    return o


def save_load(obj, name=''):
    try:
        save(name, obj)
        o = load(name)
    except Exception as e:
        print(type(obj), e)
        return

    print(f"Successfully pickled {name}")
