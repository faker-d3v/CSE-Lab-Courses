#include "bits/stdc++.h"
using namespace std;

// C++ Generics
template <typename T>
void print_vector(vector<T> v) {
    for (T val : v)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<string> coins; 
    coins.assign({"BTC", "ETH", "SOL", "XRP", "AVLX"});

    print_vector(coins);

    // elem
    cout << "first: " << coins.at(0) << endl;
    cout << "second: " << coins[0] << endl;
    cout << coins.front() << endl;
    cout << coins.back() << endl;

    // Pointers
    cout << *coins.begin() << endl; // first elem
    cout << *coins.rbegin() << endl; // last elem

    /* iterators usually used to iterate from a side */
    // cout << coins.rend()  << endl;  // before first (not meant to be derefed)
    // cout << coins.end()  << endl;  // after last (not meant to be derefed)
    cout << *coins.data() << endl; // first elem


    // size and shape 
    cout << "size: " << coins.size() << endl;
    cout << "cap: " << coins.capacity() << endl;
    // note: max_* is the theoretical versions of these two and are not the current state
    coins.resize(4); // drops elem


    // I/O
    coins.push_back("SUI");
    coins.pop_back();
    
    coins.erase(coins.begin() + 1, coins.begin() + 2); // overloaded, can take 1 param
    coins.insert(coins.begin() + 1, "ETH"); 
    // coins.clear();

    print_vector(coins);
    // Search for existence
    auto at = find(coins.begin(), coins.end(), "SOLx");
    cout << *at << endl; // returns vector.end() if not found 

    // dealloc unnecessary space
    cout << "cap: " << coins.capacity() << endl;
    coins.shrink_to_fit();
    cout << "cap: " << coins.capacity() << endl;

    // empty?
    cout << (coins.empty() ? "Empty" : "Full") << endl;
    print_vector(coins);
}

