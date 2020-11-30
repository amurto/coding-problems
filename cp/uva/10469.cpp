// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1410
// 10469 - To Carry or not to Carry

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while (cin >> a >> b)
        cout << (a ^ b) << "\n";
    return 0;
}