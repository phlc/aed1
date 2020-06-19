/*
Exemplo0118 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0118 exemplo0118.c
Windows: gcc -o exemplo0118.exe exemplo0118.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0118
Windows: exemplo0118
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
   double x = 0.0; // definir variavel com valor inicial
   double y = 0.0; // definir variavel com valor inicial
   double z = 0.0; // definir variavel com valor inicial
   
// identificar
   printf ( "%s\n", "Exemplo0118 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%lf\n%s%lf\n%s%lf\n", "x = ", x, "y = ", y, "z = ", z );
         // OBS.: O formato para double -> %lf

// ler do teclado
   printf ( "Entrar com um valor real (comprimento de um paralelepipedo): " );
   scanf ( "%lf", &x );
         // OBS.: Necessario indicar o endereco -> &
   printf ( "Entrar com um valor real (largura de um paralelepipedo): " );
   scanf ( "%lf", &y );
         // OBS.: Necessario indicar o endereco -> &
   printf ( "Entrar com um valor real (altura de um paralelepipedo): ");
   scanf ( "%lf", &z );
         // OBS.: Necessario indicar o endereco -> &
         

// mostrar volume solido do paralelepipedo
   printf ( "%s%lf\n", "Volume solido do paralelepipedo = ", (x*y*z));
      

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
a.) 2.3, 3.4 e 4.2
b.) 3.4, 20 e 7
c.) 0.3, 234.003 e 0.02

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de comprimento, largura e altura de paralelepido
                        calculo do volume solido
*/