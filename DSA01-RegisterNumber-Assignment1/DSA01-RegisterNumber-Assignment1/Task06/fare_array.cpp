#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long FARE_PAISE[] = {1000, 2000, 3000};

long long baseFare(Zone zone)
{
    return FARE_PAISE[static_cast<int>(zone)];
}

int main()
{
    cout << baseFare(Zone::Inner) << ' '
         << baseFare(Zone::Middle) << ' '
         << baseFare(Zone::Outer) << '\n';
    return 0;
}
