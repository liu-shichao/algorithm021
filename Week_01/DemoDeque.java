import java.util.Deque;
import java.util.LinkedList;

public class DemoDeque{

//    public static void main(String[] args) {
//        Deque<String> deque = new LinkedList<String>();

//        deque.addFirst("a");
//        deque.addFirst("b");
//        deque.addFirst("c");

//        System.out.println(deque);

//        String str = deque.getFirst();
//        System.out.println(str);
//        System.out.println(deque);

//        while(deque.size()>0){
//                System.out.println(deque.removeFirst());
//        }
//        System.out.println(deque);
//    }
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<String>();

        deque.addLast("a");
        deque.addLast("b");
        deque.addLast("c");

        System.out.println(deque);

        String str = deque.getLast();
        System.out.println(str);
        System.out.println(deque);

        while(deque.size()>0){
                System.out.println(deque.removeLast());
        }
        System.out.println(deque);
    }
}
