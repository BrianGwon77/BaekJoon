#include <iostream>
#include <algorithm>
#define MAX_STAIR 301
#define MAX_STRAIGHT 3
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int point[MAX_STAIR];
	int dp[MAX_STAIR][MAX_STRAIGHT];

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> point[i];
	}

	for (int i = 0; i < MAX_STAIR; i++) {
		for (int j = 0; j < MAX_STRAIGHT; j++) {
			dp[i][j]= 0;
		}
	}

	dp[1][1] = point[1];
	dp[1][0] = dp[1][2] = 0;
	
	for (int i = 2; i <= n; i++) {

		for (int j = 0; j < MAX_STRAIGHT; j++) {
			
			if (j == 0)
				dp[i][j] = max(dp[i-1][2], dp[i-1][1]);

			else if (j == 1)
				dp[i][j] = dp[i-1][0] + point[i];

			else
				dp[i][j] = dp[i-1][1] + point[i];

		}
	}

	cout << max(dp[n][1], dp[n][2]) << '\n';

	
	return 0;
}