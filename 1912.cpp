#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
#define MAX 100000
using namespace std;

int n;
long long dp[MAX], arr[MAX];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
		dp[i] = arr[i];


	long long res = -INT_MAX / 2;
	dp[1] = arr[1];

	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		res = max(dp[i], res);
	}

	cout << res << '\n';

	return 0;
}