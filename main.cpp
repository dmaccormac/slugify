#include <iostream>
#include <fstream>
using namespace std;

// slugify a string:
// 1. replace whitespaces with '-'
// 2. remove non alphanumeric chars
// 3. convert uppercase chars to lower
string slugify(string input){

    for (auto& ch: input) { 
        if (ch == ' ')
            ch = '-';

        else if (!isalnum(ch))
            ch = '\0';
        
        else if (isupper(ch))
            ch = tolower(ch); 
    } 

    return input;

}
int main(int argc, char **argv) {

    if (argc < 2)
        cout << "USAGE: " << argv[0] << " <FILE ...>" << endl;

    int file_count = argc -1;

    for (int i = 1; i <= file_count; i ++)
    {
        ifstream infile(argv[i]);
        string line;
        int line_count = 0;
        while (getline(infile, line)) 
            cout << std::setfill('0') << std::setw(2) << ++line_count << "-" << slugify(line) << endl;
        

    }
        return 0;
}
