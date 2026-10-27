#include <iostream>
using namespace std;

int main()
{
    bool peak[24] = {};
    for(int h = 8; h < 10; h++) peak[h] = true;
    for(int h = 17; h < 20; h++) peak[h] = true;

    int hour;
    cin >> hour;
    if(hour < 0 || hour > 23)
        cout << "Invalid hour";
    else if(peak[hour])
        cout << "Peak";
    else
        cout << "Off-peak";
    return 0;
}
