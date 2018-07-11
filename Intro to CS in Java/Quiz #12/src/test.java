
public class test {
	public static void main(String[] args){
		LinkedIntList list = new LinkedIntList();
		list.add(8); list.add(13); list.add(17); list.add(4); list.add(9); list.add(12); list.add(98); list.add(41);
		System.out.println(list);
		System.out.println(list.removeEvens(list));
		System.out.println(list.removeEvens(list));
		System.out.println(list.removeEvens(list));
		System.out.println(list.removeEvens(list));	//down to one node
		
		LinkedIntList list2 = new LinkedIntList();		//empty
		System.out.println(list2);
		System.out.println(list2.removeEvens(list2));


	}

}
