#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.141592653589793
#define EARTH_RADIUS 6440.0

double toRadians(double angle, string unit) {
    if (unit == "min") {
        return (angle / 60.0) * (PI / 180.0);
    }
    return angle * (PI / 180.0); // for degrees
}

int main() {
    double s, a;
    string unit;

    while (cin >> s >> a >> unit) {
        double radius = EARTH_RADIUS + s; // Total radius from the center of the earth
        double angleRad = toRadians(a, unit); // Convert angle to radians

        if (angleRad > PI) {
            angleRad = 2 * PI - angleRad; // Ensure the angle is within [0, PI]
        }

        double arcDistance = radius * angleRad; // Arc distance formula
        double chordDistance = 2 * radius * sin(angleRad / 2.0); // Chord distance formula

        cout << fixed << setprecision(6) << arcDistance << " " << chordDistance << endl;
    }

    return 0;
}
