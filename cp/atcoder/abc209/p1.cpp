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
    cin >> a >> b;
    if (a > b)
        cout << 0 << "\n";
    else
        cout << b - a + 1 << "\n";
    return 0;
}