#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int dp[1000];
	int arr[1000];

	for (int i = 0; i < 1000; i++)
		dp[i] = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int idx = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				idx = (dp[i] > dp[idx]) ? i : idx;
			}
		}
	}

	stack<int> st;

	// 최장 증가하는 수열의 길이 dp[idx].

	cout << dp[idx] << '\n';

	int num = dp[idx];

	// 최장 증가하는 수열의 마지막 값 arr[idx] 을 stack에 push
	st.push(arr[idx]);
	
	// 최장 증가하는 수열 길이 1 감소
	num--;

	for (int i = idx-1; i >= 0; i--) {

		if (num == 0) break;

		if (dp[i] == num && arr[i] < arr[idx]) {
			num--;
			st.push(arr[i]);
			idx = i;
		}
	}

	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}