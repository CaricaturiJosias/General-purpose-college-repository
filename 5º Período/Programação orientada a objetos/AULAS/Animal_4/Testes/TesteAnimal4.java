package Testes;
import java.util.ArrayList;

import Animal.*; // todas as classes do package Animal

public class TesteAnimal4 {

	public static void main(String[] args) {
		ArrayList<Animal> zoo = new ArrayList<Animal>(); 
		// armazenar qquer objeto Animal, ou sejam, qquer objeto que seja filho (sub classe) de Animal
		Gato g1 = new Gato("Garfied", 21);  
		Gato g2 = new Gato("Manda-Chuva", 5);
		Gato g3 = new Gato("Batatinha", 6);
		Cao c1 = new Cao("Scooby-Doo", 25);
		zoo.add(g1);
		zoo.add(c1);
		zoo.add(g2);
		zoo.add(g3);
		zoo.add(new Cao("Rin tin tin", 29));
		zoo.add(new Lobo("Lobo Mau", 35));
		zoo.add(new Cao("Lassie", 29));
		zoo.add(new Lobo("Lobopy Le Beau", 22));
		System.out.println("Animais no Zoo: " + zoo.size());

		for (Animal animal : zoo) {
			System.out.println ("\n"+animal.fazerBarulho());
			// instanceof verifica se o objeto em quest�o (da classe Animal) � tamb�m inst�ncia de (Gato)
			if (animal instanceof Gato) {
				// usando direto apenas sem coer��o
				System.out.println(((Gato)animal).seLamber());
			}
			if (animal instanceof Canideo) {
				Canideo can = (Canideo)animal; // usando vari�vel local para coer��o
				// n�o podemos instanciar Canideo, pois � classe abstrata
				// mas podemos referencia um objeto como sendo desta classe
				
				System.out.println(can.esconderOsso());
				System.out.println(can.farejar());
				// esconderOsso e farejar s�o comportamentos comuns a Cao e Lobo, 
				// est�o implementados em Canideo (processo de generaliza��o)
			}
		}		  
	}

}
