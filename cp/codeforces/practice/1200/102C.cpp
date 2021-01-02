// https://codeforces.com/contest/102/problem/C
// Homework

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    string str, res;
    cin >> str >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> freq(26);
    for (char ch : str)
        freq[ch - 'a']++;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            pq.push({freq[i], i});
    while (!pq.empty() && k > 0)
    {
        pair<int, int> tp = pq.top();
        pq.pop();
        int nk = max(0, k - tp.first);
        freq[tp.second] = max(0, freq[tp.second] - k);
        k = nk;
    }
    int len = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            len++;
    for (char ch : str)
        if (freq[ch - 'a']-- > 0)
            res.pb(ch);
    cout << len << "\n";
    cout << res << "\n";
    return 0;
}