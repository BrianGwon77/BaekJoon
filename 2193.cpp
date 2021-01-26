#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long dp[91][2];

	for (int i = 0; i < 91; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 0;
		}
	}

	dp[1][1] = 1;

	for (int i = 2; i < 91; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}

	cin >> n;

	cout << dp[n][0] + dp[n][1] << '\n';

	return 0;
}