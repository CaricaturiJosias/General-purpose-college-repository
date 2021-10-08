
public class Gato extends Animal {

	public Gato(String nome, float peso) {
		super(nome, peso);
	}
	
	public String seLamber() {
		return  this.getNome() + " se lambendo!";
	}

}
