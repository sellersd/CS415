#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char ** parse(string s);

int main() {

    string s;
    char ** p;
    char str[256];

    cout << "$ ";
    //cin.getline(str, 255);
    getline(cin, s);
    p = parse(str);
    cout << p << endl;
    return 0;
}

char ** parse(string s) {

    char ** p;
    int num_tokens = 4;
    char  tokens[num_tokens] = "\n|<>";
    cout << tokens << endl;
    
    char *dup = strdup(s.c_str());
    cout << dup << endl;

    char *word = strtok(dup,tokens);
    cout << "word is "; // << word << endl;
    return  p;
}
