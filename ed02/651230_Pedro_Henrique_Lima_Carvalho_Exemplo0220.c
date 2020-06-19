/*
Exemplo0220 - v0.0. - 21 / 08 / 2019
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
   double x = 0.0; // definir variavel com valor inicial
   double y = 0.0; // definir variavel com valor inicial
   double z = 0.0; // definir variavel com valor inicial

   // identificar
   IO_id ( "EXEMPLO0220 - Programa - v0.0" );

   // ler do teclado
   x = IO_readdouble ( "Entrar com um valor real: " );
   y = IO_readdouble ( "Entrar com um segundo valor real: " );
   z = IO_readdouble ( "Entrar com um terceiro valor real: " );

   
   // testar se primeiro valor nao esta entre segundo e terceiro
   if (!((y<x && x<z) || (z<x && x<y)))
   {
      IO_printf ("%s\n", "1o valor nao esta entre segundo e terceiro.");
      // testar se se todos valores sao diferentes
      if ((x!=y && x!=z) && z!=y)
      {
         IO_printf ("%s\n", "Todos valores sao diferentes entre si.");
      }
      else
      {
         IO_printf ("%s\n", "Ha valores iguais.");
      }
   }
   else
   //1o valor esta entre segundo e terceiro, logo todos sao diferentes
   {
      IO_printf ("%s\n", "1o valor esta entre segundo e terceiro");
      IO_printf ("%s\n", "Todos valores sao diferentes");     
   } // fim se
      

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) 1.2, 0.2 e 2.2
b.) 1.2, 2.2 e 0.2
c.) 1.2, 2.2 e 3.2
d.) 1.2, 2.2 e 2.2

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/