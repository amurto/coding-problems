#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, LGN = 18;
int sp[N][LGN], hp[N];

void init()
{
    // highest power of 2 less than i
    hp[0] = hp[1] = 0;
    for (int i = 2; i < N; i++)
        hp[i] = hp[i / 2] + 1;
}

void build(vector<int> &arr, int n)
{
    // sparse table initialization with input array
    for (int i = 0; i < n; i++)
        sp[i][0] = arr[i];
    // works for min, max, gcd
    // updates not supported
    for (int k = 1; k < LGN; k++)
        for (int i = 0; i < n; i++)
            sp[i][k] = min(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
}

int query(int l, int r)
{
    int dis = r - l + 1;
    return min(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n, q, l, r;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, n);
    while (q-- > 0)
    {
        cin >> l >> r;
        cout << query(l - 1, r - 1) << "\n";
    }
    return 0;
}