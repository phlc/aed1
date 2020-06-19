/*
Exemplo0308 - v0.0. - 24 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
Method01 - Repeticao com teste no inicio.
*/
void method01 ( )
{
// definir dado
int x = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method01 - v0.0" );
// ler do teclado o valor inicial
x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
while ( x > 0 )
{
// mostrar valor atual
IO_println ( IO_tostring_d ( x ) );
// passar ao proximo valor
x = x - 1;
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )
/**
Method02 - Repeticao com teste no inicio.
*/
void method02 ( )
{
// definir dado
int x = 0;
int y = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method02 - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
y = x; // copiar o valor lido (e' melhor)
while ( y > 0 )
{
// mostrar valor atual
IO_println ( IO_tostring_d ( x ) );
// passar ao proximo valor
y = y - 1;
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )
/**
Method03 - Repeticao com teste no inicio.
*/
void method03 ( )
{
// definir dado
int x = 0;
int y = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method03 - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
y = 1; // copiar o valor lido (e' melhor)
while ( y <= x )
{
// mostrar valor atual
IO_printf ( "%d\n", y );
// passar ao proximo valor
y = y + 1;
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
/**
Method04 - Repeticao com teste no inicio e variacao.
*/
void method04 ( )
{
// definir dado
int x = 0;
int y = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method04 - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
for ( y = 1; y <= x; y = y + 1 )
{
// mostrar valor atual
IO_printf ( "%d\n", y );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )
/**
Method05 - Repeticao com teste no inicio e variacao.
*/
void method05 ( )
{
// definir dado
int x = 0;
int y = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method05 - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
for ( y = x; y >= 1; y = y - 1 )
{
// mostrar valor atual
IO_printf ( "%d\n", y );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**
Method06 - Repeticao sobre cadeia de caracateres.
*/
void method06 ( )
{
// definir dado
int x = 0;
int y = 0;
chars palavra = IO_new_chars ( STR_SIZE );
int tamanho = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method06 - v0.0" );
// ler do teclado
palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
tamanho = strlen ( palavra ) - 1;
// inicio teste variacao
for ( y = tamanho; y >= 0; y = y - 1 )
{
// mostrar valor atual
IO_printf ( "%d: [%c]\n", y, palavra [y] );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
Method07 - Repeticao sobre cadeia de caracateres.
*/
void method07 ( )
{
// definir dado
int x = 0;
int y = 0;
char palavra [STR_SIZE];
int tamanho = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method07 - v0.0" );
// ler do teclado
IO_printf ( "Entrar com uma palavra: " );
scanf ( "%s", palavra );
// repetir para cada letra
tamanho = strlen ( palavra );
// inicio teste variacao
for ( y = 0; y < tamanho; y = y + 1 )
{
// mostrar valor atual
IO_printf ( "%d: [%c]\n", y, palavra [y] );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
Method08 - Repeticao com intervalos.
*/
void method08 ( )
{
// definir dado
int inferior = 0;
int superior = 0;
int x = 0;
// identificar
IO_id ( "EXEMPLO0308 - Method08 - v0.0" );
// ler do teclado
inferior = IO_readint ( "Limite inferior do intervalo: " );
superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
for ( x = inferior; x <= superior; x = x + 1 )
{
// mostrar valor atual
IO_printf ( "%d\n", x );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/*
Funcao principal.
*/
int main ( )
{
// definir dado
int x = 0;
// repetir até desejar parar
do
{
// identificar
IO_id ( "EXEMPLO0308 - Programa - v0.0" );
// ler do teclado
IO_println ( "Opcoes" );
IO_println ( "0 - parar" );
IO_println ( "1 - repeticao com teste no inicio (decrescente)" );
IO_println ( "2 - repeticao com teste no inicio (alternativo)" );
IO_println ( "3 - repeticao com teste no inicio ( crescente )" );
IO_println ( "4 - repeticao com teste no inicio e variacao ( crescente )" );
IO_println ( "5 - repeticao com teste no inicio e variacao (decrescente)");
IO_println ( "6 - repeticao sobre cadeia de caracteres (decrescente)" );
IO_println ( "7 - repeticao sobre cadeia de caracteres ( crescente )" );
IO_println ( "8 - repeticao com intervalos ( crescente )" );
IO_println ( "" );
x = IO_readint ( "Entrar com uma opcao: " );
// testar valor
switch ( x )
{
case 0:
method00 ( );
break;
case 1:
method01 ( );
break;
case 2:
method02 ( );
break;
case 3:
method03 ( );
break;
case 4:
method04 ( );
break;
case 5:
method05 ( );
break;
case 6:
method06 ( );
break;
case 7:
method07 ( );
break;
case 8:
method08 ( );
break;
default:
IO_pause ( "ERRO: Valor invalido.");
} // fim escolher
}
while ( x != 0 );
// encerrar
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 1 e 5
c.) 2 e 5
d.) 3 e 5
e.) 4 e -5
f.) 5 e -5
g.) 6 e abcde
h.) 7 e abcde
i.) 8 e [5 : 10]
j.) 9
---------------------------------------------- historico
Versao Data Modificacao
0.1 24/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/