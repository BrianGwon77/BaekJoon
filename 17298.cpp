#include <iostream>
#include <stack>
#define MAX 10000000
using namespace std;

int arr[MAX];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	stack<int> st;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> arr[i];

		while (!st.empty() && arr[st.top()] < arr[i]) {
			
			arr[st.top()] = arr[i];
			st.pop();

		}

		st.push(i);

	}

	while (!st.empty()) {
		arr[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	return 0;
}