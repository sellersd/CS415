#include <sys/types.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cstring>
// #include "../Parser/parser.cpp"

using namespace std;

struct arguments {
  int argc;
  char *argv[];
};

char ** parseCommandLine(string CommandLine) {

    const int MAX_TOKENS = 10;
    char ** ptr_arr[MAX_TOKENS];


    int count = 0;
    char delimiters[] = {'<', '>', '|', ' '};

    // inspiration from
    // https://www.tutorialspoint.com/cpp_standard_library/cpp_string_c_str.htm
    // fixes error converting from const char * to char *

    char * c = new char[CommandLine.length()+1];
    strcpy(c, CommandLine.c_str());

    // https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
    char * ptr = strtok(c, " ><|") ;

    // Loop until entire string parsed or
    // reached the size of the array
    while(ptr != NULL && count < MAX_TOKENS) {

      // app pointer to token in array
      ptr_arr[count] = &ptr;
      cout << "ptr_arr deref " << count << ": "<< *ptr_arr[count] << endl;

      // If NULL is passed, continue working on the previous input
      ptr = strtok(NULL, delimiters);

      count++;
    }

    cout << "contents of ptr_arr: " << endl;
    for(int i = 0; i < MAX_TOKENS; i++) {
      cout << "ptr_arr i " << i << '\t' << ptr_arr[i]
          << '\t' << &ptr_arr[i] << endl;
    }

    return *ptr_arr;

     //return &ptr_arr;
}


int main()
{
  string cmd;
  while(true) {
      // parse_cmd = parseCommandLine(cmd);
      cout << "$ ";
      getline(cin, cmd);
      parseCommandLine(cmd);
      // getline(cin, cmd);
      // cin.getline(cmd, 255, '\n');
  }

  pid_t pid;

  /* fork a child process */
  pid = fork();

  if(pid < 0) { /* error */
    fprintf(stderr, "Fork failed");
    return 1;
  }
  else if(pid == 0) { /* child */
    execlp("/bin/ls", "ls", NULL);
  }
  else { /* parent process */
    //wait(NULL);
    printf("Child Complete\n");
  }

}
