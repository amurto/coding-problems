#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string s, p;
        cin >> s >> p;
        sort(s.begin(), s.end());
        sort(p.begin(), p.end());
        if (s == p)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}