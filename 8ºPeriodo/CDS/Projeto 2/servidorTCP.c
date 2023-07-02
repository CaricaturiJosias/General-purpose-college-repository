/*

servidor.c
*/

/*
      Protocolo
      formato
      [MSG]-[DATA]
      [4 x char][-][50 x char]
      "GRT!" - Greet (Equivalent to SYN)
      "GRTB" - Greet confirmation
      "I AM" - Sending password
      "OK  " - Acknowledge password
      "!!!!" - Wrong password
      "SAY!" - Client sending a message
      "UHUM" - Signal to the client the server is listening
      "BYE!" - End connection (client)
      "BYEB" - End connection (server)
*/

typedef struct protocolData{
      char protocol[4];
      char ignore[1];
      char data[1495];
} Data;

#include<stdbool.h>
#include<stdio.h>
#include<string.h> //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h> //write
// #include <openssl/md5.h> // Cliente precisa disso

int main(int argc , char *argv[])
{
      /*
      Protocolo
      formato
      [MSG]-[DATA]
      [4 x char][-][50 x char]
      "GRT!" - Greet (Equivalent to SYN)
      "GRTB" - Greet confirmation
      "I AM" - Sending password
      "OK  " - Acknowledge password
      "!!!!" - Wrong password
      "SAY!" - Client sending a message
      "UHUM" - Signal to the client the server is listening
      "BYE!" - End connection (client)
      "BYEB" - End connection (server)
      */
      char * Greet = "GRT!";
      char * Pass_rec = "I AM";
      char * Saying = "SAY!";
      char * ClientBye = "BYE!";
      
      char * senha = "senha";

      FILE * Historico;
      Historico = fopen("palavras.txt", "a");

      bool EXIT = false;

      if(Historico == NULL)
      {
            puts("Não pude acessar o arquivo de registros!");   
            exit(2);             
      }
      fclose(Historico);

      int socket_desc , client_sock , c , read_size;
      struct sockaddr_in server , client;
      char client_message[1500];//Criar socket

      socket_desc = socket(AF_INET , SOCK_STREAM , 0);

      if (socket_desc == -1)
      {
            printf("Nao foi possivel criar o socket!\n");
      }

      printf("Socket criado!\n");

      //Preparar a estrutura sockaddr_in
      server.sin_family = AF_INET;
      server.sin_addr.s_addr = INADDR_ANY;
      server.sin_port = htons( 10000 );

      //Bind
      if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
      {
            //Mensagem de erro
            perror("bind falhou. Erro!\n");
            return 1;
      }
      printf("bind OK!\n");

      //Listen
      listen(socket_desc , 3);

      //Esperando cliente.....
      printf("Esperando conexoes de clientes...\n");

      c = sizeof(struct sockaddr_in);
      client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

      if (client_sock < 0)
      {
                  perror("accept falhou!\n");
                  return 1;
      }

      printf("Conexao de cliente aceita!\n");
      //Recebe uma mensagem do cliente

      while( (read_size = recv(client_sock , client_message , 1500 , 0)) > 0 )
      {
            /*
            ------------------------------------------------------------
            Procesando resposta do servidor
            Respostas:
            Greet= "GRT!"
            GreetB = "GRTB"
            I_am = "I AM"
            I_know= "OK  "
            D_know= "!!!!"
            Say= "SAY "
            Heard = "UHUM"
            ClientBye= "BYE "
            ServerBye = "BYEB"

            Greet
            Pass_recstrcpy
            Saying
            ClientBye
            */
            if (EXIT)
            {
                  puts("Encerrando...");
                  exit(1);
            }
            Historico = fopen("palavras.txt", "a");

            if(Historico == NULL)
            {
                  puts("Não pude acessar o arquivo de registros!");   
                  exit(2);             
            }
            
            //Envia mensagem de volta ao cliente
            Data * recebido = (Data *) client_message;
            Data * response;
            response= malloc(sizeof(Data));
            memset(response,'\0',sizeof(response));
            printf("\n%s", recebido->data);
            if (!strncmp(recebido->protocol, Greet, 4))
            {
                  strcpy((char *)response, "GRTB-\0");
                  strcat(response, "Handshake\0");
            }
            else if (!strncmp(recebido->protocol, Pass_rec, 4))
            {
                  if (!strncmp(senha, recebido->data, sizeof(recebido->data)/sizeof(char)))
                  {
                        strcpy((char *) response, "OK  -\0");
                        strcat(response, "Acesso permitido\0");
                  }
                  else 
                  {
                        strcpy((char *) response, "!!!!-\0");
                        strcat(response, "Acesso negado\0");
                  }
            }
            else if (!strncmp(recebido->protocol, Saying, 4))
            {
                  strcpy((char *) response, "UHUM-\0");
                  strcat(response, " Estou escutando\0");
                  fprintf(Historico,"\n%s",recebido->data);
            }
            else if (!strncmp(recebido->protocol, ClientBye, 4))
            {
                  strcpy((char *) response, "BYEB-\0");
                  strcat(response, "Tchau\0");
                  EXIT = true;
            }
            fflush(stdout);
            write(client_sock , response , strlen(response));
            memset(response,'\0',sizeof(response));
            memset(recebido,'\0',sizeof(recebido));
            fclose(Historico);
      }

      if(read_size == 0)
      {
            printf("Cliente desconectado!\n");
            fflush(stdout);
      }

      else if(read_size == -1)
      {
            perror("recv falhou!\n");
      }
      fclose(Historico);
      return 0;
}