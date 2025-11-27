#include "bits/stdc++.h"
using namespace std;


int main() {
    stack<int> st; 

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.pop();

    cout << st.top() << endl;
    cout << st.size() << endl;


    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    cout << (st.empty() ? "empty" : "full") << endl;

}

