#include<bits/stdc++.h>
using namespace std;
int fr[26];

bool cat1(string s)
{
    for(int i=0;i<s.size();i++){
            bool f=0;
            int as=s[i]-'a';
    for(int ch='a';ch<='m';ch++)
    {
        if((ch-97)==as)f=1;
    }
    if(!f){
        return false;
        break;
    }
    }
    return true;
}

bool cat2(string s)
{
    char st[]={'a','e','i','o','u'};
    for(int i=0;i<5;i++){
        for(int j=0;j<s.size();j++)
        {
            if(st[i]==s[j]){
                return false;
                break;
            }
        }
    }
    if(s.size()==6)return false;
    return true;
}

bool cat3(string s)
{
    char st[]={'a','e','i','o','u'};
    bool f=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<s.size();j++)
        {
            if(st[i]==s[j]){
                f=1;
                break;
            }
        }
    }
    int len=s.size();
    if(f || len!=6)return false;
    else return true;
}

bool cat4(string s)
{
   if(s[0]!='a')return false;
   int len=s.size();
   if(len>5)return false;
   if(s[len-2]!='d' || s[len-1]!='e')return false;
   if(len==3){
    if(s=="ade")return true;
    else return false;
   }
   if(len==5){
    if(s=="abcde")return true;
    else return false;
   }

   return false;
}



int main()
{
    string s;
    cin>>s;
    int len=s.size();

    while(1){
        if(cat1(s))
        {
            cout<<"valid with category one"<<endl;
            break;
        }
       if(cat2(s)){
            cout<<"valid with category two"<<endl;
            break;
        }
         if(cat3(s)){
            cout<<"valid with category three"<<endl;
            break;
        }
        if(cat4(s)){
            cout<<"valid with category four"<<endl;
            break;
        }
        cout<<"Invalid"<<endl;
        break;
    }



    return 0;
}
