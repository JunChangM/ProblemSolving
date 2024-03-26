#include <iostream>
#include <cmath>
using namespace std;

string s;
char a; 
long long M = 1234567891; 
int main(){
    int L;
    long long h = 0;
    scanf("%d",&L);
    cin >> s;

    long long r = 1;
    for(int i=0; i<L; i++){
        a = s[i];
        h = (h + (a - 96) * r) % M; // (a * r) mod M
        r = (r * 31) % M;
    }

    printf("%lld\n", h);

    return 0;
}
