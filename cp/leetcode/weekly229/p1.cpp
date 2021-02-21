#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string mergeAlternately(string word1, string word2)
{
    int i = 0, j = 0, n = word1.length(), m = word2.length();
    string res;
    while (i < n && j < m)
    {
        res.push_back(word1[i++]);
        res.push_back(word2[j++]);
    }
    while (i < n)
        res.push_back(word1[i++]);
    while (j < m)
        res.push_back(word2[j++]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string word1, word2;
    cin >> word1 >> word2;
    cout << mergeAlternately(word1, word2) << "\n";
    return 0;
}