#include <iostream>
#include <algorithm>
#define MAX 100001
#define INT_MAX 2147483647
using namespace std;

int dp[MAX];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < MAX; i++)
		dp[i] = INT_MAX / 2;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < MAX; i++) {
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	int n;
	cin >> n;

	cout << dp[n] << '\n';

	return 0;
}