#include <iostream>

//const unsigned int MASK = 1<<31;

int main(){
  using namespace std;
  int input;
  while(cin >> input,input){
    cout << "The parity of ";
    unsigned int mask = 1<<31;
    int count = 0;
    for(;mask&& !(mask&input);mask >>= 1);

    for(;mask;mask >>= 1){
      cout << 0 + !!(mask & input);
      count += !!(mask & input);
    }

   cout << " is " << count << " (mod 2)."<< endl;

  }
  return 0; 
}