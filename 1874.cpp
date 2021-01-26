#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int tot = 0;
	bool chk = true;

	cin >> n;

	stack<int> st;
	vector<char> res;

	for (int i = 0; i < n; i++) 
	{

		int num;
		cin >> num;

		while (tot < num) 
		{
			st.push(++tot);
			res.push_back('+');
		}

		if (st.top() != num) 
		{
			chk = false;
			break;
		}
		
		else 
		{
			st.pop();
			res.push_back('-');
		}
	}

	if (!chk) cout << "NO\n";
	
	else 
	{
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << '\n';
		}
	}

	return 0;
}