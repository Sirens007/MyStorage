import org.w3c.dom.ls.LSOutput;

import java.util.Scanner;

public class Main {
    //psvm
    public static void main(String[] args) {
        Week w1 = new Week();
        w1.judge();
    }
}

class Week{
    Scanner sc = new Scanner(System.in);
    int score;
    int today;
    public Week(){
        System.out.println("请输入成绩：");
        score = sc.nextInt();
        System.out.println("请输入日期：");
        today = sc.nextInt();
        sc.close();
    }

    public void judge(){
        if(score >= 90 && score <= 100){
            System.out.println("优秀");
        }
        else if(score >= 60 && score <= 89){
            System.out.println("及格");
        }
        else if(score >= 0 && score <= 59){
            System.out.println("不及格");
        }

        switch(today){
            case 1:
                System.out.println("今天星期一");
                break;
            case 2:
                System.out.println("今天星期二");
                break;
            case 3:
                System.out.println("今天星期三");
                break;
            case 4:
                System.out.println("今天星期四");
                break;
            case 5:
                System.out.println("今天星期五");
                break;
            case 6:
                System.out.println("今天星期六");
                break;
            case 7:
                System.out.println("今天星期日");
                break;
            default:
                System.out.println("输入错误！请输入 1~7");
        }
    }

}