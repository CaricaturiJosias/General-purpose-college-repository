
public class Endereco {
	private String logradouro;
	private int num;
	private String cidade;
	private String estado;
	private String cep;

	public Endereco() {
		super();
		this.logradouro = " ";
		this.num = 0;
		this.cidade = "Sem cidade";
		this.estado = " ";
		this.cep = " ";
	}
	
	public Endereco(String logradouro, int num, String cidade, String estado, String cep) {
		super();
		this.logradouro = logradouro;
		this.num = num;
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

	public int getNum() {
		return num;
	}

	public void setNum(int num) {
		this.num = num;
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
		return "Endereco logradouro = " + logradouro + ", num = " + num + ", cidade = " + cidade + ", estado = " + estado
				+ ", cep = " + cep + "";
	}
	
	public String etiquetaPostal() {
		return logradouro + ", "+ num + ", " + cidade + ", " + estado
				+ ", " + cep ;
	}

	
	
	
}
