#include<iostream>
#include<string>
#include<vector>
int main() {
    std::string longstr;
    std::string shortstr;
    std::cin >> longstr >> shortstr;
    int n = longstr.size(),m = shortstr.size();
    std::string str = shortstr + '#' + longstr;//合并longstr和shortstr --------#----------------------用-表示字符串
    std::vector<int> ne(str.size());
    for(int i = 1; i < str.size(); i++) {
        int len = ne[i - 1];//len等于上一个数的next数组值
        while(len != 0 && str[i] != str[len]) {//当 当前数与str[len]不同 寻找上一个next数组并再次匹配当前数与str[len]
            len = ne[len - 1];
            //,,------..len----#--------------。。i   易知。。 == ..  
            //,,与。。即表示上一个next数组所以,,==。。==..
            //即只需找到len - 1位置的next数组
        }
        if(str[i] == str[len]) {
            ne[i] = ++len;//即ne[i] = ne[i - 1] + 1
            if(ne[i] == m) {
                std::cout << i - m * 2 << std::endl;
                break;
            }
        }
    }
    //现只需找到与shortstr长度相同的next数组即可找到匹配字符串下标
    return 0;
}