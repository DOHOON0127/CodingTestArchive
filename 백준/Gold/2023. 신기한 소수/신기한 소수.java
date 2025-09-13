// N자리의 숫자 중에서 신기한 소수를 찾는 문제
// 신기한 소수란 7311 처럼 7,73,733,7311이 모두 소수인 수를 뜻함
// 시간제한 2초, 2억번 안에 해야함
// 어케풀까?
// 재귀 함수를 이용한 DFS
// 소수 판별 방법 : "에라토스테네스의 채"
// 슈도코드
//N(자리수)
//
//DFS(2,1);
//DFS(3,1);
//DFS(5,1);
//DFS(7,1);
//
//DFS(숫자, 자리수){
//    if(자리수 == N) {
//        if(소수) 수 출력하기
//        탐색 종료
//    }
//
//    for(1~9 반복하기){
//        if(뒤에 붙는 수가 홀수이면서 소수일 때)
//        DFS(현재수*10 + i, 자리수+1)
//    }
//}
//
//소수구하기 함수 만들기

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        DFS(2,1);
        DFS(3,1);
        DFS(5,1);
        DFS(7,1);
    }
    static void DFS(int number, int jarisu){
        if(jarisu == N){
            if(isPrime(number)){
                System.out.println(number);
            }
            return;
        }

        for(int i = 1; i < 10; i++){
            if(i % 2 == 0){
                continue;
            }
            if(isPrime(number * 10 + i)){
                DFS(number * 10 + i, jarisu + 1); // 자릿수를 1씩 늘리면서 DFS 실행
            }
        }
    }

    static boolean isPrime(int n){
        for(int i = 2; i <= n/2; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}