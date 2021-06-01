#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, val = 0;
    string str;
    cin >> n >> str;
    int mn = 0;
    for (char ch : str)
    {
        if (ch == '+')
            val++;
        else
            val--;
        mn = min(mn, val);
    }
    val = -mn;
    for (char ch : str)
        if (ch == '+')
            val++;
        else
            val--;
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}