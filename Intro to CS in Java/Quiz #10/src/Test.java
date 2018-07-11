import java.util.ArrayList;
// 



public class Test {

		public static void main(String[] args) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(1); list.add(-4); list.add(2); list.add(3);
				//System.out.println(list);
				ArrayList<Integer> list2 = Utility.runningTotal(list);
				//System.out.println(list2);
		}
}
