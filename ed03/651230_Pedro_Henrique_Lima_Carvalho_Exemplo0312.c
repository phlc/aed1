/*
Exemplo0312 - v0.0. - 24 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Method00 - nao faz nada.
*/
void method00 ( )
   {
   // nao faz nada
   } // fim method00 ( )

/**
Method01 -  Verificar letra maiuscula.
*/
void method01 ( )
{
   // definir dado
   char palavra[STR_SIZE];
   int tamanho = 0;
   
   // identificar
   IO_id ( "EXEMPLO0312 - Method01 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma palavra: " );
   scanf ("%s", palavra);
   
   // verificar tamanho da palavra
   tamanho = strlen (palavra);
   
   // passar por cada letra da palavra
   for (int x = 0; x < tamanho; x = x +1)
   {
      // verificar se letra é maiuscula
      if ((65 <= (int) palavra [x]) && ((int) palavra [x] <= 90))
      {
         printf ("%c\n", palavra [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02 -  Verificar letra maiuscula e contar.
*/
void method02 ( )
{
   // definir dado
   char palavra[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO0312 - Method02 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma palavra: " );
   scanf ("%s", palavra);
   
   // verificar tamanho da palavra
   tamanho = strlen (palavra);
   
   // passar por cada letra da palavra
   for (int x = 0; x < tamanho; x = x +1)
   {
      // verificar se letra é maiuscula
      if ((65 <= (int) palavra [x]) && ((int) palavra [x] <= 90))
      {
         //contar letras maiusculas
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Letra: ", palavra [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
   {

   // definir dado
   int x = 0;

   // repetir até desejar parar
   do
   {

      // identificar
      IO_id ( "EXEMPLO0312 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( "0 - parar" );
      IO_println ( "1 - teste letras maiusculas" );
      IO_println ( "2 - teste letras maiuscula com contagem" );
      IO_println ( "" );
      x = IO_readint ( "Entrar com uma opcao: " );

      // testar valor
      switch ( x )
      {
         case 0:
         method00 ( );
         break;

         case 1:
         method01 ( );
         break;
         
         case 2:
         method02 ( );
         break;

         default:
         IO_pause ( "ERRRO: numero invalido.");
      } // fim escolher

   }
   while ( x != 0 );

   // encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
a.) 0
b.) 1 e AbCdEf
c.) 2 e JdadJEJ

---------------------------------------------- historico

Versao   Data     Modificacao
0.1      24/08    esboco

---------------------------------------------- testes
Versao   Teste
0.1      01. ( OK ) identificacao de programa
*/