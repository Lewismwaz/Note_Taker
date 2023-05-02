#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename, line;
    cout << "Enter the name of the text file to be saved e.g. (readme.txt):";
    getline(cin, filename);

    ofstream file(filename);
    if (!file) {
        cout << "Error creating the text file!" << endl;
        return 1;
    }

    cout << "1. Enter your text:" << endl;
    cout << "2. Finished? Press ENTER, then type 'exit' to save and quit.):" << endl;
    while (getline(cin, line)) {
        if (line == "exit") {
            break;
        }
        file << line << endl;
    }

    file.close();
    cout << "File saved in current directory. Exiting..." << endl;

    return 0;
}
