// https://codeforces.com/contest/1464/problem/C
// Poman Numbers

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

// Check if a subset sum is possible, elements are powers of 2
// arr[i] = (1<<arr[i])
bool is_possible_sum_pw2(vector<int> &arr, ll t)
{
    // increase MX if required
    int MX = 55;
    vector<int> cnt(MX);
    for (int x : arr)
        cnt[x]++;
    int carry = 0;
    for (int bit = 0; bit < MX; bit++)
    {
        int req = ((t >> bit) & 1);
        cnt[bit] += carry;
        if (req > cnt[bit])
            return false;
        cnt[bit] -= req;
        carry = cnt[bit] / 2;
    }
    return true;
}

bool solve()
{
    int n;
    ll t, sum = 0;
    string str;
    cin >> n >> t >> str;
    t += (1ll << (str[n - 2] - 'a'));
    t -= (1ll << (str[n - 1] - 'a'));
    t = abs(t);
    for (int i = 0; i < n - 2; i++)
        sum += (1ll << (str[i] - 'a'));
    if ((sum - t) % 2 != 0)
        return false;
    if (n == 2)
        return t == 0;
    t += (sum - t) / 2;
    vector<int> arr(n - 2);
    for (int i = 0; i < n - 2; i++)
        arr[i] = str[i] - 'a';
    return is_possible_sum_pw2(arr, t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}