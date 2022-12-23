#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
class segmentTree
{
private:
    int n = 0;
    vector<int> segment;
    vector<int> arr;

public:
    segmentTree(vector<int> arr)
    {
        int n = arr.size();
        this->arr = arr;
        segment.resize(4 * n, -1);
        createSegmentTree(0, 0, n - 1);
    }
    int createSegmentTree(int index, int low, int high)
    {
        if (low == high)
            return segment[index] = arr[low];
        int mid = (low + high) / 2;
        int ans = 0;
        ans = ans + createSegmentTree(2 * index + 1, low, mid);
        ans = ans + createSegmentTree(2 * index + 2, mid + 1, high);
        return segment[index] = ans;
    }
    int rangeQuery(int index, int left, int right, int l, int r)
    {
        if (right < l || left > r)
            return 0;
        if (left <= l && right >= r)
        {
            return segment[index];
        }
        int mid = (l + r) / 2;
        int ans = 0;
        ans = ans + rangeQuery(2 * index + 1, left, right, l, mid);
        ans = ans + rangeQuery(2 * index + 2, left, right, mid + 1, r);
        return ans;
    }
    void pointUpdate(int index, int left, int right, int i, int val)
    {
        if (left == right)
        {
            segment[index] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (i > mid)
        {
            pointUpdate(2 * index + 2, mid + 1, right, i, val);
        }
        else
            pointUpdate(2 * index + 1, left, mid, i, val);
        segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
    }
};

class NumArray
{
public:
    segmentTree *seg;
    int n = 0;
    NumArray(vector<int> &nums)
    {
        seg = new segmentTree(nums);
        n = nums.size();
    }

    void update(int index, int val)
    {
        seg->pointUpdate(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return seg->rangeQuery(0, left, right, 0, n - 1);
    }
};
int main()
{

    return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */