#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    try {
        size_t used = 0;
        int hour = stoi(line, &used);
        if(used != line.size() || hour < 0 || hour > 23)
            cout << "Invalid hour";
        else
            cout << "Hour = " << hour;
    } catch(...) {
        cout << "Invalid input";
    }
    return 0;
}
