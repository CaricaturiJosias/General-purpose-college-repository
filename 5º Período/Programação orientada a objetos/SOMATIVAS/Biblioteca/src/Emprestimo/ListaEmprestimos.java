package Emprestimo;
import java.io.Serializable;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * <p>Classe do pacote Emprestimo<p/>
 * <p>Essa lista descreve todos os empr�stimos feitos at� agora, independentemente se j� foram devolvidos, esta classe serve para
 * o registro de movimenta��es na biblioteca</p>
 * @author Cez�rio
 * @since 1.0
 * @see {@linkplain Item}, {@linkplain Emprestimo}, {@linkplain Biblioteca}
 */

public class ListaEmprestimos implements Serializable {

	private ArrayList<Emprestimo> alEmprestimos;

	/**
	 * M�todo construtor vazio para ListaEmprestimos
	 * @see {@linkplain Emprestimo}
	 */
	
	public ListaEmprestimos() {
		this.alEmprestimos = new ArrayList<Emprestimo>();
	}
	
	/**
	 * Construtor para hardcoded ou lido em disco r�gido para cria��o da lista 
	 * @param ArrayList<Emmprestimo> lido em hardcode ou em disco r�gido
	 */
	
	//salvo em disco
	public ListaEmprestimos(ArrayList<Emprestimo> lista) {
		this.setAlEmprestimos(lista);
	}
	
	/**
	 * @Override
	 * M�todo toString para representa��o da lista de forma diferente, mostrando todos os itens com um padr�o espec�fico de 
	 * Tipo --> Nome do item --> Id do item --> Disponibilidade do item --> Data de emprestimo do item --> Devolu��o declarada do item
	 */
	
	public String toString() {
		String mensagem = null;
		Iterator<Emprestimo> iterador = this.alEmprestimos.iterator();
		while (iterador.hasNext()) {
			Emprestimo emprestado = iterador.next();
			if (mensagem == null) {
				mensagem = ("\n\n"+emprestado.getItem().getTipo()+" chamado(a) "+ emprestado.getItem().getTituloItem()+ " de id "
							  + (emprestado.getItem().getIdItem()+1)+ "\nDisponibilidade atual do item: "
							  + emprestado.getItem().getDispItem() +"\nEmprestado(a) em "
							  + emprestado.getDataEmprestimo().format(DateTimeFormatter.ofPattern("dd-MM-uuuu"))
							  + "\nDevolu��o programada em " 
						   + emprestado.getDataDevolucao().format(DateTimeFormatter.ofPattern("dd-MM-uuuu")))+"\n";
			} else {
				mensagem = mensagem + ("\n\n"+emprestado.getItem().getTipo()+" chamado(a) "+ emprestado.getItem().getTituloItem()
									+ " de id " + (emprestado.getItem().getIdItem()+1) + "\nDisponibilidade atual do item: " 
									+ emprestado.getItem().getDispItem() + "\nEmprestado em "
									+ emprestado.getDataEmprestimo().format(DateTimeFormatter.ofPattern("dd-MM-uuuu"))
									+ "\nDevolu��o programada em " 
									+ emprestado.getDataDevolucao().format(DateTimeFormatter.ofPattern("dd-MM-uuuu")))+"\n";	
			}
		}
		if (mensagem == null) {
			mensagem = "Nenhum empr�stimo encontrado!";
		}
		return mensagem;
	}
	public ArrayList<Emprestimo> getAlEmprestimos() {
		return alEmprestimos;
	}
	public void setAlEmprestimos(ArrayList<Emprestimo> alEmprestimos) {
		this.alEmprestimos = alEmprestimos;
	}
}
