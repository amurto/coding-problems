#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int findTime(vector<int> &A)
{
    return A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
}

bool isValid(vector<int> &A)
{
    if (A[0] > 2)
        return false;
    else
    {
        if (A[0] == 2)
            if (A[1] > 3)
                return false;
        if (A[2] > 5)
            return false;
    }

    return true;
}

void findBest(vector<int> &A, int start, int &m)
{
    if (start == 3)
    {
        if (isValid(A))
        {
            m = max(findTime(A), m);
        }
    }
    else
    {
        for (int i = start; i < 4; i++)
        {
            swap(A[start], A[i]);
            findBest(A, start + 1, m);
            swap(A[i], A[start]);
        }
    }
}

string largestTimeFromDigits(vector<int> &A)
{
    int m = -1;
    findBest(A, 0, m);
    if (m == -1)
        return "";
    else {
        string ans = to_string(m);
        while (ans.length()<4) {
            ans.insert(0,"0");
        }
        ans.insert(2,":");
        return ans;
    }    
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vector<int> A;
        for (int i = 0; i < 4; i++)
        {
            int v;
            cin >> v;
            A.push_back(v);
        }
        cout << largestTimeFromDigits(A);
    }
    return 0;
}
