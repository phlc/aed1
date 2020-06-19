/*
Exemplo0111 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0111 exemplo0111.c
Windows: gcc -o exemplo0111.exe exemplo0111.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0111
Windows: exemplo0111
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
   int x = 0; // definir variavel com valor inicial
   
// identificar
   printf ( "%s\n", "Exemplo0111 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%d\n", "x = ", x );
         // OBS.: O formato para int -> %d (ou %i)

// ler do teclado
   printf ( "Entrar com um valor inteiro (lado de um quadrado): " );
   scanf ( "%d", &x );
         // OBS.: Necessario indicar o endereco -> &

// mostrar valor da area do quadrado
   printf ( "%s%i\n", "Area do quadrado = ", (x*x));

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
a.) 2
b.) 3
c.) 10

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de inteiro lado de quadrado
                        calculo da area
*/