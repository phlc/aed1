/*
Exemplo0212 - v0.0. - 21 / 08 / 2019
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
   IO_id ( "EXEMPLO0212 - Programa - v0.0" );

   // ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );

   // testar se valor 'e par ou impar
   if ( x%2 == 0 )
   {
      IO_printf ( "%s(%d)\n", "Valor par ", x );
      // testar se valor maior que cem
      if ( x > 100)
      {
         IO_printf ( "%s(%d)\n", "Valor maior que 100 ", x);   
      }
      else
      {
         IO_printf ( "%s(%d)\n", "Valor menor que 100 ", x);
      }
   }
   else
   {
      IO_printf ( "%s(%d)\n", "Valor impar ", x );
      // testar se valor menor que menos cem
      if (x < -100)
      {
         IO_printf ("%s(%d)\n", "Valor menor que (-100) ", x);
      }
      else
      {
         IO_printf ("%s(%d)\n", "Valor maior que (-100) ", x);
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

a.) 102
b.) 98
c.) -102
d.) -98

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/