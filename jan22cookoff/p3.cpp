#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 505;
int arr[N];
void init()
{
    int M = 100 * N;
    arr[0] = 2;
    for (int i = 1; i < N; i++)
    {
        arr[i] = -1;
        vector<bool> vis(M);
        int sum = 0;
        for (int j = i - 1, sz = 2; j >= 0; j--, sz++)
        {
            sum += arr[j];
            vis[arr[j]] = true;
            int rem = sz - (sum % sz);
            for (int k = rem; k < M; k += sz)
                vis[k] = true;
        }
        for (int k = 1; arr[i] == -1 && k < M; k++)
            if (!vis[k])
                arr[i] = k;
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}