#include <iostream>
#include <memory.h>
#define MAX 1001
using namespace std;

// top-down & bottom-up

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int dp[MAX];
	memset(dp, 0, sizeof(dp));
	cin >> n;

	dp[0] = dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = (2 * dp[i - 2] % 10007) + (dp[i - 1] % 10007);
	}
	
	cout << dp[n] % 10007 << '\n';

	return 0;
}