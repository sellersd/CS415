#include <thread>
#include <semaphore>
#include <iostream>
#include <fstream>
#include <deque>
#include <random>
#include <sstream>
#include <chrono>
#include <string>
#include <typeinfo>

using namespace std;

// Global variables
deque<string> inputQueue;
const int SAMPLE_ARRIVAL_RATE = 3;
  string files[10] = {"sensor0.txt",
                      "sensor1.txt",
                      "sensor2.txt",
                      "sensor3.txt",
                      "sensor4.txt",
                      "sensor5.txt",
                      "sensor6.txt",
                      "sensor7.txt",
                      "sensor8.txt",
                      "sensor9.txt"};

// Instructor provided code to simulate input
void simulateInput(int rate)
{
  random_device rd{};
  mt19937 gen{rd()};

  poisson_distribution<> pD(rate);
  normal_distribution<> nD(75.0, 15.0);
  uniform_int_distribution<int> uD(0,9);

  while(true)
  {
    int numberEvents = pD(gen);
    if (numberEvents > 0)
    {
      for (int i = 0; i < numberEvents; ++i)
      {
        stringstream sampleStream;
        int deviceNumber = uD(gen);
        float sample = nD(gen);
        sampleStream << deviceNumber << " " << sample;
        inputQueue.push_back(sampleStream.str());
      }
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}

// Functions for threads to write input to file
void write() {

}

// Function for threads to read from deque
void read(int n) {
  while(true) {
    cout << endl;
    cout << "in read" << endl;
    // lock inputQueue
    if(!inputQueue.empty()) {
      cout << "Front is: " << inputQueue.front() << endl;
      cout << "Front[0] is: " << inputQueue.front()[0] << endl;
      cout << "Front substr is: " << inputQueue.front().substr(1) << endl;
      cout << "n: " << n << endl;
      cout << "Front[0] == n: " << (((int)inputQueue.front()[0] - 48) == n) << endl;
      bool match  = (((int)inputQueue.front()[0] - 48) == n);
      if(match) {
        cout << "Found a reading!" << endl;


        ofstream ofile;
        ofile.open(files[n]);
        cout << "Writing to file " << n << endl;
        ofile << inputQueue.front().substr(1);
        ofile.close();
        inputQueue.pop_front();
      }
    this_thread::sleep_for(chrono::milliseconds(1000));
    }
    // unlock inputQueue
  }
}

int main(int argc, char *argv[]) {

  thread threads[10];
  for(int i = 0; i < 10; i++){
    ofstream ofile;
    ofile.open(files[i]);
    ofile.close();
  }
  inputQueue.push_front("0 START");
  // Build and lanuch the input simulator thread
  thread inputThread(simulateInput, SAMPLE_ARRIVAL_RATE);
  inputThread.detach();
  // Pause three seconds
  for(int i = 0; i < 10; i++) {

    threads[i] = thread(read, i);
    threads[i].join();
  }

  cout << "Pausing three seconds for station identification" << endl;
  this_thread::sleep_for(chrono::milliseconds(3000));
  // Now start printing stuff from the queue
  while(true)
  {
    cout << "Items in queue:\t" << inputQueue.size() << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    // if (! inputQueue.empty())
    // {
    //   string sample = inputQueue.back();
    //   inputQueue.pop_back();
    //   cout << sample << endl;
    // }
  }

  return 0;
}
