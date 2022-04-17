/***********************************
* AUTHOR: David Sellers
* TITLE: main.cpp
* DATE: April 2022
* COURSE: CS 415
* ASSIGNMENT: Barbershop
* DESRCIPTION: Solve the classic barbershop problem using threads.
***********************************/

#include <iostream>
#include <thread>
#include <mutex>

int SEATS = 4;
pthread_t t;
std::mutex barberReady;
std::mutex waitChairs;
int readyCustomers = 0;
int available_seats = SEATS;


int main(int argc, char *arcg[]) {

  waitChairs.lock();
  std::cout << "Hello, World!" << std::endl;

  return 0;
}

void barber() {
  while(true) {
    // check if cust arrived
    // readyCustomers unlocked and >0
    if(readyCustomers > 0) {

    // awake acquire customer chair mutex

    // increment the number of available customer seats
    available_seats++;

    // unlock the barber ready mutex
    barberReady.unlock();
    //unlock the customer chair mutex

    // cut hair for random amount of time
    this_thread::sleep_for(chrono::milliseconds(1000));
    }
  }

}

void customer() {
  while(true) {
      // try to lock the mutex protecting updates to number of chairs
      waitChairs.lock();

      if(available_seats > 0) {
          available_seats--;

          // signal the readyCustomers condtion variable

          // unlock the mutex protecting access to the chairs
          waitChairs.unlock();
          // wait until the barber is ready

          // get hair cut

      }
      else {
        // unlock mutex protecting the chairs
        waitChairs.unlock();
        // leave the barbershop disappointed

      }
  }
}
