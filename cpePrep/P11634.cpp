#include <iostream>
using namespace std;

int main() {
	int a0;
	while (cin >> a0 && a0 != 0) {
		int count = 0;
		bool check[10001] = { false };
		while (!check[a0]) {
			count++;
			check[a0] = true;
			a0 *= a0;
			a0 /= 100;
			a0 %= 10000;
		}
		cout << count << endl;
	}
	return 0;
}





















/* #include <iostream>
#include <set>
#include <string>
#include <iomanip>
#include <sstream>

// Function to extract the middle four digits
int middleFourDigits(int number) {
    std::stringstream ss;
    ss << std::setw(8) << std::setfill('0') << number;
    std::string str = ss.str();
    return std::stoi(str.substr(2, 4));
}

int main() {
    int a0;
    while(std::cin >> a0) {
        if(a0 == 0) break;

        std::set<int> uniqueNumbers;
        uniqueNumbers.insert(a0);

        int current = a0;
        while(true) {
            int squared = current * current;
            int middle = middleFourDigits(squared);
            if(uniqueNumbers.find(middle) != uniqueNumbers.end()) {
                break;
            }
            uniqueNumbers.insert(middle);
            current = middle;
        }

        std::cout << uniqueNumbers.size() << std::endl;
    }
    return 0;
} */