#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int z = count(str.begin(), str.end(), '0');
    if (z == 0)
        return "DRAW";
    if (z==1)
        return "BOB";
    if (n % 2 == 0)
        return "BOB";
    else
    {
        int mid = str[n / 2] - '0';
        if (mid== 0)
            return "ALICE";
    }
    return "BOB";
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