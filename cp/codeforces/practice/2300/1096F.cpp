// https://codeforces.com/contest/1096/problem/F
// Inversion Expectation

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

const int MOD = 998244353, N = 2e5 + 5;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int inv(int x)
{
    return power(x, MOD - 2, MOD);
}

// factorial and inverse factorial
int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

int cnt_inv(int n)
{
    int cnt = 0;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    do
    {
        if (arr[2] == 5 && arr[4] == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                    if (arr[i] > arr[j])
                        cnt++;
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    return cnt;
}

ll merge(vector<int> &arr, vector<int> &temp, int left, int mid,
         int right)
{
    int i = left, j = mid, k = left;
    ll inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count += 1ll * (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

ll _mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    ll inv_count = 0;
    if (right > left)
    {
        int mid = left + (right - left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll count_inversions(vector<int> arr, int n)
{
    vector<int> temp(n);
    return _mergeSort(arr, temp, 0, n - 1);
}

int solve()
{
    int n, k = 0, res = 0, second_term = 0, third_term = 0;
    cin >> n;
    vector<int> arr(n), less(n + 1), more(n + 1), seq;
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == -1)
            k++;
        else
        {
            seq.pb(arr[i]);
            vis[arr[i]] = true;
        }
    }
    res = add(res, mul(mul(k, k - 1), inv(4)));
    int cntL = 0, cntM = 0;
    for (int i = n; i >= 1; i--)
    {
        if (vis[i])
            more[i] = cntM;
        else
            cntM++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            less[i] = cntL;
        else
            cntL++;
    }
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            pre++;
        else
        {
            int suf = k - pre;
            second_term = add(second_term, add(mul(less[arr[i]], suf), mul(more[arr[i]], pre)));
        }
    }
    second_term = mul(second_term, inv(k));
    if (!seq.empty())
        third_term = count_inversions(seq, (int)seq.size()) % MOD;
    res = add(res, add(second_term, third_term));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}