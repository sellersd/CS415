/***********************************
* AUTHOR: David Sellers
* TITLE: sum.cpp
* DATE: April 2022
* COURSE: CS 415
* ASSIGNMENT: Assignment 3: Threads
* DESRCIPTION: Problem 3 of assignment 3. Create a multithreaded program
* that will sum corresponding entries in two arrays and store the results
* in a third array.
***********************************/
#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

// constants
const int SIZE = 100000;
int NUM_THREADS = 8;

// initialize arrays
int dataset1[SIZE] = {};
int dataset2[SIZE] = {};
int resultset[SIZE] = {};

int total = 0;


void arrayAverage(int *dataset1, int *dataset2, int *resultset, int size) {
  cout << "In arrayAverage" << endl;
  int sum = 0;
  for(int i = 0; i < size; i++) {
    // cout << "dataset1 " << i << "\t" << dataset1[i] << endl;
    resultset[i] = dataset1[i] + dataset2[i];

  }
}

void testFunction(int n) {
  cout << "this is thread " << n << endl;
  cout << "dataset1 " << n << "\t" << dataset1[n] << endl;
}

int main(int argc, char *argv[]) {

  // random number gen
  srand(12345);


  // initialize arrays
  thread threads[NUM_THREADS]; // holds threads

  // size computation
  int block_size = SIZE / NUM_THREADS + 1;
  cout << block_size << endl;
  // random values in arrays
  for(int i = 0; i < SIZE; i++) {
      dataset1[i] = rand() % 10;
      dataset2[i] = rand() % 10;
  }

  // create NUM_THREADS threads
  for(int i = 0; i < NUM_THREADS; i++) {

    // threads[i] = thread(testFunction, i);
    if(i < (NUM_THREADS -1)) {
      threads[i] = thread(arrayAverage, &dataset1[block_size * i], &dataset2[block_size * i], &resultset[block_size * i], block_size);
    }
    else {
      threads[i] = thread(arrayAverage, &dataset1[block_size * i], &dataset2[block_size * i], &resultset[block_size * i], SIZE - (i * block_size));
    }
  }

  // join threads
  for(int i = 0; i < NUM_THREADS; i++) {
    threads[i].join();
  }

  for(int i = 0; i < SIZE; i++) {
    if(i % 500 == 0) {
      cout << "index " << i << "  " << dataset1[i] << " + " << dataset2[i] << " = " << resultset[i] << endl;
    }
  }

  //test if generalization of block_size worked
  // and includes the last index
      cout << "index " << SIZE-1 << "  " << dataset1[SIZE-1] << " + " << dataset2[SIZE-1] << " = " << resultset[SIZE-1] << endl;


}
