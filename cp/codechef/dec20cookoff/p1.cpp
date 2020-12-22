#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    string str;
    cin >> str;
    int n = str.length(), res = 0;
    vector<int> cnt(2), to(2);
    if (n % 2 == 1)
        return -1;
    for (char ch : str)
        cnt[ch - '0']++;
    int d = abs((n/2) - cnt[0]);
    for (int i = 0; i < n - 1; i++)
        if (str[i] != str[i+1])
            return d;
    return -1;
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