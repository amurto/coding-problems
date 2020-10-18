// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Letter Combinations of a Phone Number    

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string MAP[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void getKPC(string soFar, string &s, vector<string> &ans, int cur)
{
    if (cur == s.length())
    {
        ans.push_back(soFar);
        return;
    }
    for (char c: MAP[s[cur]-'0']) 
        getKPC(soFar+c, s, ans, cur+1);
}

vector<string> letterCombinations(string digits) {
    if (digits.length() == 0)
        return {};
    vector<string> ans;
    getKPC("", digits, ans, 0);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = letterCombinations(s);
    for (string v : ans)
        cout << v << "\n";
    return 0;
}