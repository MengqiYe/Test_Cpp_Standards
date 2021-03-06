# !/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created by Mengqi Ye on 2020/11/4
"""
# Imports
import sys

import cv2
import time
import threading

# Camera settings go here
imageWidth = ...
imageHeight = ...
frameRate = ...
processingThreads = 4

# Shared values
global running
global cap
global frameLock
global processorPool
running = True

# Setup the camera
cap = cv2.VideoCapture(0)
imageWidth = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
imageHeight = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
frameRate = int(cap.get(cv2.CAP_PROP_FPS))
length = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

frameLock = threading.Lock()

print(f"imageWidth : {imageWidth}, imageHeight : {imageHeight}, frameRate : {frameRate}, length : {length}")

if not cap.isOpened():
    cap.open(0)


# Image processing thread, self-starting
class ImageProcessor(threading.Thread):
    def __init__(self, name, autoRun=True):
        super(ImageProcessor, self).__init__()
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
                    self.ProcessImage(self.nextFrame)
                finally:
                    # Reset the event
                    self.nextFrame = None
                    self.event.clear()
                    # Return ourselves to the pool at the back
                    with frameLock:
                        processorPool.insert(0, self)
        print('Processor thread %s terminated' % (self.name))

    def ProcessImage(self, image):
        # Processing for each image goes here
        ### TODO ###
        print(type(image))


# Image capture thread, self-starting
class ImageCapture(threading.Thread):
    def __init__(self):
        super(ImageCapture, self).__init__()
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
                success, frame = cap.read()
                if success:
                    processor.nextFrame = frame
                    processor.event.set()
                else:
                    print('Capture stream lost...')
                    running = False
            else:
                # When the pool is starved we wait a while to allow a processor to finish
                time.sleep(0.01)
        print('Capture thread terminated')


# Create some threads for processing and frame grabbing
processorPool = [ImageProcessor(i + 1) for i in range(processingThreads)]
allProcessors = processorPool[:]
captureThread = ImageCapture()

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
captureThread.join()

# Cleanup the camera object
cap.release()
