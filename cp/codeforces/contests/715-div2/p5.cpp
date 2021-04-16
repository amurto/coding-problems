#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
int lim = 61;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int i = 1;
    while (i <= n)
    {
        int l = *st.begin(), r = *st.rbegin(), rem = n - i + 1;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}