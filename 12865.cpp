#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[101][100001];
int w[101], v[101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 100001; j++) {
			a[i][j] = 0;
		}
	}

	for (int i=w[1]; i<=k; i++)
		a[1][i] = v[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {

			a[i][j] = a[i - 1][j];
			if (j - w[i] >= 0) a[i][j] = max(a[i][j], a[i - 1][j - w[i]] + v[i]);

 		}
	}

	cout << a[n][k] << '\n';

	return 0;
}