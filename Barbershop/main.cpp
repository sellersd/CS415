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

    // awake acquire customer chair mutex

    // increment the number of available customer seats

    // unlock the barber ready mutex

    //unlock the customer chair mutex

    // cut hair for random amount of time
  }

}

void customer() {
  while(true) {
      // try to lock the mutex protecting updates to number of chairs

      if(available_seats > 0) {
          available_seats--;

          // signal the readyCustomers condtion variable

          // unlock the mutex protecting access to the chairs

          // wait until the barber is ready

          // get hair cut

      }
      else {
        // unlock mutex protecting the chairs

        // leave the barbershop disappointed

      }
  }
}
