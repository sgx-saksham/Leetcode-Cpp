// #include <bits/stdc++.h>
// using namespace std;

// // function to count such triplets
// int numTrip(vector<pair<int, int>> &points)
// {
//     int res = 0;
//     for (int i = 0; i < points.size(); ++i)
//     {
//         unordered_map<long, int> map(points.size());
//         for (int j = 0; j < points.size(); ++j)
//         {
//             if (j == i)
//                 continue;
//             int dy = points[i].second - points[j].second;

//             int dx = points[i].first - points[j].first;
//             int key = dy * dy;
//             key += dx * dx;
//             map[key]++;
//         }
//         for (auto &p : map)
//             res += p.second * (p.second - 1);
//     }
//     return res;
// }

// // Driver code
// int main()
// {
//     vector<pair<int, int>> mat = {{0, 0}, {1, 0}, {2, 0}};

//     // vector<pair<int, int>> mat = {{1, 2}, {4, 6}, {7, 8}};
//     cout << numTrip(mat);

//     return 0;
// }

#include <bits/stdc++.h>
#include <

using namespace std;

// Function to return the count of possible triplets
int countTriplets(int n, vector<pair<int, int>> points)
{
    set<pair<int, int>> pts;
    int ct = 0;

    // Insert all the points in a set
    for (int i = 0; i < n; i++)
        pts.insert(points[i]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int x = points[i].first + points[j].first;
            int y = points[i].second + points[j].second;

            // If the mid point exists in the set
            if (x % 2 == 0 && y % 2 == 0)
                if (pts.find(make_pair(x / 2, y / 2)) != pts.end())
                    ct++;
        }

    // Return the count of valid triplets
    return ct;
}

// Driver code
int main()
{
    vector<pair<int, int>> points = {{1, 2}, {4, 6}, {7, 8}};
    // vector<pair<int, int>> points = {{1, 1}, {2, 2}, {3, 3}};
    int n = points.size();
    cout << countTriplets(n, points);
}