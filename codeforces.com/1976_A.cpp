#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isStrongPassword(const string& password) {
    string letters, digits;
    bool let = 0;
    // Separate letters and digits
    for (char ch : password) {
        if (isalpha(ch)) {
            let = 1;
            letters.push_back(ch);
        } else if (isdigit(ch)) {
            if(let) return 0;
            digits.push_back(ch);
        }
    }

    // Check if letters are sorted
    if (!is_sorted(letters.begin(), letters.end())) {
        return false;
    }

    // Check if digits are sorted
    if (!is_sorted(digits.begin(), digits.end())) {
        return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string password;
        cin >> n >> password;

        if (isStrongPassword(password)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
