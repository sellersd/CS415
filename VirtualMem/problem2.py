########################################################################
# AUTHOR: David Sellers
# TITLE: sum.cpp
# DATE: April 2022
# COURSE: CS 415
# ASSIGNMENT: Assignment 4: Virtual Memory
# DESRCIPTION: Problem 2.
# Simulate virtual memory
########################################################################

from collections import deque

num_frames = 4
pages = [1,0,2,2,1,7,0,1,2,0,3,0,4,5,1,5,2,4,5,6,7,6,2,4,2,7,3,3,2,3]
loaded = deque([])

def fifo(page):
    print('\n' + 34*'*')
    print("********** FIFO swapping **********")
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

def lru(page):
    print('\n' + 34*'*')
    print("********** LRU swapping **********")
    print(34*'*' + '\n')

    print(3*'*', "page : time since last access", 3*'*')
    page_time = {}
    for p in sorted(page):
        page_time[p]=0
    print(page_time)
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
                # find largest time and replace element
                for i in range(3):
                    least = loaded[i]
                    if page_time[loaded[i]] < page_time[loaded[i+1]]:
                        least = loaded[i+1]
                print("Least used: ", least)
                loaded.remove(least)
                loaded.append(p)
        print("Step: ", count, "\t", loaded)

        for key in page_time:
            page_time[key] += 1
        page_time[p] = 0
        print(page_time, '\n')

    hit_ratio =  str(num_faults) + "/" + str(count)
    print("\nNumber of faults: ", num_faults)
    print("Hit ratio: ", hit_ratio)


fifo(pages)
lru(pages)
