#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class base_k
{
public:
    int k, mx = 0;
    vector<int> bits;
    base_k() {}
    base_k(int k, int x) : k(k)
    {
        ll cur = 1;
        while (cur < 1e9)
        {
            mx++;
            cur *= k;
        }
        bits.resize(mx);
        int i = 0;
        while (x > 0)
        {
            bits[i] = x % k;
            x /= k;
            i++;
        }
    }

    int to_dec()
    {
        int num = 0;
        for (int i = 0, v = 1; i < mx; i++, v *= k)
            num += bits[i] * v;
        return num;
    }
};

int add(int x, int y, int MOD)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

base_k add_baseK(base_k num1, base_k num2, int d)
{
    int k = num1.k;
    base_k res = base_k(k, 0);
    for (int i = 0; i < num1.mx; i++)
        res.bits[i] = add(num1.bits[i], d * num2.bits[i], k);
    return res;
}

int query(base_k y)
{
    cout << y.to_dec() << endl;
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
    base_k prev = base_k(k, 0);
    for (int i = 0; i < n; i++)
    {
        int s = 1;
        if (i & 1)
            s = -1;
        base_k cur = add_baseK(base_k(k, 0), base_k(k, i), s);
        if (query(add_baseK(prev, cur, 1)))
            return;
        prev = cur;
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