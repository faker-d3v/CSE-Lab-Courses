#include <bits/stdc++.h>
using namespace std;

int main() {

    int target_ride;                // n
    int rides_in_multi_ride_ticket; // m
    int single_ride_ticket_cost;    // a
    int multi_ride_ticket_cost;     // b

    cin >> target_ride >> rides_in_multi_ride_ticket >>
        single_ride_ticket_cost >> multi_ride_ticket_cost;

    // NOTE: [Case 1] In an ideal world, if a single ride ticket costs 1 BDT,
    // a multi-ride(5) ticket should cost less than or equal to 5 BDT.

    // multi ticket needed = floor(target ride / multi ride count)
    int multi_ticket_needed = target_ride / rides_in_multi_ride_ticket;
    // the remainder is the number of single tickets needed
    int single_ticket_needed = target_ride % rides_in_multi_ride_ticket;

    int total_cost_multi_ticket =
        (multi_ticket_needed * multi_ride_ticket_cost) +
        (single_ticket_needed * single_ride_ticket_cost);

    // NOTE: [Case 2] But in case the world is retarded and a multi-ride(5)
    // ticket costs more than 5 BDT, we are not dumb enough to buy that

    // just buy all 1 BDT tickets for the target ride
    int total_cost_single_ticket = target_ride * single_ride_ticket_cost;

    // NOTE: [Result] The case with lower cost is the case we have
    cout << min(total_cost_multi_ticket, total_cost_single_ticket) << endl;
}
