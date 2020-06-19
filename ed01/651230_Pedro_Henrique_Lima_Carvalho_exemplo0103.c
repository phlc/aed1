/*
Exemplo0103 - v0.0. - 18 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0103 exemplo0103.c
Windows: gcc -o exemplo0103.exe exemplo0103.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0103
Windows: exemplo0103
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
char x = 'A'; // definir variavel com valor inicial
// OBS.: Indispensavel usar apostrofos
// identificar
printf ( "%s\n", "EXEMPLO0103 - Programa - v0.0" );
printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
printf ( "\n" ); // mudar de linha
// mostrar valor inicial
printf ( "%s%c\n", "x = ", x );
// OBS.: O formato para char -> %c
// ler do teclado
printf ( "Entrar com um caractere: " );
scanf ( "%c", &x );
// OBS.: Necessario indicar o endereco -> &
// mostrar valor lido
printf ( "%s%c\n", "x = ", x );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
fflush ( stdin); // limpar a entrada de dados
getchar( ); // aguardar por ENTER
return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )