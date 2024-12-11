#include <iostream>
using namespace std;

int main() {
	int c[9];
	int flag;
	while (cin >> c[8]) {
		flag = 1;
		for (int i = 7; i >= 0; --i)
			cin >> c[i];

		for (int i = 8; i >= 0; --i) {
			if (c[i] == 0)
				continue;
			
			if (flag == 1) {
				flag = 0;
				if (c[i] < 0)
					cout << "-";
			}
			else {
				if (c[i] > 0)
					cout << " + ";
				else
					cout << " - ";
			}

			if (c[i] < 0)
				c[i] = -c[i];

			if (c[i] != 1 || i == 0)
				cout << c[i];

			if (i >= 2)
				cout << "x^" << i;
			else if (i == 1)
				cout << "x";
		}

		if (flag == 1)
			cout << c[0];

		cout << "\n";
	}


	return 0;
}













/* #include <iostream>
using namespace std;

int main() 
{
    int usrInput[9];

    for(int i = 0; i < 9; ++i)
    {
        cin >> usrInput[i];
    }
    while(cin >> usrInput[i]) 
    {
        bool found = false;
    int leadingDeg = 0;
    for(int i = 0; i < 9; ++i)
    {
        if(!found)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(usrInput[j] != 0)
                {
                    leadingDeg = j;
                    found = true;
                    break;
                }   
            }
        }

        short exponent = 8-i;
        if(usrInput[i] != 0)
        {

            if(usrInput[i] >= 0)
            {
                if(i != leadingDeg)
                    cout << " + " ;
                
                if(exponent == 1)
                {
                    if(usrInput[i] > 1)
                        cout << usrInput[i] << "x";
                    else
                        cout << "x";
                }
                else if(exponent)
                {
                    if(usrInput[i] > 1)
                        cout << usrInput[i] << "x^" << exponent;
                    else
                        cout << "x^" << exponent;
                }
                else
                    cout << 1;
            } 
            else
            {
                if(i != leadingDeg)
                    cout << " - " ;
                else
                    cout << "-";

                if(exponent == 1)
                {
                    if(usrInput[i] < -1)
                        cout << usrInput[i] * (-1) << "x";
                    else
                        cout << "x";
                }
                else if(exponent)
                {
                    if(usrInput[i] < -1)
                        cout << usrInput[i] * (-1) << "x^" << exponent;
                    else
                        cout << "x^" << exponent;
                }
                else
                    cout << 1;
            }
        }
    }
    }
    
} */