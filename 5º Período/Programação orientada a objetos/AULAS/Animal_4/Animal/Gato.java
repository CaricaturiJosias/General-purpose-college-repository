package Animal;

public class Gato extends Animal {


	public Gato(String nome, float peso) {
		super(nome, peso);
	}
	
	public String seLamber() {
		return this.getNome() + " se lambendo!";
	}

	public String miar() {
		return this.getNome() + " miando: miau, miau, miau....";
	}
	
	@Override
	public String fazerBarulho() {
		return miar();
	}

}
