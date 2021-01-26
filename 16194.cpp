#include <iostream>
#include <memory.h>
#include <algorithm>
#define INT_MAX 2147483647
#define MAX 1001
using namespace std;

void init(int *arr) {
	for (int i = 0; i < MAX; i++) {
		arr[i] = INT_MAX/2;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int dp[MAX];
	int price[MAX];
	init(dp);
	memset(price, 0, sizeof(price));
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}

	dp[0] = 0;
	dp[1] = price[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - j >= 0)
				dp[i] = min(dp[i], dp[i - j] + price[j]);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}