/*
Exemplo01E2 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo01E2 exemplo01E2.c
Windows: gcc -o exemplo01E2.exe exemplo01E2.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo01E2
Windows: exemplo01E2
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
   printf ( "%s\n", "Exemplo01E2 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%lf\n", "x = ", x);
         // OBS.: O formato para double -> %lf

// ler do teclado
   printf ( "Entrar com um valor real (volume de uma esfera): " );
   scanf ( "%lf", &x );
         // OBS.: Necessario indicar o endereco -> &
         

// calcular o raio da esfera
   double r = cbrt((3*x)/(4*M_PI));
   
// mostrar o valor do raio da esfera   
   printf ( "%s%lf\n", "Raio da esfera = ", r);
   
// calcular e mostrar a area da superficie da esfera
   printf ( "%s%lf\n", "Area da superficie da esfera = ", (4*M_PI*r*r));
      

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
a.) 9.0
b.) 49.0
c.) 443.84

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de volume de uma esfera
                        calculo do raio e area de sua superficie
*/