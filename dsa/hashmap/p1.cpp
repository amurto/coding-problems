// Highest Frequency Character

#include <bits/stdc++.h>
using namespace std;

char HighestFrequencyCharacter(string str)
{
    unordered_map<char, int> MAP;
    int MAX = 0;
    for (char ch : str)
    {
        MAP[ch]++;
        MAX = max(MAX, MAP[ch]);
    }
    char ans = '0';
    for (auto it = MAP.begin(); it != MAP.end(); it++)
        if (it->second == MAX)
            return it->first;
    return '0';
}

int main()
{
    string str;
    cin >> str;
    cout << HighestFrequencyCharacter(str) << "\n";
    return 0;
}