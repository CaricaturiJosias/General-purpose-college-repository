
public class Endereco {
	private String logradouro;
	private int numero; 
	private String cidade;
	private String estado;
	private String cep;

	public Endereco() {
		super(); // esta chamada existe independente do código digitado
		// chamar o construtor da superclasse até chegar a Objet
		this.logradouro = "Sem rua";
		this.numero = 0;
		this.cidade = "Sem cidade";
		this.estado = "Sem estado";
		this.cep = "Sem CEP";
	}
	
	public Endereco(String logradouro, int numero, String cidade, String estado, String cep) {
		super();
		this.logradouro = logradouro;
		this.numero = numero;
		this.cidade = cidade;
		this.estado = estado;
		this.cep = cep;
	}

	public String getLogradouro() {
		return logradouro;
	}

	public void setLogradouro(String logradouro) {
		this.logradouro = logradouro;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public String getCidade() {
		return cidade;
	}

	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	public String getEstado() {
		return estado;
	}

	public void setEstado(String estado) {
		this.estado = estado;
	}

	public String getCep() {
		return cep;
	}

	public void setCep(String cep) {
		this.cep = cep;
	}

	@Override
	public String toString() {
		return "Este endereco fica em " + cidade + ", no estado do " + estado;
	}
	
	public String getEtiquetaPostal() {
		return logradouro + ", " + numero + "\n" + cidade + " - " + estado + "\n" + cep;
	}
}
