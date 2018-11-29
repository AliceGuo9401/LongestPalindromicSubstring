#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return {};
    int maxLength(1);
    int longestStrStart(0);
    bool boolArray[s.size()][s.size()];
/*dp*/
    for (int i = 0; i < s.size(); ++i) {
        boolArray[i][i] = true;
        if (i + 1 < s.size())
            boolArray[i][i + 1] = (s[i] == s[i + 1]);
    }
    for (int j = 2; j < s.size(); ++j) {
        for (int i = 0; i < s.size() && i + j < s.size(); ++i)
            boolArray[i][i + j] = (s[i] == s[i + j]) && boolArray[i + 1][i + j - 1];
    }
/*dp*/
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (boolArray[i][j]) {
                if (j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    longestStrStart = i;
                }
            }
        }
    }
    return s.substr(longestStrStart, maxLength);
}
int main() {
    string str("10000000000000000000000000000");
    string longestStr = longestPalindrome(str);
    cout << longestStr;
    return 0;
}
