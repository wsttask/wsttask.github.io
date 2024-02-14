```java
import java.util.*;

public class Main {

    private int no_edge = -1;//什么情况是没有边的情况
    private int minCost = Integer.MAX_VALUE;
    private Vector<Integer> bestH = new Vector<Integer>();

    Comparator<HeapNode> cmp = (e1, e2) -> e2.l_cost - e1.l_cost;
    private PriorityQueue<HeapNode> priorHeap = new PriorityQueue<HeapNode>(cmp);


    public static class HeapNode implements Comparable{
        Vector<Integer> cityArrange = new Vector<Integer>();//在这个节点经过的路径
        int cost;
        int l_cost;
        int level;
        //创建一个空节点
        public HeapNode(){

        }
        public HeapNode(Vector<Integer> cities,int lb, int lev){
            cityArrange.addAll(0, cities);//为什么不直接指向，而是重新创建一个？
            l_cost = lb;
            level = lev;
        }

        @Override
        public int compareTo(Object x) {//比较lcost的大小，也就是int的大小
            int xu=((HeapNode)x).l_cost;
            if(l_cost <xu) return -1;
            if(l_cost ==xu) return 0;
            return 1;
        }
        @Override
        public boolean equals(Object x){
            return l_cost ==((HeapNode)x).l_cost;
        }
    }
    //没有必要，太罗嗦了，节点中就包含这些信息
    public int computeLB(HeapNode node, int[][] cMatrix)
    {
        int n = cMatrix.length - 1;
        int lb = node.cost;

        // 遍历未访问的城市到最近访问的城市的最小代价,下界其实找的不太好，不准确，找第二小的
        for (int i = 1; i <= n; i++) {
            if (!node.cityArrange.contains(i)) {
                int minCost = Integer.MAX_VALUE;
                for (int j = 1; j <= n; j++) {
                    if(cMatrix[j][i] != no_edge) {
                        minCost = Math.min(minCost, cMatrix[j][i]);
                    }
                }
                lb += minCost;
            }
        }
        return lb;
    }


    public int bbTSP(int[][] cMatrix, int n)//n是指城市数目
    {
        //构造初始节点
        HeapNode root = new HeapNode();
        root.cityArrange = new Vector<>();//建立了一个int的动态数组，城市排列
        root.cityArrange.add(0);//空出一个城市，与cMatrix一致
        root.cityArrange.add(1);
        root.level = 1;//0-level的城市是已经排好的
        root.l_cost = computeLB(root,cMatrix) ; //代价的下界

        priorHeap.offer(root);//添加节点

        while (!priorHeap.isEmpty()) {
            HeapNode node = priorHeap.poll();//优先队列，根据lcost排列，为什么要用优先队列，普通也可以把？
            if (node.l_cost >= minCost) continue; // 如果当前节点的下界大于等于已知的最小代价，剪枝

            //产生子节点
            for (int i = 1; i <= n; i++) {
                if(!node.cityArrange.contains(i)) {
                    HeapNode child = new HeapNode();
                    child.cityArrange = new Vector<>(node.cityArrange);
                    child.cityArrange.add(i);//添加子节点的路径
                    child.level = node.level + 1;
                    child.l_cost = computeLB(child, cMatrix);
                    child.cost = node.cost + cMatrix[node.cityArrange.get(node.level)][i];


                    if (child.level == n) { // 到达叶子节点
                        int tep = cMatrix[child.cityArrange.get(child.level)][1];
                        int temp = child.cost + tep;
                        if (temp < minCost && tep != no_edge) {
                            minCost = temp;
                            bestH = child.cityArrange;
                        }
                    } else {
                        if (child.l_cost < minCost) {
                            priorHeap.offer(child);
                        }
                    }
                }
            }
        }
        return minCost;
    }

    public int getMinCost() {
        return this.minCost;
    }

    public static void main(String[] args) {
        Main bb4TSP = new Main();
        int[][] b = { { -1, -1, -1, -1, -1 }, { -1, -1, 9, 19, 13 }, { -1, 21, -1, -1, 14 }, { -1, 1, 40, -1, 17 },
                { -1, 41, 80, 10, -1 } };
        int n = 4;
        bb4TSP.bbTSP(b, n);
        System.out.println(bb4TSP.getMinCost());
    }


}

```

