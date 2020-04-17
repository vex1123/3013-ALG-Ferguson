#include <iostream>

using namespace std;

int main() {
  int n, t, x, e;
  x = 1;
  cin >> n;
  while ( n!= 0)
  {
    e = (n * (n-1)) / 2;
    t = e/(n - 1);
    cout << "CASE: " << x << ": " << t << endl;
    x++;
    cin >> n;
  }

}
