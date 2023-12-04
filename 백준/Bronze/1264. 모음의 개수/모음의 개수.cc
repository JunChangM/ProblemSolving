#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	
	char mo[5] = { 'a','i','e','o','u' };
	while (getline(cin, str))
	{
		int ans = 0;
		if (!str.compare("#")) break;
		for (int i = 0; i < str.length(); i++) {
			char x = str.at(i);
			if (x <= 'Z') x += 32;
			for (int i = 0; i < 5; i++) {
				if (x == mo[i]) ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
