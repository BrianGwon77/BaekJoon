#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	int t;
	string str;
	stack<char> st;

	cin >> t;

	while (t--) {

		cin >> str;

		for (int i = 0; i < str.size(); i++) 
		{

			char token = str.at(i);

			if (token == '(')
				st.push(token);

			else 
			{
				if (st.empty())
				{
					st.push(')');
					break;
				}

				else 
					st.pop();
			}

		}

		if (!st.empty()) cout << "NO\n";

		else cout << "YES\n";

		while (!st.empty())
			st.pop();

	}

	return 0;
}