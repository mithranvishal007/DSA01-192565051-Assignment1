#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE = 5000;
class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial) {}
    bool canTravel(long long farePaise) const
    {
        return farePaise >= 0 && balancePaise - farePaise >= MIN_BALANCE;
    }
    bool deduct(long long farePaise)
    {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
    long long balance() const { return balancePaise; }
};
int main()
{
    SmartCard card(10000);
    long long fare = 3600;
    cout << (card.deduct(fare) ? "Accepted" : "Denied") << '\n';
    cout << "Balance paise=" << card.balance() << '\n';
    cout << (card.deduct(2000) ? "Accepted" : "Denied") << '\n';
    cout << "Balance paise=" << card.balance() << '\n';
}
