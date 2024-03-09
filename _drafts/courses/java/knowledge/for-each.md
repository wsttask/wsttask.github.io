@语句结构：
    for ( 变量类型  变量名 : 数组名 ) {   
        需要执行的循环语句;
    }

simple：
```java
import java.util.Scanner;

public class Main {

public static void main(String[] args) {

    int [] data = {56, 75, 68, 45, 24, 245, 2, 5, 22, 27, 5};
    int x = 0;
    Scanner in = new Scanner ( System.in );
    x = in.nextInt();

    boolean found = false;
    for ( int k : data ) {
        if ( k==x ) {
            found = true;
            break;
    	}
    }

    if ( found )	System.out.println("找到了");
    else 	System.out.println("没找到");

    in.close();
	

}
```