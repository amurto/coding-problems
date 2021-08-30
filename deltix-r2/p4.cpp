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

const int LGN = 30;

int is_set(int x)
{
    return x & 1;
}

int query(string str, int l, int r)
{
    cout << str << " " << l << " " << r << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), qOR(n), qAND(n), bits(LGN, -1);
    for (int i = 1; i < n; i++)
    {
        qOR[i] = query("or", 1, i + 1);
        qAND[i] = query("and", 1, i + 1);
        for (int b = 0; b < LGN; b++)
        {
            int b1 = is_set(qOR[i] >> b), b2 = is_set(qAND[i] >> b);
            if (b1 + b2 == 0)
                bits[b] = 0;
            else if (b1 + b2 == 2)
                bits[b] = 1;
        }
    }
    int q = query("or", 2, 3);
    for (int b = 0; b < LGN; b++)
    {
        if (bits[b] == -1)
        {
            if (is_set(q >> b))
                bits[b] = 0;
            else
                bits[b] = 1;
        }
        arr[0] |= (bits[b] << b);
    }
    for (int i = 1; i < n; i++)
    {
        for (int b = 0; b < LGN; b++)
        {
            int cur = is_set(arr[0] >> b), b1 = is_set(qOR[i] >> b), b2 = is_set(qAND[i] >> b);
            if (cur == 0)
            {
                if (b1 + b2 == 1)
                    arr[i] |= (1 << b);
            }
            else
            {
                if (b1 + b2 == 2)
                    arr[i] |= (1 << b);
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << "finish " << arr[k - 1] << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}