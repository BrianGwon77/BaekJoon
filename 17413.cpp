#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str, '\n');

	str += ' ';

	stack<char> st;

	for (int i = 0; i < str.size(); i++) {

		char token = str.at(i);

		if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z')) {
			st.push(token);
		}

		else if (token == ' ') {

			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			if (i < str.size()-1)
				cout << ' ';

		}

		else if (token == '<') {

			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			while (i < str.size() && str.at(i) != '>') 
				cout << str.at(i++);

			cout << '>';

		}

	}

	return 0;
}