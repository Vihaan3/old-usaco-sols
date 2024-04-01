#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool group = false;
    bool front = false;
    int num = 0;
    int out = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (group == false)
        {
            group = true;
            num = 0;
            if (s[i] == 'B')
            {
                front = true;
                continue;
            }
        }
        if (s[i] == 'A' && group == true)
        {
            num++;
        }
        if (group == true && s[i] == 'B')
        {
            out += num;
            num = 0;
            group = false;
        }
        
    }
    if (group == true && front == true)
    {
        out += num;
    }
    cout << out << endl;

}

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }

}
