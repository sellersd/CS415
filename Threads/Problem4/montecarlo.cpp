/**************************************************************************
* AUTHOR: David Sellers
* TITLE: montecarlo.cpp
* DATE: April 2022
* COURSE: CS 415
* ASSIGNMENT: Assignment 3: Threads
* DESRCIPTION: Problem 4 of assignment 3.
* Implement the Monte Carlo simulation with one thread per quadrant. 
**************************************************************************/
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <random>

using namespace std;

bool inCircle(float x, float y) {
  float d = sqrt((x*x) + (y*y));
  if(d <= 1) {
    return true;
  }
  else {
    return false;
  }
}

void mc(int region, float *value) {

    random_device rd{};
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    double x,y;

    cout << region << '\t' << value << endl;
    int count = 0;
    int num_circle = 0;
    for(int i = 0; i < 10000; i++) {
      if(region == 0) {
          x = dis(gen);
          y = dis(gen);
          if(inCircle(x, y)) {
            num_circle++;
          }
          count++;
      }
      if(region == 1) {
          x = -dis(gen);
          y = dis(gen);
          if(inCircle(x, y)) {
            num_circle++;
          }
          count++;

      }
      if(region == 2) {
          x = -dis(gen);
          y = -dis(gen);
          if(inCircle(x, y)) {
            num_circle++;
          }
          count++;

      }
      if(region == 3) {
          x = dis(gen);
          y = -dis(gen);
          if(inCircle(x, y)) {
            num_circle++;
          }
          count++;

      }
      *value = num_circle / float(count);

  }
}

int main(int argc, char *argv[]) {
  float values[4];
  thread threads[4];
  float total = 0;

  cout << "Hello, World!" << endl;

  for(int i = 0; i < 4; i++) {
    threads[i] = thread(mc, i, &values[i]);
  }

  for(int i = 0; i < 4; i++) {
    threads[i].join();
  }

  for(int i = 0; i < 4; i++) {
    cout << i << '\t' << values[i] << endl;
    total += values[i];
  }

  cout << "pi approximation: " << total << endl;
  return 0;
}
