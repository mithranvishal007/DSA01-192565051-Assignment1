#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    const long long journeys[] = {20000, 500000, 3000000};
    const long long farePaise = 3600; // maximum current fare: Outer at peak
    cout << fixed << setprecision(2);
    for (long long n : journeys) {
        long long exactPaise = n * farePaise;
        double doubleRupees = static_cast<double>(n) * 36.0;
        cout << "journeys=" << n << " integer_paise=" << exactPaise
             << " double_rupees=" << doubleRupees
             << " double_paise=" << doubleRupees * 100.0 << '\n';
    }
    return 0;
}
