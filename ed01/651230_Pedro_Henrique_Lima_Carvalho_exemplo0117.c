/*
Exemplo0117 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0117 exemplo0117.c
Windows: gcc -o exemplo0117.exe exemplo0117.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0117
Windows: exemplo0117
*/

// dependencias
#include <stdio.h> // para as entradas e saidas
#include <math.h>  // para funcoes matematicas

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
   
// identificar
   printf ( "%s\n", "Exemplo0117 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%lf\n", "x = ", x);
         // OBS.: O formato para double -> lf
         
// ler do teclado
   printf ( "Entrar com um valor real (lado de um cubo): " );
   scanf ( "%lf", &x );
         // OBS.: Necessario indicar o endereco -> &
         
// mostrar valor do volume solido do cubo
   printf ( "%s%lf\n", "Volume solido do cubo = ", (pow(x,3)));   
        

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
a.) 2.4
b.) 3.4
c.) 10.02

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de lados de um cubo
                        calculo do volume solido
*/