
import java.io.*;
import java.util.*;

public class Main {
    // 각 문자의 인덱스를 쉽게 찾기 위한 변수 (A:0, C:1, G:2, T:3)
    // static 변수로 선언하여 함수 등에서 공용으로 사용
    static int[] myArr = new int[4];
    static int[] checkArr = new int[4];
    static int checkCount = 0; // 조건을 만족하는 문자의 개수 (4가 되면 비밀번호 사용 가능)

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        char[] A = br.readLine().toCharArray(); 

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 4; i++) {
            checkArr[i] = Integer.parseInt(st.nextToken());
            // 만약 해당 문자의 요구 개수가 0이라면, 이미 조건을 만족한 것으로 침
            if(checkArr[i] == 0) checkCount++;
        }

        int count = 0; // 정답 개수

        // 1. 초기 P개 부분 문자열 처리 (첫 윈도우 만들기)
        for(int i = 0; i < P; i++) {
            add(A[i]);
        }

        // 첫 윈도우가 조건 만족하는지 확인
        if(checkCount == 4) count++;

        // 2. 슬라이딩 윈도우 (한 칸씩 이동)
        // i는 끝나는 지점(end), j는 시작 지점(start)
        for(int i = P; i < S; i++) {
            int j = i - P;

            add(A[i]);   // 새로 들어오는 문자 추가 (오른쪽 끝)
            remove(A[j]); // 빠지는 문자 제거 (왼쪽 끝)

            if(checkCount == 4) count++; // 조건 만족 확인
        }

        System.out.println(count);
    }

    private static void add(char c) {
        int idx = getIndex(c);
        myArr[idx]++;
        // 내 개수가 목표 개수와 '정확히 같아지는 순간'에만 checkCount 증가
        if(myArr[idx] == checkArr[idx]) {
            checkCount++;
        }
    }

    private static void remove(char c) {
        int idx = getIndex(c);
        // 내 개수가 목표 개수와 같았다가 줄어들면 조건 불만족이므로 checkCount 감소
        if(myArr[idx] == checkArr[idx]) {
            checkCount--;
        }
        myArr[idx]--;
    }

    private static int getIndex(char c) {
        switch(c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
}