
import java.io.*;
import java.util.*;

public class Main {

    static int checkArr[];
    static int myArr[];
    static int checkSecret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken()); // 문자열 길이
        int P = Integer.parseInt(st.nextToken()); // 부분 문자열 길이

        int Result = 0;
        char A[] = new char[S];
        checkArr = new int[4];
        myArr = new int[4];
        checkSecret = 0;

        A = br.readLine().toCharArray();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            checkArr[i] = Integer.parseInt(st.nextToken()); // {A, C, G, T}
            if (checkArr[i] == 0) checkSecret++;
        }

        // 초기 윈도우
        for (int i = 0; i < P; i++) Add(A[i]);
        if (checkSecret == 4) Result++;

        // 슬라이딩
        for (int i = P; i < S; i++) {
            int j = i - P;
            Add(A[i]);
            Remove(A[j]);
            if (checkSecret == 4) Result++;
        }

        System.out.println(Result);
        br.close();
    }

    private static void Add(char c) {
        int idx = map(c);
        myArr[idx]++;
        if (myArr[idx] == checkArr[idx]) {
            checkSecret++;
        }
    }

    private static void Remove(char c) {
        int idx = map(c);
        if (myArr[idx] == checkArr[idx]) {
            checkSecret--;
        }
        myArr[idx]--;
    }

    private static int map(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default:  return -1; // 입력이 DNA가 아니면 여기로 (문제 조건상 안 옴)
        }
    }
}