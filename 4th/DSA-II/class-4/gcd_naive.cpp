#include <bits/stdc++.h>
using namespace std;

int main() {
  int number1, number2, gcd;
  cin >> number1 >> number2;

  for (int i = 1; i <= min(number1, number2); i++) {
    if (number1 % i == 0 && number2 % i == 0)
      gcd = i;
  }

  cout << "Gcd of " << number1 << " and " << number2 << " is " << gcd << endl;
}
