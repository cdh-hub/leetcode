import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=1632 lang=java
 *
 * [1632] 矩阵转换后的秩
 */

// @lc code=start
class Solution {
    private int[] same;
    private int find(int a) {
        if (a == same[a]) return a;
        return a = find(same[a]);
    }
    private void un(int a, int b) {
        same[find(a)] = find(b);
    }
    public int[][] matrixRankTransform(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        HashSet<Integer>[] g = new HashSet[m*n];
        int[] degree = new int[m*n];
        same = new int[m*n];
        for (int i = 0; i < m*n; i++) {
            same[i] = i;
            g[i] = new HashSet<>();
            degree[i] = 0;
        }
        // for (int i = 0; i < m*n; i++) {
        //     g[i] = new HashSet<>();
        //     degree[i] = 0;
        //     int x = i / n, y = i % n;
        //     for (int j = x + 1; j < m; j++) {
        //         if (matrix[j][y] == matrix[x][y]) {
        //             un(i, j*n+y);
        //         }
        //     }
        //     for (int j = y + 1; j < n; j++) {
        //         if (matrix[x][j] == matrix[x][y]) {
        //             un(i, x*n+j);
        //         }
        //     }
        // }

        for (int i = 0; i < m; i++) {
            HashMap<Integer, List<Integer>> map = new HashMap<>();
            int[] row = new int[n];
            for (int j = 0; j < n; j++) {
                row[j] = matrix[i][j];
                if (map.containsKey(matrix[i][j])) {
                    map.get(matrix[i][j]).add(i*n+j);
                }
                else {
                    List<Integer> l = new ArrayList<>();
                    l.add(i*n+j);
                    map.put(matrix[i][j], l);
                }
            }
            Arrays.sort(row);
            for (int j = 1; j < n; j++) {
                if (row[j] == row[j-1]) {
                    for (Integer l: map.get(row[j])) {
                        un(l, map.get(row[j]).get(0));
                    }
                    j += map.get(row[j]).size() - 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            HashMap<Integer, List<Integer>> map = new HashMap<>();
            int[] column = new int[m];
            for (int j = 0; j < m; j++) {
                column[j] = matrix[j][i];
                if (map.containsKey(matrix[j][i])) {
                    map.get(matrix[j][i]).add(j*n+i);
                }
                else {
                    List<Integer> l = new ArrayList<>();
                    l.add(j*n+i);
                    map.put(matrix[j][i], l);
                }
            }
            Arrays.sort(column);
            for (int j = 1; j < m; j++) {
                if (column[j] == column[j-1]) {
                    for (Integer l: map.get(column[j])) {
                        un(l, map.get(column[j]).get(0));
                    }
                    j += map.get(column[j]).size() - 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            HashMap<Integer, Integer> map = new HashMap<>();
            int[] row = new int[n];
            for (int j = 0; j < n; j++) {
                row[j] = matrix[i][j];
                map.put(matrix[i][j], i*n+j);
            }
            Arrays.sort(row);
            for (int j = 1; j < n; j++) {
                if (row[j] > row[j-1] && !g[find(map.get(row[j-1]))].contains(find(map.get(row[j])))) {
                    g[find(map.get(row[j-1]))].add(find(map.get(row[j])));
                    degree[find(map.get(row[j]))]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            HashMap<Integer, Integer> map = new HashMap<>();
            int[] column = new int[m];
            for (int j = 0; j < m; j++) {
                column[j] = matrix[j][i];
                map.put(matrix[j][i], j*n+i);
            }
            Arrays.sort(column);
            for (int j = 1; j < m; j++) {
                if (column[j] > column[j-1] && !g[find(map.get(column[j-1]))].contains(find(map.get(column[j])))) {
                    g[find(map.get(column[j-1]))].add(find(map.get(column[j])));
                    degree[find(map.get(column[j]))]++;
                }
            }
        }
        // for (int i = 0; i < m*n; i++) {
        //     int x = i / n, y = i % n;
        //     for (int j = x + 1; j < m; j++) {
        //         if (matrix[j][y] > matrix[x][y]) {
        //             if (!g[find(i)].contains(find(j*n+y))) {
        //                 g[find(i)].add(find(j*n+y));
        //                 degree[find(j*n+y)]++;
        //             }
        //         }
        //         else if (matrix[j][y] < matrix[x][y]) {
        //             if (!g[find(j*n+y)].contains(find(i))) {
        //                 g[find(j*n+y)].add(find(i));
        //                 degree[find(i)]++;
        //             }
        //         }
        //     }
        //     for (int j = y + 1; j < n; j++) {
        //         if (matrix[x][j] > matrix[x][y]) {
        //             if (!g[find(i)].contains(find(x*n+j))) {
        //                 g[find(i)].add(find(x*n+j));
        //                 degree[find(x*n+j)]++;
        //             }
        //         }
        //         else if (matrix[x][j] < matrix[x][y]) {
        //             if (!g[find(x*n+j)].contains(find(i))) {
        //                 g[find(x*n+j)].add(find(i));
        //                 degree[find(i)]++;
        //             }
        //         }
        //     }
        // }
        int[][] ans = new int[m][n];
        Queue<Integer> q = new LinkedList<>();
        int cnt1 = 0, cnt2;
        for (int i = 0; i < m*n; i++) {
            if (i == find(i) && degree[i] == 0) {
                q.offer(i);
                cnt1++;
            }
        }
        int num = 1;
        while (!q.isEmpty()) {
            cnt2 = cnt1;
            cnt1 = 0;
            for (int i = 0; i < cnt2; i++) {
                int u = q.poll();
                for (int v: g[u]) {
                    degree[v]--;
                    if (degree[v] == 0) {
                        q.offer(v);
                        cnt1++;
                    }
                }
                int x = u / n, y = u % n;
                ans[x][y] = num;
            }
            num++;
        }
        for (int i = 0; i < m*n; i++) {
            int root = find(i);
            ans[i/n][i%n] = ans[root/n][root%n];
        }
        return ans;
    }
}
// @lc code=end

