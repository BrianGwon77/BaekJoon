#include <iostream> 
#include <algorithm>
using namespace std;

// top-down 방식 구현.

int dp[1000001];

int top_down(int n) {

	if (n == 1) return 0;

	if (dp[n] != -1) return dp[n];

	int res = top_down(n - 1) + 1;
	
	if (n % 3 == 0) res = min(res, top_down(n / 3) + 1);
	if (n % 2 == 0) res = min(res, top_down(n / 2) + 1);

	dp[n] = res;

	return res;

}


int main() {

	for (int i = 0; i < 1000001; i++)
		dp[i] = -1;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 정수입력
	int x;

	cin >> x;

	cout << top_down(x) << '\n';

	return 0;
}