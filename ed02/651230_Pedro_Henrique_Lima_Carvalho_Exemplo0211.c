/*
Exemplo0211 - v0.0. - 21 / 08 / 2019
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
   IO_id ( "EXEMPLO0211 - Programa - v0.0" );

   // ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );

   // testar se valor 'e par ou impar
   if ( x%2 == 0 )
   {
      IO_printf ( "%s (%d)\n", "Valor par", x );
   }
   else
   {
      IO_printf ( "%s (%d)\n", "Valor impar", x );
   } // fim se

// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) 2
b.) 3
c.) -4
d.) 0

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/