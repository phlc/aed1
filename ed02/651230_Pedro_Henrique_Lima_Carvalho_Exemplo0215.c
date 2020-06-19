/*
Exemplo0215 - v0.0. - 21 / 08 / 2019
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
   int x = 0; // definir variavel com valor inicial

   // identificar
   IO_id ( "EXEMPLO0215 - Programa - v0.0" );

   // ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );

   // testar se valor pertence ao intervalo fechado entre (25:99)
   if ( 25<=x && x<=99 )
   {
      if ( x<33 )
      {   
         IO_printf ("%s(%d)\n", "Valor pertence apenas ao intervalo [25:45]", x);   
      }
      if ( x>45 )
      {
         IO_printf ("%s(%d)\n", "Valor pertence apenas ao intervalo [33:99]", x);
      }
      if ( 33<=x && x<=45 )
      {
         IO_printf ("%s(%d)\n", "Valor pertene a ambos intervalos [25:45] e [33:99]", x);
      } 
   }
   
   else
   {
      IO_printf ("%s(%d)\n", "Valor nao pertence aos intervalos [25:45] ou [33:99] ", x);
   } // fim se

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) 24
b.) 32
c.) 33
d.) 45
e.) 46
f.) 99
g.) 100

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/