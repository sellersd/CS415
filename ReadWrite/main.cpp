#include <thread>
#include <semaphore>
#include <iostream>
#include <deque>
#include <random>
#include <sstream>
#include <chrono>


using namespace std;

// Global variables
deque<string> inputQueue;
const int SAMPLE_ARRIVAL_RATE = 3;

// Instructor provided code to simulate input
void simulateInput(int rate)
{
  random_device rd{};
  mt19937 gen{rd()};
  int count = 0;

  poisson_distribution<> pD(rate);
  normal_distribution<> nD(5.0, 3.0);
  uniform_int_distribution<int> uD(0,10);

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
        count++;
        sampleStream << count << " " << deviceNumber << " " << sample;
        inputQueue.push_front(sampleStream.str());
      }
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}

// Functions for threads to write input to file
void write() {

}

// Function for threads to read from deque
void read() {

}

int main(int argc, char *argv[]) {

  inputQueue.push_front("0 START");
  // Build and lanuch the input simulator thread
  thread inputThread(simulateInput, SAMPLE_ARRIVAL_RATE);
  inputThread.detach();
  // Pause three seconds
  cout << "Pausing three seconds for station identification" << endl;
  this_thread::sleep_for(chrono::milliseconds(3000));
  // Now start printing stuff from the queue
  while(true)
  {
    if (! inputQueue.empty())
    {
      string sample = inputQueue.back();
      inputQueue.pop_back();
      cout << sample << endl;
    }
  }

  return 0;
}
