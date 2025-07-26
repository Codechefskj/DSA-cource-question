#include <iostream>
#include <string>
using namespace std;

bool correct(string s) {
    for (int i = 2; i < s.size(); i++) {
        if ((s[i - 2] == 'F' && s[i - 1] == 'F' && s[i] == 'T') ||
            (s[i - 2] == 'N' && s[i - 1] == 'T' && s[i] == 'T')) {
            return false;
        }
    }
    return true;
}

string correctans(string s) {
    for (int i = 2; i < s.size(); i++) {
        if (s[i - 2] == 'F' && s[i - 1] == 'F' && s[i] == 'T') {
            swap(s[i - 1], s[i]); 
        } else if (s[i - 2] == 'N' && s[i - 1] == 'T' && s[i] == 'T') {
            swap(s[i - 2], s[i - 1]); 
        }
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        while (!correct(s)) {
            s = correctans(s);
        }

        cout << s << endl;
    }
    }
