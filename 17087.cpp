#include <iostream>
using namespace std;

int getGCD(int a, int b) {

	if (b == 0)
		return a;

	else
		return getGCD(b, a % b);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s, res;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		
		int locate;
		cin >> locate;

		locate = (locate > s) ? locate - s : s - locate;

		if (i == 0) {
			res = locate;
			continue;
		}

		res = getGCD(locate, res);

	}

	cout << res << '\n';

	return 0;
}