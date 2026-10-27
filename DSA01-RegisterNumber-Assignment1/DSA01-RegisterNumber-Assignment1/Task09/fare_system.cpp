#include <iostream>
#include <limits>
#include <string>
using namespace std;
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int BASE_PAISE[] = {1000, 2000, 3000};

bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
bool calculateFare(int zone, int hour, long long& fare)
{
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23) return false;
    fare = BASE_PAISE[zone - 1];
    if (isPeakHour(hour)) fare += fare * 20 / 100;
    return true;
}
bool canTravel(long long balance, long long fare)
{
    return fare >= 0 && balance - fare >= MIN_BALANCE_PAISE;
}
int main()
{
    long long balance, recharge;
    int zone, hour;
    if (!(cin >> balance >> recharge >> zone >> hour)) {
        cout << "Invalid input\n";
        return 0;
    }
    if (balance < 0) { cout << "Invalid balance\n"; return 0; }
    if (recharge < 0) { cout << "Invalid recharge\n"; return 0; }
    balance += recharge;
    long long fare = 0;
    if (!calculateFare(zone, hour, fare)) { cout << "Invalid zone or hour\n"; return 0; }
    if (!canTravel(balance, fare)) { cout << "Denied (low balance)\n"; return 0; }
    balance -= fare;
    cout << "Fare paise=" << fare << '\n';
    cout << "Balance paise=" << balance << '\n';
    return 0;
}
