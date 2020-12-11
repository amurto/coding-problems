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
        int n, k, cur = 0;
        cin >> n >> k;
        string str;
        for (int i = 0; i < n; i++)
        {
            str.pb(cur + 'a');
            cur++;
            cur = cur % 3;
        }
        cout << str << "\n";
    }
    return 0;
}