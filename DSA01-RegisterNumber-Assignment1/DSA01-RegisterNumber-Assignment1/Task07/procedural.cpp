#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE = 5000;
long long calculateFare(int basePaise, bool peak)
{
    return peak ? basePaise + basePaise * 20 / 100 : basePaise;
}
bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE;
}
int main()
{
    long long balance = 10000;
    long long f = calculateFare(3000, true);
    if (canTravel(balance, f)) { balance -= f; cout << "Accepted "; }
    else cout << "Denied ";
    cout << "Balance paise=" << balance << '\n';
}
