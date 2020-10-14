// https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0
// Tower of Hanoi

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int TOH(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    int steps = 1;
    steps += TOH(n - 1, a, c, b);
    cout << "move disk " << n << " from rod " << a << " to rod " << c << "\n";
    steps += TOH(n - 1, b, a, c);
    return steps;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        cout << TOH(n, 1, 2, 3) << "\n";
    }
    return 0;
}
