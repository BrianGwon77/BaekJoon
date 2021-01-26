#include <iostream>
#include <memory.h>
#include <algorithm>
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

	int res = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}

	cout << res << '\n';

	return 0;
}