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



     return ptr_arr;
}
