#include <iostream>
using namespace std;
int n, t;
string str;
int arr[21];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("add") == 0) {
			cin >> t;
			arr[t] = 1;
		}
		else if (str.compare("remove") == 0) {
			cin >> t;
			arr[t] = 0;
		}
		else if (str.compare("check") == 0) {
			cin >> t;
			if (arr[t] == 1) cout << "1\n";
			else cout << "0\n";
		}
		else if (str.compare("toggle") == 0) {
			cin >> t;
			if (arr[t] == 1) arr[t] = 0;
			else arr[t] = 1;

		}
		else if (str.compare("all") == 0) for (int i = 1; i <= 20; i++) arr[i] = 1;
		else if (str.compare("empty") == 0) for (int i = 1; i <= 20; i++) arr[i] = 0;
	}
	return 0;
}	

