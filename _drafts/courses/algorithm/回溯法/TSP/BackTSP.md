```
问题描述：
旅行商问题，需要走一圈再回来
```



```java
package Experiment2;

import java.util.Arrays;

public class Back_TSP {
    public static int[][] city_graph = {{0, 0, 0, 0, 0},
                                        {0,-1, 30, 6, 4},
                                        {0,30, -1, 5, 10},
                                        {0,6, 5, -1, 20},
                                        {0,4, 10, 20, -1}};
    public static int path_num = city_graph.length;
    public static int[] is_in = new int[path_num]; //用来检测该节点是否已经添加到路径中
    public static int[] path = new int[path_num];//用于储存路径
    public static int[] best_path = new int[path_num];//用于储存最优路径
    public static int best_length = Integer.MAX_VALUE;//初始化最优路径的路程总和
    public static int now_length = 0;

    /**
     * 注意递归返回时，全局变量并不会返回，而是保留深层递归的值，需要你手动取消
     * 递归返回跟随返回的值只有i,j,k这种局部变量,递归一次相当于重新创建了一个局部变量
     *
     * @param t 代表递归深度，递归到城市数目加一的时候结束
     */
    private static void TSP(int t) {
        if (t > path_num - 1) {  // 搜索至叶子节点
            StringBuilder ThePath = new StringBuilder();

            for (int i = 1; i < path_num; ++i) {  // 输出当前路径
                ThePath.append(path[i]).append("->");
            }
            //temp是最后一个城市
            int temp = path[path_num-1];

            if (city_graph[temp][1] > 0) { // 判断是否存在回路
                ThePath.append('1');  // 路径加上回路回到城市1
                System.out.println("当前路径:" + ThePath);

                int back_length = now_length + city_graph[temp][1]; // 回路路程也需要相加
                //System.out.println("当前路径总和:" + back_length);

                if (back_length < best_length) { // 更新最优解
                    System.arraycopy(path, 1, best_path, 1, path_num - 1);

                    best_length = back_length;
                    // 更新最优路径
                    //System.out.println("更新最优路径");
                }
                return;  // 返回
            }
        } else {
            for (int j = 1; j < path_num; ++j) {
                //图大1,可以不用对初始条件做分类讨论
                if (city_graph[path[t - 1]][j] != -1 && (is_in[j] == 0)) { // 两城市间存在路径并且还未走过
                    is_in[j] = 1; // 表示该城市已经来过
                    path[t] = j; // 将该城市存至path中
                    now_length = now_length + city_graph[path[t - 1]][j]; // 加路径对应路程和

                    //剪支
                    if(now_length>best_length) {
                        //此时不需要再向下搜索,不需要迭代了
                        //System.out.println(Arrays.toString(path));
                    }
                    else {
                        TSP(t + 1);
                    }
                    is_in[j] = 0;//递归结束,开始回退,先把城市去掉
                    path[t] = 0;//把路径中的去掉
                    now_length = now_length - city_graph[path[t - 1]][j];//把路程减回去
                }
            }
        }
    }

    /**
     *
     * @param city_graph 这个图必须和test测试用例一样,第一行第一列均为零,即下表为0为无效点
     */
    public static void Back_TSP(int[][] city_graph) {
        Back_TSP.city_graph = city_graph;
        path_num = city_graph.length;
        path = new int[path_num];
        best_path = new int[path_num];
        is_in = new int[path_num];
        TSP(1);

        System.out.println(Arrays.toString(best_path));
        System.out.println(best_length);
    }

    public static void main(String[] args) {
        int[][] city_graph = {{0, 0, 0, 0, 0},
                {0,-1, 30, 6, 4},
                {0,30, -1, 5, 10},
                {0,6, 5, -1, 20},
                {0,4, 10, 20, -1}};

        int[][] b = { { 0, 0, 0, 0, 0 }, { 0, -1, 9, 19, 13 }, { 0, 21, -1, -1, 14 }, { 0, 1, 40, -1, 17 },
                { 0, 41, 80, 10, -1 } };
        Back_TSP(city_graph);
    }


}

```

