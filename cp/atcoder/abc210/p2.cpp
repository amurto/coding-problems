#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string res[2] = {"Takahashi", "Aoki"};
string solve()
{
    int n;
    string str;
    cin >> n >> str;
    int mn = n;
    for (int i = 0; i < n; i++)
        if (str[i] == '1')
            mn = min(mn, i);
    return res[mn % 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}