#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

const string PROMPT_FILENAME = "Enter the name of the text file to be saved (e.g. readme.txt): ";
const string PROMPT_TEXT = "Enter your text (type 'exit' to save and quit): ";
const string ERROR_FILENAME = "Error: Invalid filename. Please enter a valid filename without spaces or special characters.";
const string ERROR_OPEN_FILE = "Error: Failed to create file.";

int main()
{
    string filename, line;
    cout << PROMPT_FILENAME;
    getline(cin, filename);

    // Validate filename
    if (!regex_match(filename, regex("^[a-zA-Z0-9_\\.]+$"))) {
        cout << ERROR_FILENAME << endl;
        return 1;
    }

    ofstream file(filename);
    if (!file) {
        cout << ERROR_OPEN_FILE << endl;
        return 1;
    }

    cout << PROMPT_TEXT;
    do {
        getline(cin, line);
        if (line != "exit") {
            file << line << endl;
        }
    } while (line != "exit");

    file.close();
    cout << "File saved in current directory. Exiting..." << endl;

    return 0;
}
