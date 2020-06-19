/*
Exemplo0202 - v0.0. - 20 / 08 / 2019
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
IO_id ( "EXEMPLO0202 - Programa - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
if ( x == 0 )
{
IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
}
else
{
IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
} // fim se
// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco
--------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/