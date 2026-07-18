#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() + 1;

        st.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}