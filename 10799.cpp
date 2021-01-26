#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	string str;

	stack<char> st;

	cin >> str;



	for (int i = 0; i < str.size(); i++) {

		char token = str.at(i);

		if (token == '(') {

			char nextToken = str.at(i+1);

			if (nextToken == ')') {
				i++;
				cnt += st.size();
			}

			else
				st.push(token);
				
		}

		else if (token == ')') {
			st.pop();
			cnt++;
		}

	}

	cout << cnt << '\n';

	return 0;
}