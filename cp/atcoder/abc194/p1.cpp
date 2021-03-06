#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, res = 4;
    cin >> a >> b;
    if (a + b >= 15 && b >= 8)
        res = 1;
    else if (a + b >= 10 && b >= 3)
        res = 2;
    else if (a + b >= 3)
        res = 3;
    cout << res << "\n";
    return 0;
}