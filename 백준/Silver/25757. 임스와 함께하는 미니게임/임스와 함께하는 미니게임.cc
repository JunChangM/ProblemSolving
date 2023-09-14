#include <iostream>
#include <map>
using namespace std;
char c;
int n, idx;
string str;
map<string, int> myMap;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c;
	while (n--) {
		cin >> str;
		if (myMap.find(str) == myMap.end()) {
			myMap.insert(pair<string, int>(str, 1));
		}
		else {
			myMap[str]++;
		}
	}
	idx = myMap.size();
	int ans = 0;
	if (c == 'Y') ans = idx ;
	else if (c == 'F') ans = idx / 2;
	else if (c == 'O') ans = idx / 3;
	cout << ans;
	return 0;
}	