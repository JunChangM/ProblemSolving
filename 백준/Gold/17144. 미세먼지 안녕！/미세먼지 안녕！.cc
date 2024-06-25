#include <iostream>
using namespace std;
/*
공기청정기 성능 테스트
집 크기 R * C 격자판
(r,c)
1. 공기 청정기 항상 1번 열에 설치
2. 공기청정기 크기는 두 행 차지
3. 공기청정기 없는 칸에는 미세먼지, 미세먼지 양 줌

1초 마다 아래 반복
1) 미세먼지 확산. 네 방향으로 확산. 공기청정기가 있거나 칸 없으면 확산 X
    확산되는 양 A/5 (소수점 버림) 남은 미세먼지 양 계산 기존 - 확산양 * 확산 수
2) 공기청정기 작동
    위쪽 바람은 반시계, 아래쪽 바람은 시계
    바람이 불면 미세먼지가 바람의 방향대로 한 칸 이동
    공기청정기로 들어간 미세먼지는 모두 정화

첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 
둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)

첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력

7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

출력
188
*/


int R,C,T;
int a = -1;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[50][50];

void input_data(){
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
            if (map[i][j] == -1 && a == -1){
                a = i;
            }
        }
    }
}

void spread(){
    int temp[50][50];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            temp[i][j] = map[i][j];
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){

            if (map[i][j] == -1) continue;

            int dust = temp[i][j];
            int spread_dust = dust/5;

            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (map[nx][ny] == -1 ) continue;
                map[nx][ny] += spread_dust;
                map[i][j] -= spread_dust;
            }
        }
    }
}

void airconditioner(){
    // (a,0) (a+1,0)
    
    // up
    for(int i = a - 1; i>= 1; i--) map[i][0] = map[i-1][0];
    for(int i = 0; i<= C-2; i++) map[0][i] = map[0][i+1];
    for(int i=0; i<a; i++) map[i][C-1] = map[i+1][C-1];
    for(int i=C-1; i>=2; i--) map[a][i] = map[a][i-1];
    map[a][1] = 0;

    // down
    int b = a+1;
    for(int i = b+1; i<=R-2; i++) map[i][0] = map[i+1][0];
    for(int i = 0; i<= C-2; i++) map[R-1][i] = map[R-1][i+1];
    for(int i=R-1; i>b; i--) map[i][C-1] = map[i-1][C-1];
    for(int i=C-1; i>=2; i--) map[b][i] = map[b][i-1];
    map[b][1] = 0;
}

void process(){
    for(int i=0; i<T; i++){
        spread();
        airconditioner();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input_data();
    process();
    int ans = 2;
     for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            ans += map[i][j];
        }
    }
    cout << ans;
}