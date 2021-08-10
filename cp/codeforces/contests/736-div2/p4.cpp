#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, LGN = 18;
ll sp[N][LGN], hp[N];

void init()
{
    // highest power of 2 less than i
    hp[0] = hp[1] = 0;
    for (int i = 2; i < N; i++)
        hp[i] = hp[i / 2] + 1;
}

ll combine(ll x, ll y) {
    // use your combiner here
    return __gcd(x, y);
}

void build(vector<ll> &arr, int n)
{
    // sparse table initialization with input array
    for (int i = 0; i < n; i++)
        sp[i][0] = arr[i];
    // works for min, max, gcd
    // updates not supported
    for (int k = 1; k < LGN; k++)
        for (int i = 0; i < n; i++)
            sp[i][k] = combine(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
}

ll query(int l, int r)
{
    int dis = r - l + 1;
    return combine(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

int solve()
{
    int n, res = 1;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
        return 1;
    vector<ll> seq(n - 1);
    for (int i = 1; i < n; i++)
        seq[i - 1] = abs(arr[i] - arr[i - 1]);
    build(seq, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (seq[i] == 1)
            continue;
        int low = 0, high = i, idx = i;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (query(mid, i) != 1)
            {
                idx = min(idx, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        res = max(res, i - idx + 2);
    }
    return res;
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
        cout << solve() << "\n";
    return 0;
}