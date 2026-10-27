#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double total = 0.0;
    for(int i = 0; i < 100000; ++i) total += 0.1;
    long long paise = 100000LL * 10; // 100,000 fares of 10 paise each
    cout << fixed << setprecision(10) << "double total=" << total << '\n';
    cout << "integer total=" << paise / 100 << " rupees (" << paise << " paise)\n";
    return 0;
}
