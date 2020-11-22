#include <bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    sort(word1.begin(), word1.begin());
    sort(word2.begin(), word2.begin());
    string str1 = "", str2 = "";
    for (string s : word1)
        str1 += s;
    for (string s : word2)
        str2 += s;
    return (str1 == str2);
}

int main()
{
    vector<string> word1 = {"abc", "d", "defg"}, word2 = {"abcddefg"};
    arrayStringsAreEqual(word1, word2) ? cout << "true\n" : cout << "false\n";
    return 0;
}