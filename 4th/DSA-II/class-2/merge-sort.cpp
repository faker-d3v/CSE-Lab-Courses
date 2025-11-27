#include "bits/stdc++.h"
using namespace std;

template <typename T>
void print_vector(vector<T> v) {
    for (T val : v)
        cout << val << " ";
    cout << endl;
}

// For visualization watch YT
// Merge two arrays 
// 1. It is required that the arrays passed are sorted. 
// 2. In case of merge sort, at the end of the recursion each array will have only 1 element, which can be considered already sorted
// 2. The resulting array is only guaranteed to be sorted if the passed arrays were pre-sorted
vector<int> merge(vector<int>& a, vector <int>& b) {
    vector<int> c;
    int i = 0, j = 0;

    // compare and add elements in an ascending order 
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            c.push_back(b[j]);
            j++;
            continue;
        }
        c.push_back(a[i]);
        i++;
    }

    // NOTE:
    // 1. One array may be emptied out before another due to having more smaller numbers. Thus add the remaining numbers
    // 2. As we're not resorting the remaining numbers, it is required that merge() receives already sorted arrays
    
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> mergesort(vector<int>& arr) {
    // NOTE: this is the "base case" that stops the recursion at some point
    // Without this, Segmentation fault (core dumped) ;)
    if (arr.size() <= 1) { 
        return arr;
    }

    int mid = arr.size()/ 2;

    vector<int> a1(arr.begin(),arr.begin()+mid);
    vector<int> a2(arr.begin()+mid,arr.end());

    a1 = mergesort(a1);
    a2 = mergesort(a2);

    return merge(a1, a2);
}

int main() {
    vector<int> xd = {1,2,3};
    vector<int> lt = {2,3,4,4};
    vector<int> cd = {2,3,1,2,3,4,4};

    // print_vector(mergesort(cd));
    print_vector(merge(xd,lt));
}

