import java.util.Scanner;

//今天作业是164.42 单独取出数字
public class Main {
    public static void main(String[] args) {
//        Test2 t1 = new Test2();
//        t1.test2();
        Homework h1 = new Homework();
        h1.task();
    }
}

class Homework{
    void task(){
        double num = 164.42;
        String str = String.valueOf(num);
        char ch = 0;
        int digit = 0;
        for(int i = 0;i < str.length();i++){
            ch = str.charAt(i);
            if(ch != '.'){
                digit = ch - '0';
                System.out.println(digit);
            }
        }
    }
}

class Test2{
    void test2(){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
        int sum = 0;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
        }
        int avg = sum/arr.length;
        System.out.println(avg);
    }
}

class Test{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int sum = 0;
    int i = 1;
    void test(){
        do{
            sum += i;
            i++;
        }while(i <= n);
        System.out.println(sum);
    }
}

class MaxNumber{
    Scanner sc = new Scanner(System.in);
    void findMax(){
        System.out.println("请输入三个数字：");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int max = a;
        if(b > max){
            max = b;
        }
        if(c > max){
            max = c;
        }
        System.out.println("最大数为："+max);
        sc.close();
    }
}