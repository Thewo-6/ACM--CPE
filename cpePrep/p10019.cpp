//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dec_to_bin_and_count1(int);
int hex_to_bin_and_count1(int);

int main(){
    int n, m;
    int b1, b2;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m; // the number wants to encrypt

        b1 = dec_to_bin_and_count1(m); // covert m(decimal) to its binary representation
        b2 = hex_to_bin_and_count1(m); // covert m(hexadecimal) to its binary representation
        cout << b1 << " " << b2 << endl;
    }

    return 0;
}

int dec_to_bin_and_count1(int m){
    string x = "";
    int b1, tmp;

    while (m > 0){
        tmp = m % 2;
        m /= 2;
        x += to_string(tmp);
    }
    b1 = count(x.begin(), x.end(), '1');
    return b1;
}

int hex_to_bin_and_count1(int m){
    string x = to_string(m);
    int b2 = 0;

    for (int i = 0; i < x.length(); i++){
        b2 += dec_to_bin_and_count1(x[i] - '0');
    }
    return b2;
}