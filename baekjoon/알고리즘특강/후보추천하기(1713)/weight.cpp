#include<cstdio>
#include<algorithm>

int data[20], n, m, t, score, i, position, case_num, size;https://github.com/JunChangM/ProblemSolving/tree/main/baekjoon/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%ED%8A%B9%EA%B0%95/%ED%9B%84%EB%B3%B4%EC%B6%94%EC%B2%9C%ED%95%98%EA%B8%B0(1713)

int main() {
    scanf("%d%d", &n, &m);
    for (case_num = 0; case_num < m; case_num++) {
        scanf("%d", &t);
        score = 101101001; // MAX
        for (i = 0; i < n; i++) {
          // data가 비어있는 경우 새롭게 넣기
            if (!data[i]) { 
                size++; 
                data[i] = 101 * 1001 + i * 101 + t; // ( 추천수 {101 * 1001 } ) + ( 게시 시점 { 최대 1000 } ) + (학생 번호 { 최대 100 } )
                position = -1;
                break;
            }
          // 학생 번호가 이미 존재하는 경우 
            if (t == data[i] % 101) { 
                data[i] += 101 * 1001; // 추천수 증가
                position = -1; 
                break; 
            }
          // 가장 작은 data[i] 값 찾아서 position check 하기, 이 값이 바뀌는 값이 됨.
            if (score > data[i]) {
                score = data[i];
                position = i;
            }
        }
      // 위의 position -1에 걸리지 않는다면, 그 위치(사진틀)에 새로운 후보자 등록
        if (position > -1) {
            data[position] = 101 * 1001 + case_num * 101 + t;
        }
    }
  // 101로 나누어 후보자 학생의 번호 확인
    for (i = 0; i < size; i++) {
        data[i] %= 101;
    }
  // 오름차순 정렬
    std::sort(data, data + size);
  // size만큼(사진틀에 등록된 후보자 수) 출력
    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
}
