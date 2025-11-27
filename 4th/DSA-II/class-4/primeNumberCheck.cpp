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
  int num;
  cin >> num;
  if (isPrime(num))
    cout << num << " is Prime Number." << endl;
  else
    cout << num << " is Not Prime Number." << endl;
}
