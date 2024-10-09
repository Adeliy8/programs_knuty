#include <iostream>
#include <string>

using namespace std;

char caesar_cipher(char i) {
    if (isalpha(i)) {  
        char base = isupper(i) ? 'A' : 'a';  
        return (i - base + 3) % 26 + base;  
    }
    return i;  
}

char caesar_decipher(char i) {
    if (isalpha(i)) {  
        char base = isupper(i) ? 'A' : 'a';
        return (i - base - 3 + 26) % 26 + base;  // Дешифрование
    }
    return i;
}

string cipher(const string& text) {
    string cipher_text;
    for (char i : text) {
        cipher_text += caesar_cipher(i);
    }
    return cipher_text;
}

string decipher(const string& text) {
    string deciphered_text;
    for (char i : text) {
        deciphered_text += caesar_decipher(i);
    }
    return deciphered_text;
}

int main() {



    string text = "Hello, world 123456789!";
    string cipher_text = cipher(text);
    cout <<"Encrypted text: " << cipher_text << endl;
    
    string decipher_text = decipher(cipher_text);
    cout <<"Decrypted text: " << decipher_text << endl;
    return 0;
}