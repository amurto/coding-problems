// EOOPR

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x, y;
        cin >> x >> y;
        int d = abs(y - x);
        int h = d / 2;
        if (y == x)
            cout << "0\n";
        else if (y > x)
            if (d & 1)
                cout << "1\n";
            else if (h & 1)
                cout << "2\n";
            else
                cout << "3\n";
        else if (y < x)
            if (d & 1)
                cout << "2\n";
            else
                cout << "1\n";
    }
    return 0;
}