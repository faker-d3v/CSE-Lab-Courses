#include <bits/stdc++.h>
using namespace std;

// Recursive approach to find gcd
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int number1, number2;
  cin >> number1 >> number2;

  int result = gcd(number1, number2);
  cout << "GCD is " << result << endl;

  return 0;
}
