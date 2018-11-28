#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int start(0);
    int maxLength(0);
    
    for (int i = 0; i < s.size(); ++i) {       //b[a]b或b[aa]b
        int left(i - 1), right(i);
        int length(0);
        while (right < s.size() && s[i] == s[right])
            ++right;                          
            
        while (0 <= left && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        ++left;
        --right;
        length = right - left + 1;
        if (length > maxLength) {
            start = left;
            maxLength = length;
        }
    }
    return s.substr(start, maxLength);          //s.substr(pos, n)：返回一个string，包含s中从start开始的n个字符的拷贝
}
int main() {
    string s("aaaaaaaaaa");
    string longestStr = longestPalindrome(s);
    cout << longestStr;
    return 0;
}
