/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 29216
 * Date: 2025-09-03
 * Time: 17:08
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Task t1 = new Task();
        t1.test();
    }
}

class Task{
    void test(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入学生个数：");
        int stdNum = sc.nextInt();
        double[][] stdScores = new double[stdNum][2];
        //输入成绩
        for(int i = 0; i < stdNum; i++){
            System.out.println("请输入第"+(i+1)+"位同学的两科成绩：");
            for(int j = 0;j < 2;j++){
                stdScores[i][j] = sc.nextDouble();
            }
        }

        //输出成绩
        for(int i = 0; i < stdNum; i++) {
            double sum = 0;
            for (int j = 0; j < 2; j++) {
                sum += stdScores[i][j];
            }
            double avg = sum / 2;
            System.out.println("第" + (i + 1) + "位同学的平均成绩为：" + avg);
        }
        sc.close();
    }
}