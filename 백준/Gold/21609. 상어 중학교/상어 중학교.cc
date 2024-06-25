#include <iostream>
using namespace std;

int n,m;
int map[20][20];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

typedef struct info{
    int standx;
    int standy;
    int count;
    int rainbow;
} info;

info find(int sx, int sy, int option){
    int queue [400][2];
    int visit[20][20] = {0,};
    int s = 0;
    int e = 1;
    int value = map[sx][sy];

    queue[0][0] = sx;
    queue[0][1] = sy;

    while(s != e){
        sx = queue[s][0];
        sy = queue[s][1];
        s++;

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (map[nx][ny] == -1 || map[nx][ny] == -2 || visit[nx][ny] == 1) continue;
            if (map[nx][ny] == value || map[nx][ny] == 0){
                visit[nx][ny] = 1;
                queue[e][0] = nx;
                queue[e][1] = ny;
                e++;
            }
            
        } 
    }



    info information;
    information.standx = -1;
    information.standy = -1;
    information.count = 0;
    information.rainbow = 0;

    if (option == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (visit[i][j] == 1){
                    map[i][j] = -2;
                }
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (visit[i][j] == 1){
                    information.count++;

                    if (map[i][j] == 0) information.rainbow++;

                    if (information.standx == -1 && information.standy == -1 && map[i][j] != 0){
                        information.standx = i;
                        information.standy = j;
                    }
                }
                    
                
            }
        }
    }


    return information;
}

void gravity(){
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if (map[j][i] == -2){
                for(int k=j-1; k>=0; k--){
                    if (map[k][i] == -2) continue;
                    if (map[k][i] == -1) break;
                    int temp = map[k][i];
                    map[k][i] = -2;
                    map[j][i] = temp;
                    break;
                }
            }
        }
    }
}

void rotate(){
    int map_2[20][20] = {0,};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map_2[i][j] = map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[n-1-j][i] = map_2[i][j];
        }
    }
}

void print_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int score = 0;
    int past_score = 1;
    // input
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    

    while(score != past_score){
        past_score = score;
        // cout << score << '\n';

        info ans;
        ans.count = 1;
        
        // find
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (map[i][j] != -1 && map[i][j] != -2 && map[i][j] != 0){
                    info temp = find(i,j,0);
                    if (ans.count < temp.count) ans = temp;
                    else if (ans.count == temp.count){
                        if (ans.rainbow < temp.rainbow) ans = temp;
                        else if (ans.rainbow == temp.rainbow){
                            if (ans.standx < temp.standx) ans = temp;
                            else if (ans.standx == temp.standx){
                                if (ans.standy < temp.standy) ans = temp;
                            }
                        }
                    }
                }
            }
        }

        if (ans.count > 1){
            // cout << ans.standx << ':' << ans.standy << ':' << map[ans.standx][ans.standy] << '\n';
            find(ans.standx,ans.standy,1);
            // print_map();
            score += ans.count * ans.count;
        }

        // gravity
        gravity();
        rotate();
        gravity();
  
    }
    cout << score;
}
