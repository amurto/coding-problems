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

const int N = 2e5 + 5;
ll pw3(ll n)
{
    return n * n * n;
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> arr(n), freq(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for (int i = 1; i < N; i++)
    {
        if (freq[i] > 0)
        {
            for (int j = i, t = 1; j < N; j += i, t++)
            {
                if (freq[j] > 0 && freq[t] > 0)
                {
                    if (j == 1)
                        res += pw3(freq[1]);
                    else
                        res += freq[i] * freq[t] * freq[j];
                }
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}