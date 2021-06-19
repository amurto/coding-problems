#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < 30; i += 2)
        if (1 << i == n)
            return "Bob";
    vector<string> seq = {"Alice", "Bob"};
    return seq[n & 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}