#include <iostream>
using namespace std;

int dp[105][10];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = 0;
		}
	}

	dp[2][0] = 1;

	for (int i = 1; i < 10; i++) {
		
		dp[1][i] = 1;

		if (i == 1 || i == 9) 
			dp[2][i] = 1;
		else 
			dp[2][i] = 2;

	}

	for (int i = 3; i < 105; i++) {
		for (int j = 0; j < 10; j++) {

			if (j + 1 <= 9)
				dp[i][j] = ((dp[i][j] % 1000000000) + (dp[i - 1][j + 1] % 1000000000)) % 1000000000;
			if (j-1 >= 0)
				dp[i][j] = ((dp[i][j] % 1000000000) + (dp[i - 1][j - 1] % 1000000000)) % 1000000000;

		}
	}

	int sum = 0;
	
	for (int i = 0; i < 10; i++)
		sum = ((sum % 1000000000) + (dp[n][i] % 1000000000)) % 1000000000;

	cout << (sum % 1000000000) << '\n';

	return 0;
}