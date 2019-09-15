#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


bool check(string s1, string s2)
{
	int M = s1.length();
	int N = s2.length();

	for (int i = 0; i <= N - M; i++) {
		int j;
		for ( j = 0; j < M; j++)
			if (s2[i + j] != s1[j])
				break;

		if (j == M)
		{
			return true;
			break;
		}
	}

	return false;
}
bool regex_match(string exp, string p)
{
	int len1 = exp.size();

	string ff = "";
	for (int i = 4; i < len1 - 1; i++)
	{
		if (exp[i] == '*') {
			for (int ss = 1; ss <= 4; ss++) {
				ff += exp[i - 1];
			}
		}
		else if (exp[i] == '+')
		{
			for (int ss = 1; ss <= 7; ss++) {
				ff += exp[i - 1];
			}
		}
		else if (exp[i] == '?')
		{
			ff += exp[i - 1];
		}
		else if (exp[i] == '^') {
			ff += "";
		}
		else if (exp[i] == '{')
		{
			int to = exp[i + 1] - '0';
			int st = exp[i - 4] - '0';
			int ed = exp[i - 2] - '0';
			string kk = "";
			for (int i = st; i <= ed; i++)
			{
				char ch = i + '0';
				kk += ch;
			}

			for (int i = 0; i < to; i++)ff += kk;

		}

	}

	if (check(p, ff))return true;
	else return false;


}
int main()
{

	int n; cin >> n;
	string s[100];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];     //////Expression
	}
	int m; cin >> m;
	string p[100];
	for (int i = 0; i < m; i++)
	{
		cin >> p[i];    /////text string
	}

	for (int i = 0; i < m; i++) {
		bool f = 0;
		for (int j = 0; j < n; j++) {
			regex b(s[j]);

			if (regex_match(p[i], b)) {
				cout << "YES, " << j + 1 << endl;
				f = 1;
			}
		}
		if (!f)
			cout << "NO, 0" << endl;
	}

	return 0;

}


/*2
ab*c*d
a*b(cd)+e?f
3
acccd
abbbbbcccc
bcdcdef






3
[a-c]{3}cab+(da)*f
db*a[^def]{2}gh
def[k-p]*p+
5
defkmnpmpp
acbcabbf
pqrstdd
dbaabggh
dbbbbamkgh*/
