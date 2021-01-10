#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    if (x + 3 > y)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}