// https://codeforces.com/contest/1397/problem/D
// Stoned Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int play()
{
    int n, x, sum = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    if (mx <= sum / 2 && sum % 2 == 0)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string winner[2] = {"T", "HL"};
    int t;
    cin >> t;
    while (t-- > 0)
        cout << winner[play()] << "\n";
    return 0;
}