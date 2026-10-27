#include <climits>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "sizeof(bool)=" << sizeof(bool) << '\n';
    cout << "sizeof(char)=" << sizeof(char) << '\n';
    cout << "sizeof(int)=" << sizeof(int) << '\n';
    cout << "sizeof(long long)=" << sizeof(long long) << '\n';
    cout << "sizeof(float)=" << sizeof(float) << '\n';
    cout << "sizeof(double)=" << sizeof(double) << '\n';
    cout << "INT_MAX=" << INT_MAX << '\n';
    cout << "LLONG_MAX=" << LLONG_MAX << '\n';
    cout << "Network max fare total paise=" << 3000000LL * 3600 << '\n';
    cout << "Network max fare total fits int? " << (3000000LL * 3600 <= INT_MAX ? "yes" : "no") << '\n';
    return 0;
}
