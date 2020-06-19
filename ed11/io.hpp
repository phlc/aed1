/**
   IO_lib 
   Author: Pedro Henrique Lima Carvalho

 */
// ---------------------- lista de dependencias

#include <iostream>    // para entradas e saida
#include <fstream>     // para arquivos
#include <sstream>     // para entradas e saida 

#include <cstdio>      // para entradas e saida
#include <cstdlib>     // para a biblioteca padrao
#include <string>      // para cadeias de caracteres
#include <iomanip>     // para formatos
#include <cmath>       // para definicoes matematicas

#include <stddef.h>    // para definicoes basicas
#include <stdarg.h>    // para tratar argumentos
#include <ctype.h>     // para tipos padroes
#include <time.h>      // para medir tempo

// ---------------------- definicoes uteis


// ---------------------- definicoes de constantes

const   bool FALSE        = false;  // definir constante
const   bool TRUE         = true ;  // definir constante

const   char EOS          = '\0';   // definir fim de cadeia de caracteres
const   char EOL          = '\n';   // definir mudanca de linha
const   char ENDL []      = "\n";   // definir mudanca de linha
const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia
const   int  STR_SIZE     =  80 ;   // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char*   chars  ;            // definir cadeia  de caracteres
typedef int*    ints   ;            // definir arranjo de inteiros
typedef double* doubles;            // definir arranjo de reais
typedef bool*   bools  ;            // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int IO_error = 0;                   // sem erros

// ---------------------- definicoes de funcoes e procedimentos

/**
    Metodo para limpar a saida de dados padrao.
 */
void IO_clrscr ( )
{
    system ( "clear" ); // para Linux   - OBS; NAO RECOMENDADO !
  // system ( "cls"   ); // para Windows - OBS; NAO RECOMENDADO !
} // end IO_flush ( )

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush ( )
{
    fflush ( stdin ); // OBS; NAO RECOMENDADO !
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} // end IO_flush ( )

/**
    Funcao para informar a versao dessa biblioteca.
    @return versao atual
 */
std::string IO_version ( )
{
    std::string x = "v.02";
    return ( x );
} // end IO_version ( )

/**
    Metodo para identificar o programa e a autoria.
    @param text - mensagem a ser exibida
 */
void IO_id ( std::string text )
{
    std::cout << text << std::endl;
    std::cout << "Autor: Pedro Henrique Lima Carvalho";
    std::cout << std::endl;          // mudar de linha
} // fim IO_id ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readint ( std::string text )
{
    int x = 0;
    std::cout << text;
    IO_flush  ( );
    std::cin  >> x;
    return    ( x );
} // end IO_readint ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double IO_readdouble ( std::string text )
{
    double x = 0.0;
    std::cout << text;
    IO_flush  ( );
    std::cin  >> x;
    return    ( x );
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readfloat ( std::string text )
{
    float x = 0.0;
    std::cout << text;
    IO_flush  ( );
    std::cin  >> x;
    return    ( x );
} // end IO_readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar o valor 0 para falso e diferente de zero para verdadeiro
 */
bool IO_readbool ( std::string text )
{
    int x = 0;
    std::cout << text;
    IO_flush  ( );
    std::cin  >> x;
    return    ( x!=0 );
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char IO_readchar ( std::string text )
{
    char x = '0';
    std::cout << text;
    do
    {
      IO_flush    ( );
      x = getchar ( );
    }
    while ( x == '\n' );
    return ( x );
} // end IO_readchar ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
 */
void IO_pause ( void )
{
    std::string dummy;
    std::cin.clear ( );
    std::cin.ignore( );
    std::getline(std::cin, dummy);
} // end IO_pause ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
void IO_pause ( std::string text )
{
    char x = '0';
    std::cout << std::endl << text << std::endl;
    IO_pause ( );
} // end IO_pause ( )

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars IO_new_chars ( int size )
{
    return ( (chars) malloc ( (size+1)*sizeof(char) ) );
} // fim IO_new_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints IO_new_ints ( int size )
{
    return ( (ints) malloc ( (size)*sizeof(int) ) );
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles IO_new_doubles ( int size )
{
    return ( (doubles) malloc ( (size)*sizeof(double) ) );
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bools IO_new_bools ( int size )
{
    return ( (bools) malloc ( (size)*sizeof(bool) ) );
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
std::string IO_concat ( std::string text1, std::string text2 )
{                               // reservar area
  std::string buffer = text1+text2;
  return ( buffer );
} // fim IO_concat ( )

/**
    Funcao para converter valor logico para caracteres.
    @return cadeia com o resultado
    @param x     - valor logico
 */
std::string IO_toString ( bool x )
{                             // variante do sstream( )
    std::stringstream buffer;
    buffer << std::boolalpha << x;
    return ( buffer.str( ) );
} // fim IO_toString_b ( )

/**
    Funcao para converter caractere para caracteres.
    @return cadeia com o resultado
    @param x     - caractere
 */
std::string IO_toString ( char x )
{                             // variante do sstream( )
    std::stringstream buffer;
    buffer << x;
    return ( buffer.str( ) );
} // fim IO_toString ( )

/**
    Funcao para converter inteiro para caracteres.
    @return cadeia com o resultado
    @param x     - valor inteiro
 */
std::string IO_toString ( int x )
{                             // variante do sstream( )
    std::stringstream buffer;
    buffer << x;
    return ( buffer.str( ) );
} // fim IO_toString ( )

/**
    Funcaoo para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
std::string IO_toString ( double x )
{                             // variante do printf( )
    std::stringstream buffer;
    buffer << x;
    return ( buffer.str( ) );
} // fim IO_toString ( )

/**
    Metodo para mostrar uma linha com certo texto.
    @param text1 - primeira cadeia
 */
void IO_print ( std::string text1 )
{
  std::cout << text1;
} // fim IO_print ( )

/**
    Metodo para mostrar uma linha com certo texto
    e mudar de linha.
    @param text1 - primeira cadeia
 */
void IO_println ( std::string text1 )
{
  std::cout << text1 << std::endl;
} // fim IO_println ( )

/**
    Metodo para gravar uma linha em arquivo texto.
    @param filePtr - referencia para arquivo aberto
    @param text1 - cadeia de caracteres a ser gravada
 */
void IO_fprint   ( std::ofstream& filePtr, std::string text1 )
{
  filePtr << text1;
} // fim IO_fprint ( )

/**
    Metodo para gravar uma linha em arquivo texto
    e mudar de linha.
    @param filePtr - referencia para arquivo aberto
    @param text1 - cadeia de caracteres a ser gravada
 */
void IO_fprintln ( std::ofstream& filePtr, std::string text1 )
{
  filePtr << text1 << std::endl;
} // fim IO_fprintln ( )

/**
    Funcao para ler uma palavra de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
std::string IO_fread ( std::ifstream& filePtr )
{
  std::string buffer;

  filePtr >> buffer;                    // ler uma cadeia de caracteres
  return ( buffer );
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
std::string IO_freadln ( std::ifstream& filePtr )
{
  std::string buffer;

  std::getline ( filePtr, buffer );    // ler uma linha
  return ( buffer );
} // fim IO_freadln ( )
/**/
/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text1 - mensagem a ser exibida antes da leitura
 */
std::string IO_readstring ( std::string text1 )
{
  std::string buffer;

  std::cout << text1 ;
  IO_flush  ( )      ;                // limpar a entrada de dados
  std::cin  >> buffer;                // ler cadeia de caracteres

  return ( buffer );
} // fim IO_readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text1 - mensagem a ser exibida antes da leitura
 */
std::string IO_readln ( std::string text1 )
{
  std::string buffer;

  std::cout << text1 ;
  IO_flush  ( )      ;                // limpar a entrada de dados
//std::getline( std::cin, buffer, std::cin.widen('\n') );   // ler cadeia de caracteres
  std::getline( std::cin, buffer, '\n' ); // ler cadeia de caracteres

  return ( buffer );
} // fim IO_readln ( )
