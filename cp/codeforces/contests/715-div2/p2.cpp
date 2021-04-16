#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    string str;
    cin >> n >> str;
    queue<int> tq;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'T')
            tq.push(i);
        else
        {
            if (tq.empty())
                return false;
            tq.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'M')
        {
            if (tq.empty() || tq.front() < i)
                return false;
            tq.pop();
        }
    }
    return tq.empty();
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