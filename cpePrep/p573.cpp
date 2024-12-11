#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	double H, U, D, F;
	while(scanf("%lf%lf%lf%lf", &H, &U, &D, &F) != EOF && H != 0) {
		double height = 0;
		int day = 0;
		
		double fatigue = U * (F / 100);
		do{
			++day;
			height += U;
			if(height > H) break;
			
			U = max(0.0, U - fatigue);
			height -= D;
		}while(height >= 0);
		
		if(height > H) {
			printf("success");
		}else {
			printf("failure");
		}
		
		printf(" on day %d\n", day);
	}
	return 0;
}