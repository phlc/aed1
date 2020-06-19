/*
Exemplo0107 - v0.0. - 18 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0107 exemplo0107.c
Windows: gcc -o exemplo0107.exe exemplo0107.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0107
Windows: exemplo0107
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres
#include <math.h> // para funcoes matematicas
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados
double x = 0.0; // definir variavel com valor inicial
double y = 0.0; // definir variavel com valor inicial
double z = 0.0; // definir variavel com valor inicial
// identificar
printf ( "%s\n", "EXEMPLO0107 - Programa - v0.0" );
printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
printf ( "\n" ); // mudar de linha
// mostrar valores iniciais
printf ( "%s%lf\n", "x = ", x );
printf ( "%s%lf\n", "y = ", y );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
printf ( "Entrar com um valor real: " );
scanf ( "%lf", &x );
// OBS.: Necessario indicar o endereco -> &
printf ( "Entrar com outro valor real: " );
scanf ( "%lf", &y );
// OBS.: Necessario indicar o endereco -> &
// operar valores
z = pow( x, y ); // elevar a base (x) 'a potencia (y)
// mostrar valor resultante
printf ( "%s(%lf)*(%lf) = (%lf)\n", "z = ", x, y, z );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
fflush ( stdin ); // limpar a entrada de dados
getchar( ); // aguardar por ENTER
return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 2.0 e 3.0
b.) 3.0 e 2.0
c.) -3.0 e 2.0
d.) -2.0 e -3.0
---------------------------------------------- historico
Versao      Data     Modificacao
0.1         18/08    esboco
---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                       Eleva um inteiro a potencia de outro
*/