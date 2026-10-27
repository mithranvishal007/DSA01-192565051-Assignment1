#include <iostream>
using namespace std;

int main()
{
    int a{7}, b{2};
    double integerDivision{static_cast<double>(a / b)};
    double realDivision{static_cast<double>(a) / b};
    cout << integerDivision << ' ' << realDivision << '\n';
    return 0;
}
