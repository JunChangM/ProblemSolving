#include <iostream>
using namespace std;
void star(int i, int j, int num)
{
    // 해당 좌표를 num으로 나누었을 때, 나머지가 1이면 공백으로 둔다.
  
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else // num이 커서 나머지가 1이 나오지 않는다면
    {
        if (num / 3 == 0) // num이 1이면 * 출력
            cout << '*';
        else // 동일한 좌표에 대해 num 감소
            star(i, j, num / 3);
    }
}
int main() {
    int num;
    cin >> num;
    // 1. num * num 의 공간에  *과 ' '의 위치를 설정하자.
    for (int i = 0; i < num; i++) // 가로줄을 한 줄 씩 진행하며 비어 있어야할 위치를 찾고 출력한다.
    {
        for (int j = 0; j < num; j++) {
            star(i, j, num); // (i,j)의 위치에 star 가 올 수 있는지 확인하기
        }
        cout << '\n'; // 가로 한줄이 끝나면 개행
    }
}