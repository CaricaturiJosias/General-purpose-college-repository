
public class ExemploFor {
	public static void main(String[] args) {
		//loop de 2 em 2, come�ando em 1, at� passar de 100
		//mostre a soma no final
		int i;
		for(i=1 ; i<100;i+=2 ){
			System.out.print(i +" ");
			if (i % 15 == 0) 
				System.out.println();			
		}
	}
}
