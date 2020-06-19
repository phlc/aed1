/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 11
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"

#include "651230_myarray.hpp"

// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
std::string dummy;
std::cin.clear ( );
std::cout << std::endl << text;
std::cin.ignore( );
std::getline(std::cin, dummy);
std::cout << std::endl << std::endl;
} // end pause ( )

// using namespace
using namespace std;

/**
Method00 - nao faz nada.
*/
void method00 ( )
{
    // nao faz nada
} // fim method00 ( )

/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// definir dados
Array <int> int_array ( 5 );
int_array.set ( 0, 1 );
int_array.set ( 1, 2 );
int_array.set ( 2, 3 );
int_array.set ( 3, 4 );
int_array.set ( 4, 5 );
// identificar
cout << "\nEXEMPLO1101 - Method01 - v0.0\n" << endl;
// mostrar dados
int_array.print ( );
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
// definir dados
Array <int> int_array ( 5 );
// identificar
cout << endl << "EXEMPLO1110 - Method02 - v0.0" << endl;
// ler dados
int_array.read ( );
// mostrar dados
int_array.print ( );
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
// definir dados
Array <int> int_array ( 5 );
// identificar
cout << endl << "EXEMPLO1110 - Method03 - v0.0" << endl;
// ler dados
int_array.read ( );
// mostrar dados
int_array.fprint ( "INT_ARRAY1.TXT" );
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
// definir dados
Array <int> int_array ( 5 );
// identificar
cout << endl << "EXEMPLO1110 - Method04 - v0.0" << endl;
// ler dados
int_array.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
int_array.print ( );
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
// definir dados
int other [ ] = { 1, 2, 3, 4, 5 };
Array <int> int_array ( 5, other );
// identificar
cout << endl << "EXEMPLO1110 - Method05 - v0.0" << endl;
// mostrar dados
cout << "\nCopia\n" << endl;
int_array.print ( );
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
// definir dados
Array <int> int_array1 ( 1 );
// identificar
cout << endl << "EXEMPLO1110 - Method06 - v0.0" << endl;
// ler dados
int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
cout << "\nOriginal\n" << endl;
int_array1.print ( );
// criar copia
Array <int> int_array2 ( int_array1 );
// mostrar dados
cout << "\nCopia\n" << endl;
int_array2.print ( );
// reciclar espaco
int_array1.free ( );
int_array2.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
// definir dados
Array <int> int_array1 ( 1 );
Array <int> int_array2 ( 1 );
// identificar
cout << endl << "EXEMPLO1110 - Method07 - v0.0" << endl;
// ler dados
int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
cout << "\nOriginal\n" << endl;
int_array1.print ( );
// copiar dados
int_array2 = int_array1;
// mostrar dados
cout << "\nCopia\n" << endl;
int_array2.print ( );
// reciclar espaco
int_array1.free ( );
int_array2.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
// definir dados
int other [ ] = { 1, 2, 3 };
Array <int> int_array1 ( 3, other );
Array <int> int_array2 ( 3, other );
int x;
// identificar
cout << endl << "EXEMPLO1110 - Method08 - v0.0" << endl;
// mostrar dados
cout << endl;
cout << "Array_1";
int_array1.print ( );
// mostrar dados
cout << "Array_2";
int_array2.print ( );
// mostrar comparacao
cout << "Igualdade = " << (int_array1==int_array2) << endl;
// alterar dado
int_array2.set ( 0, (-1) );
// mostrar dados
cout << endl;
cout << "Array_1" << endl;
int_array1.print ( );
// mostrar dados
cout << "Array_2" << endl;
int_array2.print ( );
// mostrar comparacao
cout << "Igualdade = " << (int_array1==int_array2) << endl;
// reciclar espaco
int_array1.free ( );
int_array2.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
// definir dados
Array <int> int_array1 ( 1 );
Array <int> int_array2 ( 1 );
Array <int> int_array3 ( 1 );
// identificar
cout << endl << "EXEMPLO1110 - Method09 - v0.0" << endl;
// ler dados
int_array1.fread ( "INT_ARRAY1.TXT" );
// copiar dados
int_array2 = int_array1;
// somar dados
int_array3 = int_array2 + int_array1;
// mostrar dados
cout << endl;
cout << "Original" << endl;
int_array1.print ( );
// mostrar dados
cout << "Copia" << endl;
int_array2.print ( );
// mostrar dados
cout << "Soma" << endl;
int_array3.print ( );
// reciclar espaco
int_array1.free ( );
int_array2.free ( );
int_array3.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
// definir dados
int other [ ] = { 1, 2, 3, 4, 5 };
Array <int> int_array ( 5, other );
int x;
// identificar
cout << endl << "EXEMPLO1110 - Method10 - v0.0" << endl;
// mostrar dados
cout << "\nAcesso externo" << endl;
for ( x=0; x<int_array.getLength( ); x=x+1 )
{
cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
} // fim repetir
cout << endl << "\nFora dos limites:";
cout << endl << "[-1]: " << int_array.get(-1) << endl;
cout << endl << "[" << int_array.getLength( ) << "]: "
<< int_array [ int_array.getLength( ) ] << endl;
// reciclar espaco
int_array.free ( );
// encerrar
pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )


// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        IO_id ("Estudo Dirigido 11");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Exemplo1101" << endl;
        cout << " 2 - Exemplo1102" << endl;
        cout << " 3 - Exemplo1103" << endl;
        cout << " 4 - Exemplo1104" << endl;
        cout << " 5 - Exemplo1105" << endl;
        cout << " 6 - Exemplo1106" << endl;
        cout << " 7 - Exemplo1107" << endl;
        cout << " 8 - Exemplo1108" << endl;
        cout << " 9 - Exemplo1109" << endl;
        cout << "10 - Exemplo1110" << endl;

        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
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
            cout << endl << "ERRO: Valor invalido." << endl;
        } // fim escolher
    }while ( x != 0 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )

