# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/3
"""
import random
from threading import Thread

import stl
import sys
import time

import cv2
import time
import threading

print(dir(stl))

# Shared values
global running
global cap
global frameLock

global processorPool
running = True

frameLock = threading.Lock()

# Image processing thread, self-starting
class NormalThread(threading.Thread):
    def __init__(self, name, autoRun=True):
        super(NormalThread, self).__init__()
        self.event = threading.Event()
        # self.eventWait = (2.0 * processingThreads) / frameRate
        self.eventWait = .1
        self.name = str(name)
        print('Processor thread %s started with idle time of %.2fs' % (self.name, self.eventWait))
        self.start()

    def run(self):
        # This method runs in a separate thread
        global running
        global frameLock
        global processorPool
        while running:
            # Wait for an image to be written to the stream
            self.event.wait(self.eventWait)
            if self.event.isSet():
                if not running:
                    break
                try:
                    self.gen_normal_distribution(self.next_param)
                finally:
                    # Reset the event
                    self.next_param = None
                    self.event.clear()
                    # Return ourselves to the pool at the back
                    with frameLock:
                        processorPool.insert(0, self)
        print('Processor thread %s terminated' % (self.name))

    def gen_normal_distribution(self, next_param):
        # Processing for each image goes here
        mu, std = next_param
        a = stl.Chromosome([])
        stl.normal(a, 100, mu, std)
        print(a)


class ParamThread(threading.Thread):
    def __init__(self):
        super(ParamThread, self).__init__()
        self.start()

    # Stream delegation loop
    def run(self):
        # This method runs in a separate thread
        global running
        global cap
        global processorPool
        global frameLock
        while running:
            # Grab the oldest unused processor thread
            with frameLock:
                if processorPool:
                    processor = processorPool.pop()
                else:
                    processor = None
            if processor:
                # Grab the next frame and send it to the processor
                epsilon = 1e-6
                rand_mean = random.random()
                rand_std = min(min(random.random(), rand_mean - epsilon), 1 - rand_mean - epsilon) / 3

                processor.next_param = (rand_mean, rand_std)
                processor.event.set()
            else:
                # When the pool is starved we wait a while to allow a processor to finish
                time.sleep(0.01)
        print('Capture thread terminated')


def main_mp(x):
    a = stl.Chromosome([])
    stl.normal(a, 10, 0.5, 0.1)
    print(a)


# Create some threads for processing and frame grabbing
processorPool = [NormalThread(i + 1) for i in range(4)]
allProcessors = processorPool[:]
paramThread = ParamThread()
# Main loop, basically waits until you press CTRL+C
# The captureThread gets the frames and passes them to an unused processing thread
try:
    print('Press CTRL+C to quit')
    while running:
        time.sleep(1)
except KeyboardInterrupt:
    print('\nUser shutdown')
except:
    e = sys.exc_info()
    print()
    print(e)
    print('\nUnexpected error, shutting down!')

# Cleanup all processing threads
running = False
while allProcessors:
    # Get the next running thread
    with frameLock:
        processor = allProcessors.pop()
    # Send an event and wait until it finishes
    processor.event.set()
    processor.join()

# Cleanup the capture thread
paramThread.join()

