#include<bits/stdc++.h>
using namespace std;
stack<char>opp;
stack<int>res;
map<char, int>pres, invalid;
bool check1(string s)
{
    int l = s.size();
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[l - 1] == '+'
            || s[l - 1] == '-' || s[l - 1] == '*' || s[l - 1] == '/')return false;
    else return true;
}

bool check2(string s)
{
    int sz = s.size();
    for (int i = 1; i < sz; i++)
    {
        if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') &&
                (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/')) {
            return false;
            break;
        }
    }
    return true;
}

bool check3(string s)
{
    int sz = s.size();
    for (int i = 1; i < sz; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') &&
                (s[i - 1] >= 'a' && s[i - 1] <= 'z')) {
            return false;
            break;
        }
    }
    return true;
}

string space_string(string s)
{
    string pp;
    for (char ch : s)
    {
        if (ch != ' ')pp += ch;
    }
    return pp;
}

int get_res(int a, int b, char ch)
{
    if (ch == '+')return a + b;
    if (ch == '-')return a - b;
    if (ch == '*')return a * b;
    else return a / b;
}

int main()
{

    pres['+'] = 1; pres['-'] = 2; pres['*'] = 3; pres['/'] = 4;

    int n;
    cin >> n;
    map<char, int>mp;

    std::vector<char> vk;
    for (int i = 0; i < n; i++) {
        char c, ch; int val;
        cin >> c >> ch >> val;
        vk.push_back(c);
        mp[c] = val;
        pres[c] = 1;
        invalid[c] = 1;
    }
    vector<string>mmain;
    vector<int>vv, inv;
    set<char>st1;
    bool ff = 0;
    int m; cin >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        string pp; getline(cin, pp);
        pp = space_string(pp);
        mmain.push_back(pp);
        int cnt = 0;
        for (auto cc : pp) {
            if (cc >= 'a' && cc <= 'z')vv.push_back(cc);
        }

        for (int x : vv)
        {
            if (invalid[x] == 0)inv.push_back(i);
        }

        vv.clear();

    }

    bool f = false, sgn = false;

    for (auto it : mmain)
    {
        string ex = it;
        f=false;sgn=true;

        for (int i = 0; i < ex.size(); i++) {
            if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/')
            {
                if (sgn)
                {
                    f = true;
                    //break;
                }

                while (!opp.empty() && pres[opp.top()] > pres[ex[i]])
                {
                    auto t = opp.top();
                    opp.pop();
                    auto a = res.top();
                    res.pop();
                    auto b = res.top();
                    res.pop();
                    auto c = get_res(b, a, t);
                    res.push(c);
                }
                opp.push(ex[i]);
                sgn = true;
            }
            else if (pres[ex[i]])
            {
                if (!sgn)
                {
                    f = true;
                    //break;
                }
                res.push(mp[ex[i]]);
                sgn=false;
            }
            else
            {
                f = true;
                //break;
            }
        }

        if(f)
            cout<<"Compilation Error\n";
        else{
        while (!opp.empty()) {
            auto t = opp.top();
            opp.pop();
            auto a = res.top();
            res.pop();
            auto b = res.top();
            res.pop();
            auto c = get_res(b, a, t);
            res.push(c);
        }

        cout << res.top() << endl;

    }
}

return 0;

}

/*
3
a = 1
b = 2
c = 2
2
a * b + a * c + b * c
a * c - b / c + c * c

4
g = 2
p = 3
t = 1
w = 2
3
g + p * t - w * p
t - g + t - w
e + t * t - m
*/
