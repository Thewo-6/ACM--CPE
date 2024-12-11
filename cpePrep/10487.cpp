//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int testcase = 1;
	while(scanf("%d", &n) != EOF && n != 0) {
		int num[1005];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &num[i]);
		}
		sort(num, num+n);
		
		int m;
		scanf("%d", &m);
		
		printf("Case %d:\n", testcase++);
		int query;
		for(int i = 0; i < m; ++i){
			scanf("%d", &query);
			
			int closestSum = num[0] + num[1];
			for(int j = 0; j < n; ++j){
				for(int k = j+1; k < n; ++k){
					int sum = num[j] + num[k];
					if(abs(sum - query) < abs(closestSum - query)) {
						closestSum = sum;
					}else if((sum - query) > abs(closestSum - query)) {
						break;
					}
				}
			}
			printf("Closest sum to %d is %d.\n", query, closestSum);
		}
	}
	return 0;
}






// 本題 隨機測資 可能出現 等距解 
// 此時請勿放在心上
// 批改時 不會出現等距解