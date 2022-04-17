########################################################################
# AUTHOR: David Sellers
# TITLE: sum.cpp
# DATE: April 2022
# COURSE: CS 415
# ASSIGNMENT: Assignment 4: Virtual Memory
# DESRCIPTION: Problem 1.
# Simulate virtual memory
########################################################################

from collections import deque

num_frames = 4
pages = ['A','B','D','A','B','C','D','E']
loaded = deque([])

def fifo(page):
    print('\n' + 34*'*')
    print("********* FIFO swapping  *********")
    print("********* with ", num_frames, "frames *********")
    print(34*'*' + '\n')
    num_faults = 0
    count = 0
    for p in page:
        count += 1
        if p in loaded:
            pass
        else:
            num_faults += 1
            print("fault, ", p, "not in ", loaded)
            print("num_faults: ", num_faults)
            if len(loaded) < num_frames:
                loaded.append(p)
            else:
                loaded.popleft()
                loaded.append(p)
        print(loaded)

    hit_ratio =  str(num_faults) + "/" + str(count)
    print("\nNumber of faults: ", num_faults)
    print("Hit ratio: ", hit_ratio)
    while(loaded):
        loaded.popleft()



fifo(pages)
