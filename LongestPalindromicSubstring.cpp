#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*start*/
string longestPalindrome(string s) {
    vector<int> iLength;
    auto iter1 = s.begin();

    for(int i = 0; i < s.size(); ++i) {
        auto iter2 = iter1 + i;
        auto iter3 = iter2;
        int flag = 0;
        iLength.push_back(0);

        while(iter3 != s.end()) {
            iter3 = find(iter3+1, s.end(), *iter3);
            if(iter3 != s.end()) {
                auto iter2Temp = iter2;
                auto iter3Temp = iter3;
                
                while(iter2Temp <= iter3Temp) {
                    if(*iter2Temp == *iter3Temp) {
                        flag = 0;
                        ++iter2Temp;
                        --iter3Temp;
                    }else if(*iter2Temp != *iter3Temp) {
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0) {
                    int length = iter3 - iter2;
                    if(length > iLength[i])
                        iLength[i] = length;
                }
            }
        }
    }
    
    int max(0), maxi(0);
    for(int i = 0; i < s.size(); ++i) {
        if(iLength[i] > max) {
            max = iLength[i];
            maxi = i;
        }
    }
    
    string str(iter1 + maxi, iter1 + maxi + max+1); //使用迭代器初始化string对象
    return str;
}
/*end*/

int main() {
    string s("abcdefedcbag");
    string str = longestPalindrome(s);
    cout << str;
    return 0;
}
