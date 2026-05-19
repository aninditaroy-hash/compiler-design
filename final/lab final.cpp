
#include <iostream>
#include <string>
using namespace std;

bool isAccepted(string s) {
    int n = s.length();
    if (n == 0) return false;

    int i = 0;
    //a check
    while (i < n && s[i] == 'a') {
        i++;
    }

    //  b check
    int bCount = 0;
    while (i < n && s[i] == 'b') {
        i++;
        bCount++;
    }

    // last strind b thn accepted
    return (i == n && bCount > 0);
}

int main() {

    string testCases[5] = {"b", "ab", "aaabb", "ba", "aaa"};

    for (int i = 0; i < 5; i++) {
        cout << "Input: " << testCases[i] << " -> ";
        if (isAccepted(testCases[i])) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }
    return 0;
}
