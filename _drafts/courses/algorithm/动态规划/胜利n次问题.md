小明想要在王者荣耀游戏里晋升一个段位，假设他一共需打了*n*场比赛，且必须成功赢得至少70%的场次才能成功晋升。假设每场比赛小明获胜的概率分别为*p*1，*p*2，…，*p**n*，请帮他算出成功晋级段位的概率是多少？



输入：

​	参数1：整数num（0 £ num £ 1000），表示比赛的场数。

​	参数2：整数数组*p*[num] = {*p*1，*p*2，…，*p**n**um*}，其中$p_i$表示小明有${p_i}$%的概率赢得第*i*场比赛。



输出：

成功晋级段位的概率，保留小数点后5位，最后结果四舍五入。



```java
package Experiment1;

public class GamePassProbability {

    public double calculatePassProbability_noDp(int[] p, int num)
    {
        int winNum =(int) Math.ceil(num * 0.7);
        double probability_sum = 0;


        double[] p_new = new double[p.length];
        for (int i = 0; i < p.length; i++) {
            p_new[i] = (p[i] * 1.0) / 100;
        }


        for (int i = 0; i < (int)Math.pow(2,num); i++) {
            int sum = 0;
            int binaryNumber = i;
            // 循环遍历二进制数的每一位
            while (binaryNumber > 0) {
                // 使用位运算获取最后一位，并将其加到总和中
                sum += binaryNumber & 1;
                // 右移二进制数，相当于去掉最后一位
                binaryNumber >>= 1;
            }
            if(sum >= winNum) {
                double probability = 1;
                binaryNumber = i;
                int n = 0;
                while (n < num) {
                    // 使用位运算获取最后一位，1代表赢，0代表输
                    if( (binaryNumber & 1) == 1 ) {
                        probability *= p_new[n];
                    }
                    else {
                        probability *= 1-p_new[n];
                    }
                    // 右移二进制数，相当于去掉最后一位
                    binaryNumber >>= 1;
                    //n代表第几场比赛
                    n++;
                }
                probability_sum += probability;
            }
        }
        String formattedNumber = String.format("%.5f", probability_sum);
        probability_sum = Double.valueOf(formattedNumber);
        return probability_sum;
    }

    public  double calculatePassProbability(int[] p, int num) {
        // dp数组，dp[i][j]表示前i场比赛中获胜j场的概率
        double[][] dp = new double[num + 1][num + 1];
        dp[0][0] = 1.0;

        // 动态规划递推
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j <= i; j++) {
                // 前i场胜利j次 = 前i-1场胜利j-1 + 前i-1场胜利j
                dp[i][j] = (j > 0 ? dp[i - 1][j - 1] * (p[i - 1]/100.0) : 0) + dp[i - 1][j] * (1 - (p[i - 1]/100.0));
            }
        }

        // 统计成功晋级的概率
        double successProbability = 0.0;
        for (int j = (int) Math.ceil(0.7 * num); j <= num; j++) {
            successProbability += dp[num][j];
        }

        return successProbability;
    }
}

package test;

import org.junit.Assert;
import org.junit.Test;

import Experiment1.GamePassProbability;


public class GamePassProbabilityTest {

    @Test
    public void testCalculateProbability(){
        GamePassProbability gamePassProbability = new GamePassProbability();
        int[] p1 = {50, 50, 50, 50};
        int[] p2 = {80, 80, 90, 90, 99};
        int[] p3 = {};
        double result1 = gamePassProbability.calculatePassProbability(p1, 4);
        double result2 = gamePassProbability.calculatePassProbability(p2, 5);
        double result3 = gamePassProbability.calculatePassProbability(p3, 0);
        System.out.println(result1);
        System.out.println(result2);
        System.out.println(result3);
        double epsilon = 1e-5; // 设定一个小的范围
        Assert.assertTrue(Math.abs(result1 - 0.31250)<epsilon);
        Assert.assertTrue(Math.abs(result2 - 0.88906)<epsilon);
        Assert.assertTrue(Math.abs(result3 - 1)<epsilon);
    }

}


```

