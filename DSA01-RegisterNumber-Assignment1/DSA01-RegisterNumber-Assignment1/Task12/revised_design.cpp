#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };
constexpr array<long long, 4> FARE_PAISE = {1000, 2000, 3000, 6000};
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fareFor(Zone zone, bool peak, bool weekend)
{
    long long base = FARE_PAISE.at(static_cast<size_t>(zone));
    // Weekend discount does not combine with peak surcharge; weekend takes precedence.
    if (weekend) return base * 90 / 100;
    if (peak) return base + base * 20 / 100;
    return base;
}

class MonthlyPass {
private:
    Zone first;
    Zone second;
public:
    MonthlyPass(Zone a, Zone b) : first(a), second(b) {}
    bool covers(Zone z) const { return z == first || z == second; }
};

class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    bool canTravel(long long fare) const
    {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE_PAISE;
    }
    bool deduct(long long fare)
    {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};

int main()
{
    MonthlyPass pass(Zone::Inner, Zone::Middle);
    SmartCard card(20000);
    Zone testZones[] = {Zone::Inner, Zone::Airport, Zone::Outer};
    for (Zone z : testZones) {
        if (pass.covers(z)) {
            cout << "PASS fare=0 paise";
        } else {
            long long f = fareFor(z, true, true); // weekend discount takes priority over peak
            cout << "Fare paise=" << f;
            if (!card.deduct(f)) cout << " denied";
            else cout << " accepted";
        }
        cout << " balance=" << card.balance() << '\n';
    }
    cout << "Airport weekday peak paise=" << fareFor(Zone::Airport, true, false) << '\n';
    cout << "Airport weekend paise=" << fareFor(Zone::Airport, true, true) << '\n';
}
