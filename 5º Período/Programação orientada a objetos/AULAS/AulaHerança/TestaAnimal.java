/**
 * 
 */

/**
 * @author hfebe
 *
 */
public class TestaAnimal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Animal a1 = new Animal("Animal X", 99); 
		Gato a2 = new Gato("Garfied", 21);  
		
		System.out.println(a1);
		System.out.println(a2);
		System.out.println(a2.seLamber());
	}

}  
