//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int G;
	string input;
	
	while(scanf("%d", &G) != EOF && G != 0){
		cin >> input;
		
		int numOfGroupMember = input.length() / G;
		for(int i = 0; i < input.length(); i += numOfGroupMember) {
			for(int j = i + numOfGroupMember - 1; j >= i; j--) {
				printf("%c", input[j]);
			}
		}
		printf("\n");
	}
	return 0;
}