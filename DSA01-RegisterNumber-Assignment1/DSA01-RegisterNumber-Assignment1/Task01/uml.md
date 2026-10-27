# Task 1 — UML-style class diagram

```mermaid
classDiagram
    class SmartCard {
      -long long balancePaise
      +canTravel(farePaise) bool
      +deduct(farePaise) bool
      +balance() long long
    }
    class Journey {
      +Zone zone
      +int hour
      +bool weekend
    }
    class FarePolicy {
      +fareFor(zone, hour, weekend) long long
      +isPeakHour(hour) bool
    }
    class Passenger {
      +string passengerId
      +PassengerCategory category
    }
    class MonthlyPass {
      -Zone firstZone
      -Zone secondZone
      +covers(zone) bool
    }
    SmartCard --> FarePolicy : requests fare validation
    Journey --> FarePolicy : priced by
    Passenger --> Journey : takes
    MonthlyPass --> Passenger : assigned to
```

This is a design sketch rather than a generated UML-tool export. The SmartCard owns and protects balance state; FarePolicy owns fare rules; Journey records the trip facts; Passenger identifies concession eligibility; MonthlyPass is added in Task 12.
