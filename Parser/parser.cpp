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
    cout << parse_cmd << endl;

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

    int MAX_TOKENS = 10;
    int count = 0;
    char ** ptr_arr[MAX_TOKENS];

    // inspiration from
    // https://www.tutorialspoint.com/cpp_standard_library/cpp_string_c_str.htm
    // fixes error converting from const char * to char *
    char * c = new char[CommandLine.length()+1];
    strcpy(c, CommandLine.c_str());

    char * ptr = strtok(c, " ><|") ;
    while(ptr != NULL && count < MAX_TOKENS) {
      ptr_arr[count] = &ptr;
      cout << ptr << endl;
      ptr = strtok(NULL, " ><|");
    }

    cout << "contents of ptr_arr" << endl;
    cout << "0 " << ptr_arr[0]
        << "1 " << ptr_arr[1]
        << "2 " << ptr_arr[2] << endl;



     //return &ptr_arr;
}
