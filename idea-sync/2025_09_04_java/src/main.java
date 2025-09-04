import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
//        //        StringTools.reverse();  //静态方法直接调用函数名
//        System.out.println("请输入字符：");
//        Scanner sc = new Scanner(System.in);
//        String word = sc.nextLine();
//        String result = StringTools.reverse(word);
//        System.out.println(result);

    }
}

class Counter{
    static int count = 0;
    public Counter(){
        count++;
    }
}

class StringTools{
//    static void reverse(){
//        Scanner sc = new Scanner(System.in);
//        System.out.println("请输入字符串：");
//        String word = sc.nextLine();
//        String reversed = "";
//        for(int i = word.length()-1;i >= 0;i--){
//            reversed += word.charAt(i);
//        }
//        System.out.println(reversed);
//    }

    static String reverse(String word){
        String reversed = "";
        for(int i = word.length()-1;i >= 0;i--){
            reversed += word.charAt(i);
        }
        return reversed;
    }

}