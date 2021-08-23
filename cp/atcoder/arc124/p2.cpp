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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> nums;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int id = 0; id < n; id++)
    {
        int x = a[0] ^ b[id];
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
            if (i != id)
                cnt[b[i]]++;
        bool sat = true;
        for (int i = 1; sat && i < n; i++)
        {
            if (cnt[x ^ a[i]] == 0)
                sat = false;
            else
                cnt[x ^ a[i]]--;
        }
        if (sat)
            nums.insert(x);
    }
    cout << nums.size() << "\n";
    for (int num : nums)
        cout << num << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}