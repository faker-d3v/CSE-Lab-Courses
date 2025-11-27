#include <bits/stdc++.h>
#define sz 1001
using namespace std;

int a[sz], cnt;

void sieve() {
  int i, j;

  for (i = 4; i <= sz; i += 2)
    a[i] = 1;

  for (i = 3; i <= sz; i += 2) {
    if (a[i] == 0) {
      for (j = i * i; j <= sz; j += (i + i))
        a[j] = 1;
    }
  }

  for (i = 2; i <= sz; i++) {
    if (a[i] == 0) {

      cout << i << " ";
      cnt++;
    }
  }
  cout << "total prime number is " << cnt << endl;
}

int main() { sieve(); }
