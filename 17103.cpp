#include <iostream>
#define MAX 1000001
using namespace std;

bool isPrime[MAX];

void eratosthenes() {

	for (int i = 2; i*i < MAX; i++) {
		
		if (isPrime[i]) {
			for (int j = i * 2; j< MAX; j+=i) {
				isPrime[j] = false;
			}
		}

	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(isPrime, true, sizeof(isPrime));
	eratosthenes();

	int t;
	cin >> t;

	while (t--) {

		int num;
		int res = 0;
		cin >> num;


		for (int i = 2; i <= num - i; i++) {
			if (isPrime[i] && isPrime[num - i])
				res++;
		}

		cout << res << '\n';

	}


	return 0;
}