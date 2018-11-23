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
            iter3 = find(iter3+1, s.end(), *iter3); //泛型算法find，定义在头文件algorithm
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
                        break;  //break终止离它最近的while、for
                    }
                }
                
                if(flag == 0) {
                    int length = iter3 - iter2; //iter2 + length = iter3
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
    
    string str(iter1 + maxi, iter1 + maxi + max + 1); //string对象初始化为迭代器指定范围中的元素的拷贝，但不包括第二个迭代器指向的元素
                                                      //iter2、iter3指定范围的string
    return str;
}
/*end*/

int main() {
    string s("abcdefedcbag");
    string str = longestPalindrome(s);
    cout << str;
    return 0;
}
