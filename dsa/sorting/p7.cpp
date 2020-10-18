// Sort Dates

#include <bits/stdc++.h>
using namespace std;

struct Date
{
    string fulldate;
    int day, mon, year;
    Date(string fd) : fulldate(fd)
    {
        int d = stoi(fd);
        year = d % 10000;
        d /= 10000;
        mon = d % 100;
        d /= 100;
        day = d;
    }
};

bool compare(Date *d1, Date *d2)
{
    if (d1->year == d2->year)
        if (d1->mon == d2->mon)
            return (d1->day < d2->day);
        else
            return (d1->mon < d2->mon);
    else
        return (d1->year < d2->year);
}

int main()
{
    string fd;
    int n, d, m, y;
    cin >> n;
    vector<Date *> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fd;
        arr[i] = new Date(fd);
    }
    sort(arr.begin(), arr.end(), compare);
    for (Date *date : arr)
        cout << date->fulldate << "\n";
    return 0;
}