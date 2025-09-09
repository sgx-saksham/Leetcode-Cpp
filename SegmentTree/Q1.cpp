#include <bits/stdc++.h>
using namespace std;

class SegmentTreeLazy
{
public:
    vector<int> s, lz;
    SegmentTreeLazy(int n)
    {
        s.resize(4 * n);
        lz.resize(4 * n);
    }
    void build(int ind, int low, int high, vector<int> v)
    {
        if (low == high)
        {
            s[ind] = v[low];
            return;
        }
        int mid = (low + high) >> 1;
        build((2 * ind + 1), low, mid, v);
        build((2 * ind + 2), mid + 1, high, v);
        s[ind] = s[(2 * ind + 1)] + s[(2 * ind + 2)];
    }
    void update(int ind, int low, int high, int l, int r, int val)
    {
        // No overlap
        if (high < l || r < low)
            return;
        // Partial overlap //update and propagate downwards
        if (lz[ind] != 0)
        {
            s[ind] += (high - low + 1) * lz[ind];
            // pro
            if (low != high)
            {
                lz[(2 * ind + 1)] += lz[ind];
                lz[(2 * ind + 2)] += lz[ind];
            }
            lz[ind] = 0;
        }
        // Complete Overlap
        if (l <= low && high <= r)
        {
            s[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lz[(2 * ind + 1)] += val;
                lz[(2 * ind + 2)] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update((2 * ind + 1), low, mid, l, r, val);
        update((2 * ind + 1), mid + 1, high, l, r, val);
        s[ind] = s[(2 * ind + 1)] + s[(2 * ind + 2)];
    }
    int query(int ind, int low, int high, int l, int r)
    {

        // update if any updates are remaining
        // as the node will stay fresh and updated
        if (lz[ind] != 0)
        {
            s[ind] += (high - low + 1) * lz[ind];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if (low != high)
            {
                lz[2 * ind + 1] += lz[ind];
                lz[2 * ind + 2] += lz[ind];
            }

            lz[ind] = 0;
        }

        // no overlap return 0;
        if (high < l or r < low)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return s[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void Solve()
{
    int n1, q;
    cin >> n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; i++)
        cin >> v1[i];
    SegmentTreeLazy t(n1);
    t.build(0, 0, n1 - 1, v1);
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << t.query(0, 0, n1 - 1, l, r) << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            t.update(0, 0, n1 - 1, l, r, val);
        }
    }

    // int n2;
    // cin >> n2;
    // vector<int> v2(n2);
    // for (int i = 0; i < n2; i++)
    //     cin >> v2[i];
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