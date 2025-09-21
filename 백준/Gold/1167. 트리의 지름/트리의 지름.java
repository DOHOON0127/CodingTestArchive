// 트리에서 임의의 두 점 사이에서 거리 중 가장 긴 것
// 트리의 지름 구하기

//        5
//        1 3 2 -1
//        2 4 4 -1
//        3 1 2 4 3 -1
//        4 2 4 3 3 5 6 -1
//        5 4 6 -1

//        답 : 11

// 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)
// 둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.
// 먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데,
// 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다.
// 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고,
// 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다.
// 주어지는 거리는 모두 10,000 이하의 자연수이다.

//첫째 줄에 트리의 지름을 출력한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean visited[];
    static int[] distance;
    static ArrayList<Edge>[] A;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken()); // 정점 개수

        A = new ArrayList[V+1];

        for(int i = 0; i <= V; i++){
            A[i] = new ArrayList<Edge>();
        }

        for(int i = 1; i <= V; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            while(true){
                int e = Integer.parseInt(st.nextToken());
                if(e == -1) {
                    break;
                }
                int v = Integer.parseInt(st.nextToken());

                A[n].add(new Edge(e,v));
            }
        }

        distance = new int[V+1];
        visited = new boolean[V+1];
        BFS(1);
        int Max = 1;
        for(int i = 1; i <= V; i++){
            if(distance[Max] < distance[i]){
                Max = i;
            }
        }
        distance = new int[V+1];
        visited = new boolean[V+1];
        BFS(Max);
        Arrays.sort(distance);
        System.out.println(distance[V]);
    }

    public static void BFS(int index){
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(index);
        visited[index] = true;
        while(!q.isEmpty()){
            int new_node = q.poll();
            for(Edge i : A[new_node]){
                int e = i.e;
                int v = i.value;
                if(!visited[e]){
                    visited[e] = true;
                    q.add(e);
                    distance[e] = distance[new_node] + v;
                }
            }
        }
    }

    static class Edge {
        int e;
        int value;

        public Edge(int e, int value) {
            this.e = e;
            this.value = value;
        }
    }
}