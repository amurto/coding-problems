#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<char, int>> piii;
#define pb push_back

bool cmp1(piii p1, piii p2)
{
    if (p1.first == p2.first)
    {
        if (p1.second.first == p2.second.first)
            return p1.second.second <= p2.second.second;
        else 
            return p1.second <= p2.second;
    }
    return p1.first > p2.first;
}

bool cmp2(piii p1, piii p2) {
    return p1.second.second < p2.second.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vector<ll> val(26), cnt(26);
        for (int i = 0; i < 26; i++)
            cin >> val[i];
        vector<piii> res, best;
        for (int i = 0; i < n; i++)
            res.pb({val[str[i] - 'a'], {str[i], i}});
        sort(res.begin(), res.end(), cmp1);


        cout << "\n";
    }
    return 0;
}