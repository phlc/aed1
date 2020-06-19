/*
Exemplo0216 - v0.0. - 21 / 08 / 2019
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
   int y = 0; // definir variavel com valor inicial

   // identificar
   IO_id ( "EXEMPLO0216 - Programa - v0.0" );

   // ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );
   y = IO_readint ( "Entrar com um segundo valor inteiro: " );

   // testar se primeiro valor impar
   if ( x%2!=0 )
   {
      IO_printf ("%s(%d)\n", "Primeiro valor impar ", x);
   }
   
   else
   {
      IO_printf ("%s(%d)\n", "Primeiro valor nao impar ", x);
   } // fim se
   
   // testar se segundo valor par
   if ( y%2==0 )
   {
      IO_printf ("%s(%d)\n", "Segundo valor par ", y);
   }
   else
   {
      IO_printf ("%s(%d)\n", "Segundo valor nao par ", y);
   } // fim se

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) 1 e 2
b.) 2 e 1
c.) -1 e -2
d.) -2 e -1


---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/