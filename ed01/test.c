/*
Exemplo0101 - v0.0. - 18 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
Matrícula: 651230
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0101 exemplo0101.c
Windows: gcc -o exemplo0101.exe exemplo0101.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0101
Windows: exemplo0101
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <iostream>
#include <stdlib.h>
#include <string.h>
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
int x = 0; // definir variavel com valor inicial
// identificar
printf ( "%s\n", "Exemplo0101 - Programa = v0.0" );
printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
printf ( "\n" ); // mudar de linha
// mostrar valor inicial
printf ( "%s%d\n", "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
printf ( "Entrar com um valor inteiro: " );
scanf ( "%d", &x );
// OBS.: Necessario indicar o endereco -> &
// mostrar valor lido
printf ( "%s%i\n", "x = ", x );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
system("clear");
fflush ( stdin ); // limpar a entrada de dados
getchar( ); // aguardar por ENTER
return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao            Data Modificacao
0.1               18/08 esboco
---------------------------------------------- testes
Versao            Teste
0.1 01.           ( OK )   identificacao de programa
                           leitura e exibicao de inteiro
*/
