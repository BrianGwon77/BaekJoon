#include <iostream>
#define MAX 1000001
using namespace std;

bool chk[MAX] = { false, };

void eratosthenes(int n) {

	chk[0] = chk[1] = true;

	for (int i = 2; i * i <= n; i++) {

		if (chk[i] == false) {

			for (int j = i * i; j <= n; j+=i) {

				chk[j] = true;

			}

		}

	}

}

int main() {

	int n;
	eratosthenes(MAX-1);

	while (1) {

		scanf("%d", &n);
		
		if (n == 0) break;

		for (int i = 2; i <= n-i; i++) {

			if (chk[i] == false && chk[n - i] == false) {
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}

		}
	}

	return 0;
}