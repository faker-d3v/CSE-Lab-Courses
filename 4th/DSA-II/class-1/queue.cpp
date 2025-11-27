#include "bits/stdc++.h"
using namespace std;


int main() {
    queue<int> q ;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }


    cout << endl;

    cout << (q.empty() ? "empty" : "full") << endl;
}
