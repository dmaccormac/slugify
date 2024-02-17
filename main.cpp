#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

string slugify(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    replace(input.begin(), input.end(), ' ', '-');

    regex pattern("[^a-z0-9-]");
    input = regex_replace(input, pattern, "");

    return input;
}
int main(int argc, char **argv) {

    if (argc == 1)
        cout << "Usage: " << argv[0] << " <string ...>" << endl;

    for (int i = 1; i < argc; i++)
        cout << slugify(argv[i]) << endl;

    return 0;
}
