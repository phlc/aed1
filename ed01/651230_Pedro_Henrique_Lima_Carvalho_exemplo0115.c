/*
Exemplo0115 - v0.0. - 20 / 08 / 2019
Author: Pedro Henrique Lima Carvalho

Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0115 exemplo0115.c
Windows: gcc -o exemplo0115.exe exemplo0115.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0115
Windows: exemplo0115
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
   double x = 0; // definir variavel com valor inicial
   double y = 0; // definir variavel com valor inicial
   
// identificar
   printf ( "%s\n", "Exemplo0115 - Programa = v0.0" );
   printf ( "%s\n", "Autor: Pedro Henrique Lima Carvalho" );
   printf ( "\n" ); // mudar de linha

// mostrar valor inicial
   printf ( "%s%lf\n%s%lf\n", "x = ", x, "y = ", y );
         // OBS.: O formato para double -> %lf

// ler do teclado
   printf ( "Entrar com um valor real (base de um triangulo): " );
   scanf ( "%lf", &x );
         // OBS.: Necessario indicar o endereco -> &
   printf ( "Entrar com um valor real (altura de um triangulo): " );
   scanf ( "%lf", &y );
         // OBS.: Necessario indicar o endereco -> &
         

// mostrar valor da area do triangulo
   printf ( "%s%lf\n", "Area do retangulo = ", (x*y/2));
      

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
a.) 2.3 e 4.2
b.) 3.4 e 7
c.) 0.3 e 12

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         20/08    esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
                        leitura de base e altura de triangulo
                        calculo da area
*/