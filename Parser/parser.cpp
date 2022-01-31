#include <iostream>
#include <string.h>

using namespace std;

// char ** parseCommandLine(string CommandLine);
char ** parseCommandLine(string CommandLine);

int main(int argc, char ** argv) {

    string cmd;
    char ** parse_cmd;

    cout << "$ ";
    getline(cin, cmd);
    parse_cmd = parseCommandLine(cmd);
    cout << "parse_cmd: " << parse_cmd << endl;

    /*
    while(cmd != "quit" && cmd != "q") {
        // parse_cmd = parseCommandLine(cmd);
        parseCommandLine(cmd);
        cout << "$ ";
        cin.get(ccmd, 255);
        // getline(cin, cmd);
        // cin.getline(cmd, 255, '\n');
    }
    */
      return 0;
}

//char ** parseCommandLine(string CommandLine) {
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
