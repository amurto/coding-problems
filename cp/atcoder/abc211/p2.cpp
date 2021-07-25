#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    vector<string> s(4);
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    for (int i = 1; i < 4; i++)
        if (s[i - 1] == s[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}