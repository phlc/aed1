/*
Exemplo0410 - v0.0. - 31 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Funcao para determinar se valor inteiro e' positivo.
@return true, se positivo; false, caso contrario
@param x - valor a ser testado
*/
bool positive ( int x )
{
   // definir dado local
   bool result = false;
   
   // testar a condicao
   if ( x > 0 )
   {
      result = true;
   } // fim se
   
   return ( result );
} // fim positive ( )


/**
Funcao para determinar se valor inteiro pertence a intervalo aberto.
@return true, se pertencer; false, caso contrario
@param x - valor a ser testado
*/
bool belongsto ( int x, int inferior, int superior )
{
   // definir dado local
   bool result = false;

   // testar a condicao
   if ( inferior < x && x < superior )
   {
      result = true;
   } // fim se

   return ( result );
} // fim belongsto ( )

/**
Funcao para determinar se valor inteiro e' par.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool even ( int x )
{
   // definir dado local
   bool result = false;
   
   // testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
   if ( x % 2 == 0 )
   {
      result = true;
   } // fim se

   return ( result );
} // fim even ( )

/**
Funcao para determinar se caractere e' letra minuscula.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool islowercase ( char x )
{
   // definir dado local
   bool result = false;

   // testar a condicao
   if ( 'a' <= x && x <= 'z' )
   {
      result = true;
   } // fim se
   
   return ( result );
} // fim isLowerCase ( )

/**
Funcao para determinar se caractere e' digito.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool isdigit2 ( char x )
{
   // definir dado local
   bool result = false;

   // testar a condicao
   if ( '0' <= x && x <= '9' )
   {
      result = true;
   } // fim se

   return ( result );
} // fim isDigit2 ( )

/**
Funcao para determinar se caractere e' digito.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool isadigit ( char x )
{
   return ( '0' <= x && x <= '9' );
} // fim isADigit ( )

/**
Method00 - nao faz nada.
*/
void method00 ( )
   {
   // nao faz nada
   }// fim method00 ( )

/**
Method01 - Repeticao para ler certa quantidade de valores.
*/
void method01 ( )
   {
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method01 - v0.0" );

   // ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
      // ler valor do teclado
      valor = IO_readint ( IO_concat (
                           IO_concat ( "", IO_tostring_d ( controle ) ),
                           ": " ) );

      // passar ao proximo valor
      controle = controle + 1;

   } // fim repetir

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}// fim method01 ( )

/**
Method02 - Ler valores e contar positivos.
*/
void method02 ( )
{
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method02 - v0.0" );

   // ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
      // ler valor do teclado
      valor = IO_readint ( IO_concat (
      IO_concat ( "", IO_tostring_d ( controle ) ),
                  ": " ) );

      // testar e contar se valor for positivo
      if ( positive ( valor ) )
      {            
         contador = contador + 1;
      } // fim se

      // passar ao proximo valor
      controle = controle + 1;

   } // fim repetir

   // mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03 - Ler valores e contar positivos menores que 100.
*/
void method03 ( )
{
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method03 - v0.0" );

   // ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
      // ler valor do teclado
      valor = IO_readint ( IO_concat (
                           IO_concat ( "", IO_tostring_d ( controle ) ),
                           ": " ) );

      // testar e contar se valor for positivo
      if ( belongsto ( valor, 0, 100 ) )
      {
         contador = contador + 1;
      } // fim se

      // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir

   // mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method04 ( )
{
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method04 - v0.0" );

   // ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
      // ler valor do teclado
      valor = IO_readint ( IO_concat (
                           IO_concat ( "", IO_tostring_d ( controle ) ),
                           ": " ) );

      // testar e contar se valor for positivo menor que 100 e par
      if ( belongsto ( valor, 0, 100 ) && even ( valor ) )
      {
         contador = contador + 1;
      } // fim se

      // passar ao proximo valor
      controle = controle + 1;

   } // fim repetir

   // mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method05 ( )
{
   // definir dado
   int quantidade = 0;
   int valor = 0;
   int controle = 0;
   int contador = 0;
   bool ok = false;

   // identificar
   IO_id ( "EXEMPLO0410 - Method05 - v0.0" );

   // ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
      // ler valor do teclado
      valor = IO_readint ( IO_concat (
                           IO_concat ( "", IO_tostring_d ( controle ) ),
                           ": " ) );

      // testar e contar se valor for positivo menor que 100 e par
      ok = belongsto ( valor, 0, 100 );
      ok = ok && even ( valor );
      if ( ok )
      {
         contador = contador + 1;
      } // fim se

      // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir

   // mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06 - Ler palavra e contar letras minusculas.
*/
void method06 ( )
{
   // definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method06 - v0.0" );

   // ler do teclado
   palavra = IO_readstring ( "Entrar com uma palavra: " );

   // determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );

   // repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
      // isolar um simbolo por vez
      simbolo = palavra [ posicao ];

      // testar e contar se caractere e' letra minuscula
      if ( islowercase ( simbolo ) )
      {
         contador = contador + 1;
      } // fim se
   } // fim repetir

   // mostrar a quantidade de minusculas
   IO_printf ( "%s%d\n", "Minusculas = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method07 ( )
{
   // definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method07 - v0.0" );

   // ler do teclado
   palavra = IO_readstring ( "Entrar com uma palavra: " );

   // determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );

   // repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
      // isolar um simbolo por vez
      simbolo = palavra [ posicao ];

      // testar e contar se caractere e' letra minuscula
      if ( islowercase ( simbolo ) )
      {
         // mostrar
         IO_printf ( "%c ", simbolo );

         // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir

   // mostrar a quantidade de minusculas
   IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08 - Ler palavra, contar e mostrar letras minusculas (alternativo).
*/
void method08 ( )
{
   // definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;
   chars minusculas = IO_new_chars ( STR_SIZE );
   strcpy ( minusculas, STR_EMPTY ); // vazio

   // identificar
   IO_id ( "EXEMPLO0410 - Method08 - v0.0" );

   // ler do teclado
   palavra = IO_readstring ( "Entrar com uma palavra: " );

   // determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );
   
   // repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
      // isolar um simbolo por vez
      simbolo = palavra [ posicao ];

      // testar e contar as letras minusculas de uma palavra
      if ( islowercase ( simbolo ) )
      {
         // concatenar simbolo encontrado
         minusculas = IO_concat ( minusculas, IO_tostring_c ( simbolo ) );
         
         // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir

   // mostrar a quantidade de minusculas
   IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09 - Ler palavra e contar os algarismos.
*/
void method09 ( )
{
   // definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;

   // identificar
   IO_id ( "EXEMPLO0410 - Method09 - v0.0" );

   // ler do teclado
   palavra = IO_readstring ( "Entrar com caracteres: " );

   // determinar a quantidade de simbolos
   tamanho = strlen ( palavra );

   // repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
      // isolar um simbolo por vez
      simbolo = palavra [ posicao ];

      // testar e contar os algarismos em uma cadeia de caracteres
      if ( isdigit2 ( simbolo ) )
      {
         // mostrar
         IO_printf ( "%c ", simbolo );

         // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir

   // mostrar a quantidade de digitos
   IO_printf ( "\n%s%d\n", "Algarismos = ", contador );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10 - Ler palavra e contar os algarismos (alternativo).
*/
void method10 ( )
{
   // definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   chars digitos = IO_new_chars ( STR_SIZE );
   strcpy ( digitos, STR_EMPTY ); // vazio

   // identificar
   IO_id ( "EXEMPLO0410 - Method10 - v0.0" );

   // ler do teclado
   palavra = IO_readstring ( "Entrar com uma palavra: " );

   // determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );

   // repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
      // isolar um simbolo por vez
      simbolo = palavra [ posicao ];

      // testar e contar os algarismos em uma cadeia de caracteres
      if ( isadigit ( simbolo ) )
      {
         // concatenar simbolo encontrado
         digitos = IO_concat ( digitos, IO_tostring_c ( simbolo ) );
      } // fim se
   } // fim repetir

   // mostrar a quantidade de digitos
   IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", (int)strlen( digitos ), digitos );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
{
   // definir dado
   int x = 0;

   // repetir até desejar parar
   do
   {
      // identificar
      IO_id ( "EXEMPLO041p - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( " 0 - parar" );
      IO_println ( " 1 - ler certa quantidade de valores" );
      IO_println ( " 2 - ler valores e contar positivos" );
      IO_println ( " 3 - ler valores e contar positivos menores que 100" );
      IO_println ( " 4 - ler valores e contar positivos menores que 100 e par" );
      IO_println ( " 5 - ler valores e contar positivos menores que 100 e pares (alternativo)" );
      IO_println ( " 6 - ler palavra e contar letras minusculas" );
      IO_println ( " 7 - ler palavra, contar e mostrar letras minusculas" );
      IO_println ( " 8 - ler palavra, contar e mostrar letras minusculas (alternativo)" );
      IO_println ( " 9 - ler palavra e contar algarismos" );
      IO_println ( "10 - ler palavra e contar algarismos (alternativo)" );
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

         case 9:
         method09 ( );
         break;

         case 10:
         method10 ( );
         break;

         default:
         IO_pause ( "ERRO: Valor invalido." );
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

a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
d.) 4 e {-1, 0, 1, 4}
e.) 4 e {-101, -5, 5, 100}
f.) 5 e {-101, -5, 5, 6, 100}
g.) 5 e {-101, -5, 5, 6, 100}
h.) PALAVRA, PALAvRA, Palavra, palavra
i.) PALAVRA, PALAvRA, Palavra, palavra
j.) PALAVRA, PALAvRA, Palavra, palavra
k.) Palav5a, PALAVRA, palavra, P@l@64@
l.) Palav5a, PALAVRA, palavra, P@l@64@

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         31/08   esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/