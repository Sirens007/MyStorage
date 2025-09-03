import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Homework h1 = new Homework();
        h1.task();
    }
}

class Homework{
    void task(){
        Scanner scanner = new Scanner(System.in);
        double num = scanner.nextDouble();
        String str = Double.toString(num);

        //统计数字个数
        int count = 0;
        for(int i = 0;i < str.length();i++){
            if(str.charAt(i) != '.'){
                count++;
            }
        }

        int length = 0;                         //用来判断是否需要空格
        for(int i = 0;i < str.length();i++){
            char ch = str.charAt(i);            //用ch存储每一次读到的字符
            if(ch != '.'){
                length++;
                int digit = ch - '0';
                if(length == count){
                    System.out.print(digit);
                }
                else{
                    System.out.print(digit+" ");
                }
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