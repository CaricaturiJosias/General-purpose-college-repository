import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import java.time.Duration;
import java.time.LocalTime;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;

public class AES 
{
	private static String ALGORITMO = "AES";
	
	public static byte[] cifra(String texto, String chave) 
			throws IllegalBlockSizeException, BadPaddingException, NoSuchAlgorithmException, NoSuchPaddingException, UnsupportedEncodingException, InvalidKeyException
	{
		Key key = 
				new SecretKeySpec(chave.getBytes(StandardCharsets.UTF_8), ALGORITMO);			
		Cipher cifrador = Cipher.getInstance(ALGORITMO);
		cifrador.init(Cipher.ENCRYPT_MODE, key);
		byte[] textoCifrado = cifrador.doFinal(texto.getBytes());
		return textoCifrado;
	}	
	
	public static String decifra(byte[] texto, String chave) 
			throws IllegalBlockSizeException, BadPaddingException, NoSuchAlgorithmException, NoSuchPaddingException, UnsupportedEncodingException, InvalidKeyException
	{
	  	 Key key = 
	  			 new SecretKeySpec(chave.getBytes(StandardCharsets.UTF_8), ALGORITMO);
		 Cipher decifrador = Cipher.getInstance(ALGORITMO);
		 decifrador.init(Cipher.DECRYPT_MODE, key);
    	 byte[] textoDecifrado = decifrador.doFinal(texto);
    	 return new String(textoDecifrado);
	}	
	
	public static void Imprimir(String texto)
	{
		System.out.println(texto);
	}
	
	public static void Imprimir(byte[] texto)
	{
		System.out.println(new String(texto));
	}
	
	public static void main(String[] args) throws Exception {
		try
		{						
			String chave = "bolabolabolabolabolabolabolabola"; //tamanho: 32 bytes
			String texto = "RSA é um  algoritmo que deve o seu nome a três professores do MIT: Ronald Rivest, Adi Shamir e Leonard Adleman";			
			LocalTime start = LocalTime.now();
			byte[] textoCifrado = AES.cifra(texto, chave);
			
			String textoDecifrado = AES.decifra(textoCifrado, chave);
			LocalTime end = LocalTime.now();
			Imprimir(textoCifrado);
			Imprimir(textoDecifrado);
			Duration dur = Duration.between(start, end);
			System.out.printf("\nTempo para cifrar: %d ms", dur.getNano()/1000000);
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}
