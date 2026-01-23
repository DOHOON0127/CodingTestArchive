#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main()
{
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        map<string, int> mp;
        cin >> n;

        for (int j = 1; j <= n; j++)
        {
            cin >> a >> b;
            mp[b]++;
        }
        long long ret = 1;

        for (auto c : mp)
        {
            ret *= ((long long)c.second + 1);
        }

        ret--;

        cout << ret << '\n';
    }
    return 0;
}