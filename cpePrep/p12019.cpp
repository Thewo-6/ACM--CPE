#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to determine the day of the week for the given date
string getDayOfWeek(int month, int day) {
    // Correct doomsday dates for 2011 (non-leap year)
    // Index 0 is unused, doomsday for January is 10, and for February is 21
    vector<int> doomsdayDates = {0, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    
    // Days of the week in order
    vector<string> daysOfWeek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Calculate the offset from the doomsday date for the month
    int offset = day - doomsdayDates[month];
    
    // Determine the day of the week (Monday is day 0)
    int dayOfWeekIndex = (offset % 7 + 7) % 7;

    return daysOfWeek[dayOfWeekIndex];
}

int main() {
    int t;
    cin >> t; // Read the number of test cases
    
    while (t--) {
        int month, day;
        cin >> month >> day; // Read the month and day for each test case
        
        cout << getDayOfWeek(month, day) << endl; // Output the day of the week
    }

    return 0;
}
