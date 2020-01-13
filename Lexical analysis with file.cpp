#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define unik(v)  v.erase(unique(v.begin(),v.end()),v.end())
vector<string>key, num, iden, math, logic, other;
string keyword[32] = {"auto", "break", "case", "char", "const", "continue", "default",
                      "do", "double", "else", "enum", "extern", "float", "for", "goto",
                      "if", "int", "long", "register", "return", "short", "signed",
                      "sizeof", "static", "struct", "switch", "typedef", "union",
                      "unsigned", "void", "volatile", "while"
                     };

string mathOp[6] = {"+", "-", "*", "/", "%", "="};
string logicOp[7] = {">", "<", ">=", "<=", "!", "!=", "=="};

bool is_keyword(string s)
{
	for (int i = 0; i < 32; i++)
	{
		if (keyword[i] == s) {
			return true;
			break;
		}
	}
	return false;
}

bool is_mathOp(string s)
{
	for (int i = 0; i < 6; i++)
	{
		if (mathOp[i] == s) {
			return true;
			break;
		}
	}
	return false;
}
bool is_logicOp(string s)
{
	for (int i = 0; i < 7; i++)
	{
		if (logicOp[i] == s) {
			return true;
			break;
		}
	}
	return false;
}
bool is_identifier(string s)
{
	if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))return true;
	else return false;
}

bool is_number(string s)
{
	if ((s[0] >= '0' && s[0] <= '9'))return true;
	else return false;
}


void print()
{
	sort(all(key));
	unik(key);

	sort(all(iden));
	unik(iden);

	sort(all(math));
	unik(math);

	sort(all(logic));
	unik(logic);

	sort(all(num));
	unik(num);

	sort(all(other));
	unik(other);

	cout << "keyword :: "; for (auto x : key)cout << x << "  ";
	cout << "\n";

	cout << "Identifiers :: "; for (auto x : iden)cout << x << "  ";
	cout << "\n";

	cout << "Math Operators :: "; for (auto x : math)cout << x << "  ";
	cout << "\n";

	cout << "Logical Operators :: "; for (auto x : logic)cout << x << "  ";
	cout << "\n";

	cout << "Numbers :: "; for (auto x : num)cout << x << "  ";
	cout << "\n";

	cout << "Others :: "; for (auto x : other)cout << x << "  ";
	cout << "\n";
}

int main()
{

	string input, str, tmp, s;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin >> s)
	{
		input += " ";
		input += s;
	}

	stringstream ss(input);
	while (ss >> str)
	{
		if (str.back() == ',' || str.back() == ';')
		{
			tmp.clear();
			tmp.push_back(str.back());
			other.push_back(tmp);
			str.pop_back();
		}

		if (is_keyword(str))key.push_back(str);
		else if (is_identifier(str))iden.push_back(str);
		else if (is_number(str))num.push_back(str);
		else if (is_mathOp(str))math.push_back(str);
		else if (is_logicOp(str))logic.push_back(str);
		else other.push_back(str);
	}

	print();

	return 0;
}

