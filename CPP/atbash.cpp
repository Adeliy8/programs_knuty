
#include <iostream>
#include <string>

using namespace std;

string atbash(const string& text) {
    string result;

    for (int ch : text) {
        if (ch >= 'A' && ch <= 'Z') {
            result += 'Z' - (ch - 'A');
        }
        else if (ch >= 'a' && ch <= 'z') {
            result += 'z' - (ch - 'a');
        }
        else if (ch >= '0' && ch <= '9') {
            result += ch;
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {

    //setlocale(LC_ALL, "Rus");

     /*string input_text = "Привет, world! 123456789";
     string output_text = atbash(input_text);

     cout << "Результат: " << output_text << endl;*/

    string input_text;
    cout << "Text:";

    getline(cin, input_text);

    string output_text = atbash(input_text);
    cout << "Encrypted text: " << output_text << endl;

    string decrypted_text = atbash(output_text);
    cout << "Decrypted text: " << decrypted_text << endl;
    return 0;
}
