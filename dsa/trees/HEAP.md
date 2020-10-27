# Binary Heap
A min heap is a binary tree in which the value of each vertex is less than or equal to the values of its children. Thus the minimum of the tree is always in the root vertex.

## Structure
```cpp
// Min Heap
// Reverse the compare operators for max heap
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
        return (arr.size() == 0);
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
        // child is less than parent
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
```

## Table of Contents
- [K largest elements](#k-largest-elements)
- [Nearly Sorted Algorithm](#nearly-sorted-algorithm)
- [Find Median from Data Stream](#find-median-from-data-stream)
- [Merge k Sorted Arrays](#merge-k-sorted-arrays)

<div id="k-largest-elements">

## K largest elements
https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
```cpp
vector<int> kLargest(int arr[], int n, int k)
{
    vector<int> large;
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);
    while (k-- > 0)
    {
        large.push_back(pq.top());
        pq.pop();
    }
    return large;
}
```
</div>

<div id="nearly-sorted-algorithm">

## Nearly Sorted Algorithm
https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
```cpp
vector<int> sortKsortedArr(vector<int> nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
        pq.push(nums[i]);
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
```
</div>

<div id="find-median-from-data-stream">

## Find Median from Data Stream
https://leetcode.com/problems/find-median-from-data-stream/
```cpp
class MedianFinder
{
private:
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        L.push(num);
        R.push(L.top());
        L.pop();
        if (R.size() > L.size())
        {
            L.push(R.top());
            R.pop();
        }
    }

    double findMedian()
    {
        if (!L.empty() && !R.empty() && L.size() == R.size())
            return 1.0 * (L.top() + R.top()) / 2;
        else
            return L.empty() ? -1 : L.top();
    }
};
```
</div>

<div id="merge-k-sorted-arrays">

## Merge k Sorted Arrays
https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
```cpp
class pii
{
public:
    int first, second, third;
    pii(int first, int second, int third) : first(first), second(second), third(third) {}
};

bool operator<(const pii &p1, const pii &p2)
{
    return (p1.first > p2.first);
}

vector<int> mergeKsortedArr(vector<vector<int>> &arr, int k)
{
    priority_queue<pii> pq;
    vector<int> nums;
    for (int i = 0; i < k; i++)
        pq.push(pii(arr[i][0], i, 0));
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        nums.push_back(cur.first);
        if (arr[cur.second].size() - 1 > cur.third)
            pq.push(pii(arr[cur.second][cur.third + 1], cur.second, cur.third + 1));
    }
    return nums;
}
```
</div>