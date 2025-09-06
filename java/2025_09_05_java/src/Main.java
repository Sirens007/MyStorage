/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Sirens007_host
 * Date: 2025-09-05
 * Time: 18:44
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.setName("Sirens");
        s1.setScore(99);
        System.out.println("姓名："+s1.getName());
        System.out.println("成绩："+s1.getScore());

    }
}

class BankAccount{
    private double balance;
    public double deposit(double money){
        if(money > 0){
            balance += money;
            System.out.println("成功存入"+money+"元");
        }
        else{
            System.out.println("存款金额必须大于0！");
        }
        return balance;
    }

    public double withdraw(double money){
        if(balance >= money){
            balance -= money;
            System.out.println("成功取出"+money+"元");
        }
        else{
            System.out.println("余额不足取款金额！");
        }
        return balance;
    }
}

class Student{
    private String name;
    private int score;

    public String getName(){
        return name;
    }
    public int getScore(){
        return score;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setScore(int score){
        if(score >= 0 && score <= 100){
            this.score = score;
        }
    }
}

class Test{
    void test(){
        Scanner sc = new Scanner(System.in);

        System.out.println("以下将会显示创建Counter类的对象的次数：");
        System.out.println(Counter.counter);

        System.out.println("请输入两个数字进行add运算（直接显示结果）：");
        MathTools.add(sc.nextInt(),sc.nextInt());
        System.out.println("请输入两个数字进行max比较（会显示较大的数）：");
        MathTools.max(sc.nextInt(),sc.nextInt());

        // 多次获取实例并比较引用是否相等
        Config c1 = Config.getInstance();
        Config c2 = Config.getInstance();
        Config c3 = Config.getInstance();
        System.out.println(c1 == c2);
        System.out.println(c2 == c3);
    }
}

class Counter{
    static int counter = 0;
    public Counter(){
        counter++;
    }
}

class MathTools{
    static int add(int a, int b){
        System.out.println(a + b);
        return a + b;
    }

    static int max(int a,int b){
        System.out.println(a > b ? a : b);
        return a > b ? a : b;
    }
}

class Config{
    // 1） 保存唯一实例的地方 （还未创建时为 null）
    private static Config instance;

    // 2) 私有构造函数，禁止外部用 new 创建
    private Config(){
        System.out.println("配置对象被创建！");
    }
    // 3） 提供静态方法获取唯一实例（懒汉式：第一次调用时创建）
    public static Config getInstance(){
        if(instance == null){           //第一次调用时instance 为 null
            instance = new Config();    //创建唯一的 Config 对象，并赋给静态变量
        }
        return instance;                //返回同一份引用
    }
}

