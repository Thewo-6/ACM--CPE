#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int main()                                       
{
    int n;
    std::vector <unsigned> numbers(10000, 0);
    int index = 0;
    while(std::cin >> n){
        numbers[index++] = n;
        for(int i = index - 1 ; i >= 0 ; --i){
            if(numbers[i] > n){
                std::swap(numbers[i], numbers[i + 1]);
            }
        }
        unsigned median = -1;
        if(index % 2 == 1){
            int m_index = (index - 1) / 2;
            median = numbers[m_index];
        } else{
            int m_index1 = index / 2;
            int m_index2 = (index / 2) - 1;
            median = (numbers[m_index1] + numbers[m_index2]) / 2;
        }
        std::cout << median << '\n';
    }
    return 0;
}