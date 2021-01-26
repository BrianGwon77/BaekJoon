#include <iostream>
#include <memory.h>
#define MAX 11
using namespace std;

int main() {

	int n, t;
	int dp[MAX];
	memset(dp, 0, sizeof(dp));
	cin >> t;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}