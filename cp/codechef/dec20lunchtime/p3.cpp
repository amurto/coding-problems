#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    string str;
    cin >> str;
    vector<int> freq(26);
    for (char ch : str)
        freq[ch - 'a']++;
    multiset<int> ms;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            ms.insert(freq[i]);
    int res = 0;
    while (ms.size() > 1)
    {
        int l = *ms.begin();
        ms.erase(ms.begin());
        auto ed = ms.end();
        ed--;
        int r = *ed;
        ms.erase(ed);
        if (r <= 1)
            break;
        l--;
        r -= 2;
        res++;
        if (l > 0)
            ms.insert(l);
        if (r > 0)
            ms.insert(r);
    }
    if (ms.size() > 0)
        res += (*ms.rbegin()) / 3;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}