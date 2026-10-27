#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int readInt(const char* prompt)
{
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Invalid input. Enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    int zone = readInt("Zone (1=Inner, 2=Middle, 3=Outer): ");
    int hour = readInt("Hour (0-23): ");
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23) {
        cout << "Invalid zone or hour\n";
        return 0;
    }
    long long fare = (zone == 1 ? 1000 : zone == 2 ? 2000 : 3000);
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) fare += fare * 20 / 100;
    cout << fixed << setprecision(2);
    cout << "Fare Rs " << fare / 100 << '.' << setw(2) << setfill('0') << fare % 100 << '\n';
    return 0;
}
