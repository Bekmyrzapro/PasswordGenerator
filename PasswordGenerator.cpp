#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <algorithm> 
using namespace std;

std::string generatePassword(int length) {
    const string chars = "0123456789"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "abcdefghijklmnopqrstuvwxyz"
                         "!@#$%^&*()_+";

    string password;

    mt19937 generator(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distribution(0, chars.size() - 1);

    for (int i = 0; i < length; ++i) {
        password += chars[distribution(generator)];
    }

    return password;
}

bool isStrongPassword(const std::string& password) {
    
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    const string specialChars = "!@#$%^&*()_+";

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
        if (isdigit(ch)) hasDigit = true;
        if (specialChars.find(ch) != string::npos) hasSpecial = true;
    }

    
    return password.length() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    int length;
    cout << "Enter password length: ";
    cin >> length;

    string password = generatePassword(length);
    cout << "Generated Password: " << password << endl;

    
    if (isStrongPassword(password)) {
        cout << "This is a strong password." << endl;
    } else {
        cout << "This is a weak password." << endl;
    }

    return 0;
}

