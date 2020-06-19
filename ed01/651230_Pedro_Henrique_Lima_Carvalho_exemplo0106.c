/*
Exemplo0106 - v0.0. - 18 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0106 exemplo0106.c
Windows: gcc -o exemplo0106.exe exemplo0106.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0106
Windows: exemplo0106
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados
int x = 0; // definir variavel com valor inicial
int y = 0; // definir variavel com valor inicial
int z = 0; // definir variavel com valor inicial
// identificar
printf ( "%s\n", "EXEMPLO0106 - Programa - v0.0" );
printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
printf ( "\n" ); // mudar de linha
// mostrar valores iniciais
printf ( "%s%d\n", "x = ", x );
printf ( "%s%i\n" , "y = ", y );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
printf ( "Entrar com um valor inteiro: " );
scanf ( "%d", &x );
// OBS.: Necessario indicar o endereco -> &
printf ( "Entrar com outro valor inteiro: " );
scanf ( "%i", &y );
// OBS.: Necessario indicar o endereco -> &
// operar valores
z = x * y;
// mostrar valor resultante
printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );
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
a.) 3 e 5
b.) -3 e 5
c.) -3 e -5
---------------------------------------------- historico
Versao      Data     Modificacao
0.1         18/08     esboco
---------------------------------------------- testes
Versao            Teste
0.1               01. ( OK ) identificacao de programa
                             multiplica dois inteiros
*/
