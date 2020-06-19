/*
Exemplo02E1 - v0.0. - 21 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/

// dependencias
#include "io.h" // para definicoes proprias

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/

int main ( )
{
   // definir dado
   char x = 'a'; // definir variavel com valor inicial
   char y = 'a'; // definir variavel com valor inicial
   char z = 'a'; // definir variavel com valor inicial

   // identificar
   IO_id ( "EXEMPLO02E1 - Programa - v0.0" );

   // ler do teclado
   x = IO_readchar ( "Entrar com um caracter: " );
   y = IO_readchar ( "Entrar com um segundo caracter: " );
   z = IO_readchar ( "Entrar com um terceiro caracter: " );

   
   // testar se primeiro caracter  esta entre segundo e terceiro
   if (((y<x && x<z) || (z<x && x<y)))
   {
      IO_printf ("%s\n", "1o caracter esta entre limites.");
      //Se esta entre, logo nao e igual aos limites
   }   
   else
   {
      IO_printf ("%s\n", "1o caracter nao esta entre limites.");
      // testar se o primeiro valor igual limites
      if (x==y || x==z)
      {
         IO_printf ("%s\n", "Primeiro caracter 'e igual a um dos limites.");
      }
      else
      {
         IO_printf ("%s\n", "Primeiro caracter nao 'e igual a um dos limites.");
      }
   } // fim se
      

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) a, b e c
b.) c, b e a
c.) b, a e c
d.) c, a e b

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/