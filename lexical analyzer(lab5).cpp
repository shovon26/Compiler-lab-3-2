#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
void pre_cal()
{
    mp["++"]="unary";
    mp["--"]="unary";

    mp["+"]="arithmetic";
    mp["-"]="arithmetic";
    mp["*"]="arithmetic";
    mp["/"]="arithmetic";

    mp["<"]="Relational";
    mp["<="]="Relational";
    mp[">"]="Relational";
    mp[">="]="Relational";
    mp["=="]="Relational";
    mp["!="]="Relational";

    mp["&&"]="logical";
    mp["||"]="logical";
    mp["!"]="logical";

    mp["&"]="Bitwise";
    mp["|"]="Bitwise";
    mp["<<"]="Bitwise";
    mp[">>"]="Bitwise";
    mp["~"]="Bitwise";
    mp["^"]="Bitwise";

    mp["="]="Assignment";
    mp["+="]="Assignment";
    mp["-="]="Assignment";
    mp["*="]="Assignment";
    mp["/="]="Assignment";
    mp["%="]="Assignment";

    mp["?:"]="Ternary";
}
int main()
{
    pre_cal();
   // freopen("input.txt","r",stdin);
    string s,p;
    vector<string >un,ar,rel,log,bit,ass,ter;
    while(cin>>p)
    {
        s+=" ";
        s+=p;
    }
    map<string,vector<string>>v;
    stringstream str(s);
    while(str >> p)
    {
        //cout<<p<<endl;
        if(mp.find(p)!=mp.end())
        {
            v[mp[p]].push_back(p);
        }
    }
    for(auto x:v)
    {
        cout<<x.first<<" ";
        for(auto z:x.second)cout<<z<<" "<<endl;
    }
    return 0;
}

