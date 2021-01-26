#include <iostream>
#define MAX 5001
using namespace std;

// �̹� ���ŵ� ���Ҹ� üũ�ϴ� �� �ð��� ���� �ɸ��� ������? 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool arr[MAX] = { false, };
	arr[0] = true;

	int n, k;
	int current = 0;
	cin >> n >> k;

	cout << '<';

	for (int i = 1; i < n; i++) {
		
		int cnt = 0;

		while (cnt != k)
		{
			current++;
			if (arr[(current) % (n+1)] == false) cnt++;
		}

		arr[(current) % (n + 1)] = true;

		cout << (current) % (n + 1) << ", ";

	}

	for (int i = 1; i <= n; i++)
		if (arr[i] == false) cout <<  i << '>';


	return 0;
}