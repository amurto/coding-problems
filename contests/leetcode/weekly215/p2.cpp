#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    if (n != m)
        return false;
    vector<int> cnt1(26), cnt2(26);
    for (char ch : word1)
        cnt1[ch - 'a']++;
    for (char ch : word2)
        cnt2[ch - 'a']++;
    vector<int> occ1, occ2;
    for (int i = 0; i < 26; i++)
    {
        if ((cnt1[i] == 0 && cnt2[i] > 0) || (cnt1[i] > 0 && cnt2[i] == 0))
            return false;
        if (cnt1[i] > 0)
            occ1.push_back(cnt1[i]);
        if (cnt2[i] > 0)
            occ2.push_back(cnt2[i]);
    }
    if (occ1.size() != occ2.size())
        return false;
    sort(occ1.begin(), occ1.end());
    sort(occ2.begin(), occ2.end());
    for (int i = 0; i < occ1.size(); i++)
        if (occ1[i] != occ2[i])
            return false;
    return true;
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    closeStrings(word1, word2) ? cout << "true\n" : cout << "false\n";
    return 0;
}