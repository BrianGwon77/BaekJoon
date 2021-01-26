#include <iostream>
#define MAX_RESULT 100001
#define MAX_USUABLE 4
using namespace std;

int n, t;
int dp[MAX_RESULT][MAX_USUABLE];

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < MAX_RESULT; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0;
	}

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	// 마지막 수가 1,2,3 으로 끝난 경우
	/*
		dp[n][1] = dp[n-1][2] + dp[n-1][3]
		dp[n][2] = dp[n-2][1] + dp[n-2][3]
		dp[n][3] = dp[n-3][1] + dp[n-3][2]
	*/

	for (int i = 4; i < MAX_RESULT; i++) {

		dp[i][1] = ((dp[i - 1][2] % 1000000009) + (dp[i - 1][3] % 1000000009)) % 1000000009;
		dp[i][2] = ((dp[i - 2][1] % 1000000009) + (dp[i - 2][3] % 1000000009)) % 1000000009;
		dp[i][3] = ((dp[i - 3][1] % 1000000009) + (dp[i - 3][2] % 1000000009)) % 1000000009;

	}

	cin >> t;

	while (t--) {

		cin >> n;
		cout << (((dp[n][1] % 1000000009) + (dp[n][2] % 1000000009)) % 1000000009 + (dp[n][3] % 1000000009)) % 1000000009 << '\n';

	}

	return 0;
}