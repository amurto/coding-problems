#include <bits/stdc++.h>
using namespace std;

class heap
{
private:
    vector<int> arr;
    void heapify(int cur)
    {
        // check left child and right child
        int L = 2 * cur + 1, R = 2 * cur + 2, smallest = cur;
        if (L < arr.size() && arr[L] < arr[cur])
            smallest = L;
        if (R < arr.size() && arr[R] < arr[smallest])
            smallest = R;

        // call heapify again if current element is smallest
        if (smallest != cur)
        {
            swap(arr[cur], arr[smallest]);
            heapify(smallest);
        }
    }

public:
    int size()
    {
        return arr.size();
    }
    bool empty()
    {
        return (arr.size() > 0);
    }
    int top()
    {
        // O(1)
        if (arr.empty())
            return -1;
        return arr[0];
    }
    void show()
    {
        for (int val : arr)
            cout << val << " ";
        cout << "\n";
    }

    void push(int val)
    {
        // O(1)
        // Push to end of array
        arr.push_back(val);
        int cur = arr.size() - 1;
        // O(logn)where n is size of heap
        // upheapify
        // keep moving new element while heap property does not hold
        // child is less than property
        while (cur > 0 && arr[(cur - 1) / 2] > arr[cur])
        {
            swap(arr[cur], arr[(cur - 1) / 2]);
            cur = (cur - 1) / 2;
        }
    }

    void pop()
    {
        // O(logn)
        if (arr.empty())
            return;
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        // if arr is empty, return
        if (arr.empty())
            return;
        heapify(0);
    }
};

int main()
{
    return 0;
}

