/*
Exemplo0113 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0113 exemplo0113.c
Windows: gcc -o exemplo0113.exe exemplo0113.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0113
Windows: exemplo0113
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
// definir dados
   int x = 0; // definir variavel com valor inicial
   int y = 0; // definir variavel com valor inicial
   
// identificar
   printf ( "%s\n", "Exemplo0113 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%d\n%s%d\n", "x = ", x, "y = ", y );
         // OBS.: O formato para int -> %d (ou %i)

// ler do teclado
   printf ( "Entrar com um valor inteiro (lado de um retangulo): " );
   scanf ( "%d", &x );
         // OBS.: Necessario indicar o endereco -> &
   printf ( "Entrar com um valor inteiro (outro lado de um retangulo): " );
   scanf ( "%d", &y );
         // OBS.: Necessario indicar o endereco -> &
         

// mostrar valor da area do retangulo
   printf ( "%s%i\n", "Area do retangulo = ", (x*y));
   

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
a.) 2 e 4
b.) 3 e 7
c.) 10 e 12

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de inteiro lado de retangulo
                        calculo da area
*/