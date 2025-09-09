/*
1
5
10 1 5 8 3
5
3 12 2 10 3
5
1 0 3 1 4
2 2 2 12
2 1 3 18
1 0 3 1 4
1 0 4 0 4
*/
#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> seg;
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, vector<int> v)
    {
        if (low == high)
        {
            seg[ind] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build((2 * ind + 1), low, mid, v);
        build((2 * ind + 2), mid + 1, high, v);
        // seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        // l r low high || low high l r

        if (r < low || high < l)
            // for max
            return INT_MIN;
        // for min
        // return INT_MAX;

        // Complete Overlap
        // l low high r
        if (low >= l && high <= r)
            return seg[ind];
        // partial overlap

        int mid = (low + high) >> 1;
        int left = query((2 * ind + 1), low, mid, l, r);
        int right = query((2 * ind + 2), mid + 1, high, l, r);
        // return min(left, right);
        return max(left, right);
        // return left+right
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update((2 * ind + 1), low, mid, i, val);
        else
            update((2 * ind + 2), mid + 1, high, i, val);
        // seg[ind] = min(seg[(2 * ind + 1)], seg[(2 * ind + 2)]);
        seg[ind] = max(seg[(2 * ind + 1)], seg[(2 * ind + 2)]);
    }
};

void Solve()
{
    int n1;
    cin >> n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; i++)
        cin >> v1[i];
    SegmentTree t1(n1);
    t1.build(0, 0, n1 - 1, v1);

    int n2;
    cin >> n2;
    vector<int> v2(n2);
    for (int i = 0; i < n2; i++)
        cin >> v2[i];
    SegmentTree t2(n2);
    t2.build(0, 0, n2 - 1, v2);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int min1 = t1.query(0, 0, n1 - 1, l1, r1);
            int min2 = t2.query(0, 0, n2 - 1, l2, r2);
            cout << max(min1, min2) << endl;
        }
        else
        {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;
            if (arrNo == 1)
                t1.update(0, 0, n1 - 1, i, val);
            else
                t2.update(0, 0, n2 - 1, i, val);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        Solve();
}