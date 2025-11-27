
#include <bits/stdc++.h>
using namespace std;

int main() {

    int target_ride;      // n
    int multi_ride_count; // m
    int single_ride_cost; // a
    int multi_ride_cost;  // b

    cin >> target_ride >> multi_ride_count >> single_ride_cost >>
        multi_ride_cost;

    // NOTE: [Case 1] In an ideal world, if a single ride ticket costs 1 BDT,
    // A multi-ride(5) ticket should cost less than or equal to 5 BDT.

    // multi ticket needed = floor(target ride / multi ride count)
    int multi_ticket_needed = target_ride / multi_ride_count;
    // the remainder is the number of single tickets needed
    int single_ticket_needed = target_ride % multi_ride_count;

    int cost_using_multi =
        (multi_ticket_needed * multi_ride_cost) +
        // depending on the input, sometimes just buying one more multi ticket
        // might be cheaper [this minimum logic is stolen]
        min(single_ticket_needed * single_ride_cost, multi_ride_cost);

    // NOTE: [Case 2] But in case the world is retarded and a multi-ride(5)
    // ticket costs more than 5 BDT, we are not dumb enough to buy that

    // just buy all 1 BDT tickets for the target ride
    int cost_using_single = target_ride * single_ride_cost;

    // NOTE: [Result] The case with lower cost is the case we have
    cout << min(cost_using_multi, cost_using_single) << endl;
}
