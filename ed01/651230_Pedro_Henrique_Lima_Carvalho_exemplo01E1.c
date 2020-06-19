/*
Exemplo01E1 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo01E1 exemplo01E1.c
Windows: gcc -o exemplo01E1.exe exemplo01E1.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo01E1
Windows: exemplo01E1
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
   printf ( "%s\n", "Exemplo01E1 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%lf\n", "x = ", x);
         // OBS.: O formato para double -> %lf

// ler do teclado
   printf ( "Entrar com um valor real (area de uma quadrado): " );
   scanf ( "%lf", &x );
         // OBS.: Necessario indicar o endereco -> &
         

// calcular e mostrar valor do lado do quadrado
   printf ( "%s%lf\n", "Lado do quadrado = ", (sqrt(x)));
      

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
a.) 4.0
b.) 9.0
c.) 4.84

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de area de um quadrado
                        calculo do lado do quadrado
*/