#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	stack<char> st;

	cin >> t;
	getline(cin, str); // \n 개행문자 제거

	while (t--) {

		getline(cin, str);

		for (int i = 0; i < str.size(); i++) {

			char token = str.at(i);

			if (token == ' ') {

				while (!st.empty()) {
					std::cout << st.top();
					st.pop();
				}

				std::cout << ' ';

			}

			else
				st.push(token);
				 
		}

		while (!st.empty()) {
			std::cout << st.top();
			st.pop();
		}

		std::cout << '\n';

	}
	
	return 0;
}