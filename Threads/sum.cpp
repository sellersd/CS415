#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

void arrayAverage(int *dataset1, int *dataset2, int *resultset, int size) {
  return;
}

int main(int argc, char *argv[]) {

  srand(12345);

  int SIZE = 100;
  int NUM_THREADS = 8;
  int dataset1[SIZE] = {};
  int dataset2[SIZE] = {};
  int resultset[SIZE] = {};


  for(int i = 0; i < 100; i++) {
      dataset1[i] = rand() % 10;
      dataset2[i] = rand() % 10;
  }
  for(int i = 0; i < 100; i++) {
      cout << dataset1[i] << '\t' << dataset2[i] << endl;
  }

}
