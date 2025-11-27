#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }

  return true;
}

int main() {
  int left, right, cnt = 0;
  cin >> left >> right;
  for (int i = left; i <= right; i++) {
    if (isPrime(i)) {
      cout << i << " ";
      cnt++;
    }
  }
  cout << endl;
  cout << "Total prime number in the range " << left << " and " << right
       << " is " << cnt << endl;
}
