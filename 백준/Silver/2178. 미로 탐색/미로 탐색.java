// 1초, 1억번 안에
// n*m 크기의 미로가 주어질 때,(N: 세로, M: 가로)
// (1,1)에서 (N,M)으로 이동하기 위해 필요한 칸 수의 최솟값을 구하는 문제

// 101111
// 101010
// 101011
// 111011

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    // 상하좌우를 탐색하기 위한 배열 선언하기
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static boolean[][] visited;
    static int[][] A;
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 세로 4
        M = Integer.parseInt(st.nextToken()); // 가로 6

        A = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken(); // 101111 같은게 line으로 들어옴
            for(int j = 0; j < M; j++) {
                A[i][j] = Integer.parseInt(line.substring(j, j+1));
            }
        }

        BFS(0,0);
        System.out.println(A[N-1][M-1]);
    }

    public static void BFS(int i, int j) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {i, j});
        visited[i][j] = true;
        while(!q.isEmpty()) {
            int now[] = q.poll();
            for(int k = 0; k < 4; k++) {
                int x = now[0] + dx[k];
                int y = now[1] + dy[k];

                if(x >= 0 && y >= 0 && x < N && y < M) { // 좌표 유효성 검사하기!
                    if(A[x][y] != 0 && !visited[x][y]) {
                        visited[x][y] = true;
                        A[x][y] = A[now[0]][now[1]] + 1; // 깊이 업데이트 하기
                        q.add(new int[]{x, y});
                    }

                }

            }
        }
    }
}