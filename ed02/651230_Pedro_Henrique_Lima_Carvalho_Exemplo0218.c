/*
Exemplo0218 - v0.0. - 21 / 08 / 2019
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

   // identificar
   IO_id ( "EXEMPLO0218 - Programa - v0.0" );

   // ler do teclado
   x = IO_readdouble ( "Entrar com um valor real: " );
   y = IO_readdouble ( "Entrar com um segundo valor real: " );

   // testar se primeiro valor igual ao segundo
   if ( x==y)
   {
      IO_printf ("%s(%lf)(%lf)\n", "Valores sao iguais ", x, y);
   }
   
   else
   {
      // testar se primeiro valor menor que o segundo
      if (x<y)
      {
         IO_printf ("%s(%lf)(%lf)\n", "Primeiro valor menor que segundo ", x, y);
      }
      // primeiro valor maior que o segundo
      else
      {
         IO_printf ("%s(%lf)(%lf)\n", "Primeiro valor maior que segundo ", x, y);
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

a.) 1.2 e 2.2
b.) 2.2 e 1.2
c.) 1.2 e 1.2

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         21/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/