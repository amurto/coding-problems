#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int px, py;
    string s;
    cin >> px >> py >> s;
    int v[2], h[2];
    v[0] = count(s.begin(), s.end(), 'U');
    v[1] = count(s.begin(), s.end(), 'D');
    h[0] = count(s.begin(), s.end(), 'R');
    h[1] = count(s.begin(), s.end(), 'L');
    if (v[py < 0] < abs(py))
        return false;
    if (h[px < 0] < abs(px))
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}