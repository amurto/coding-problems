#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t-- > 0)
    {
        int n, k, v;
        cin >> n >> k;
        set<int> SET;
        for (int i = 0; i < k; i++)
        {
            cin >> v;
            SET.insert(v);
        }
        SET.size() == n-1 ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}