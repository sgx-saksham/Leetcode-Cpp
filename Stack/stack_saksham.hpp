#include <bits/stdc++.h>
using namespace std;

// Nearest Greater to Right
vector<int> NGR(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            k.push_back(-1);
        else if ((!st.empty()) && st.top() > v[i])
            k.push_back(st.top());
        else if ((!st.empty()) && st.top() <= v[i])
        {
            while ((!st.empty()) && st.top() <= v[i])
                st.pop();
            if (st.empty())
                k.push_back(-1);
            else
                k.push_back(st.top());
        }
        st.push(v[i]);
    }
    reverse(k.begin(), k.end());
    return k;
}

// Nearest Greater to Left
vector<int> NGL(vector<int> v)
{
    vector<int> l;
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
            l.push_back(-1);
        else if ((!st.empty()) && st.top() > v[i])
            l.push_back(st.top());
        else if ((!st.empty()) && st.top() <= v[i])
        {
            while ((!st.empty()) && st.top() <= v[i])
                st.pop();
            if (st.empty())
                l.push_back(-1);
            else
                l.push_back(st.top());
        }
        st.push(v[i]);
    }
    return l;
}

// Nearest Smaller to Left
vector<int> NSL(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.size() == 0)
            k.push_back(-1);
        else if ((!st.empty()) && st.top() < v[i])
            k.push_back(st.top());
        else if ((!st.empty()) && st.top() >= v[i])
        {
            while ((!st.empty()) && st.top() >= v[i])
                st.pop();
            if (st.size() == 0)
                k.push_back(-1);
            else
                k.push_back(st.top());
        }
        st.push(v[i]);
    }
    return k;
}

// Nearest Smaller to Right
vector<int> NSR(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            k.push_back(-1);
        else if ((!st.empty()) && st.top() < v[i])
            k.push_back(st.top());
        else if ((!st.empty()) && st.top() >= v[i])
        {
            while ((!st.empty()) && st.top() >= v[i])
                st.pop();
            if (st.empty())
                k.push_back(-1);
            else
                k.push_back(st.top());
        }
        st.push(v[i]);
    }
    reverse(k.begin(), k.end());
    return k;
}

// Nearest Greater to Left Index
vector<int> NGL_ind(vector<int> v)
{
    vector<int> l;
    stack<int> st;
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            l.push_back(-1);
        else if (s.top().first > v[i] && !s.empty())
            l.push_back(s.top().second);
        else if (s.top().first <= v[i] && !s.empty())
        {
            while (s.top().first <= v[i] && !s.empty())
                s.pop();
            if (s.empty())
                l.push_back(-1);
            else
                l.push_back(s.top().second);
        }
        s.push({v[i], i});
    }

    return l;
}

// Nearest Greater to Right Index
vector<int> NGR_ind(vector<int> v)
{
    vector<int> l;
    stack<pair<int, int>> s;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.empty())
            l.push_back(-1);
        else if ((!s.empty()) && s.top().first > v[i])
            l.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first <= v[i])
        {
            while ((!s.empty()) && s.top().first <= v[i])
                s.pop();
            if (s.empty())
                l.push_back(-1);
            else
                l.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    reverse(l.begin(), l.end());
    return l;
}

// Nearest Smaller to Left Index
vector<int> NSL_ind(vector<int> v)
{
    vector<int> k;
    stack<int> st;
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            k.push_back(-1);
        else if ((!s.empty()) && s.top().first < v[i])
            k.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first >= v[i])
        {
            while ((!s.empty()) && s.top().first >= v[i])
                s.pop();
            if (s.empty())
                k.push_back(-1);
            else
                k.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    return k;
}

// Nearest Smaller to Right Index
vector<int> NSR_ind(vector<int> v)
{
    vector<int> k;
    int n = v.size();
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            k.push_back(n);
        else if ((!s.empty()) && s.top().first < v[i])
            k.push_back(s.top().second);
        else if ((!s.empty()) && s.top().first >= v[i])
        {
            while ((!s.empty()) && s.top().first >= v[i])
                s.pop();
            if (s.empty())
                k.push_back(n);
            else
                k.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    reverse(k.begin(), k.end());
    return k;
}