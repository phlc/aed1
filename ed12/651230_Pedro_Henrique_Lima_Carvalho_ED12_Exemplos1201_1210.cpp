/*
PUC - Minas
Ciencia da Computacao
AED 1
Pedro Henrique Lima Carvalho
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"
#include "651230_mymatrix.hpp"


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
    Matrix <int> int_matrix ( 2, 2 );
    int_matrix.set ( 0, 0, 1 );
    int_matrix.set ( 0, 1, 2 );
    int_matrix.set ( 1, 0, 3 );
    int_matrix.set ( 1, 1, 4 );

    // identificar
    cout << "\nEXEMPLO1210 - Method01 - v0.0\n" << endl;
    
    // mostrar dados
    int_matrix.print ( );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // definir dados
    Matrix <int> matrix ( 2, 2 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method02 - v0.0" << endl;

    // ler dados
    matrix.read ( );
    
    // mostrar dados
    matrix.print ( );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // definir dados
    Matrix <int> matrix ( 2, 2 );
    
    // identificar
    cout << endl << "EXEMPLO1210 - Method03 - v0.0" << endl;

    // ler dados
    matrix.read ( );

    // mostrar dados
    matrix.print ( );

    // gravar dados
    matrix.fprint( "MATRIX1.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // definir dados
    Matrix <int> matrix ( 1, 1 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method04 - v0.0" << endl;

    // ler dados
    matrix.fread ( "MATRIX1.TXT" );

    // mostrar dados
    matrix.print ( );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // definir dados
    Matrix <int> int_matrix1 ( 2, 2 );
    Matrix <int> int_matrix2 ( 2, 2 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method05 - v0.0" << endl;
    
    // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nOriginal\n" << endl;
    int_matrix1.print ( );

    // copiar dados
    int_matrix2 = int_matrix1;

    // mostrar dados
    cout << "\nCopia\n" << endl;
    int_matrix2.print ( );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // definir dados
    Matrix <int> int_matrix ( 2, 2 );
    int_matrix.set ( 0, 0, 0 ); int_matrix.set ( 0, 1, 0 );
    int_matrix.set ( 1, 0, 0 ); int_matrix.set ( 1, 1, 0 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method06 - v0.0" << endl;

    // mostrar dados
    int_matrix.print ( );

    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;

    // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );
    
    // mostrar dados
    int_matrix.print ( );
    
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // definir dados
    Matrix <int> int_matrix1 ( 1, 1 ); 
    Matrix <int> int_matrix2 ( 1, 1 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method07 - v0.0" << endl;

    // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

    // copiar dados
    int_matrix2 = int_matrix1;

    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

    // testar condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;

    // alterar dados
    int_matrix2.set ( 0, 0, (-1) );

    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

    // testar condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // definir dados
    Matrix <int> int_matrix1 ( 1, 1 );
    Matrix <int> int_matrix2 ( 1, 1 );
    Matrix <int> int_matrix3 ( 1, 1 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method08 - v0.0" << endl;

    // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );
    
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );
    
    // copiar dados
    int_matrix2 = int_matrix1;

    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

    // operar dados
    int_matrix3 = int_matrix1 - int_matrix2;

    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // definir dados
    Matrix <int> int_matrix1 ( 2, 2 );
    int_matrix1.set ( 0, 0, 1 );
    int_matrix1.set ( 0, 1, 0 );
    int_matrix1.set ( 1, 0, 0 );
    int_matrix1.set ( 1, 1, 1 );
    Matrix <int> int_matrix2 ( 1, 1 );
    Matrix <int> int_matrix3 ( 1, 1 );

    // identificar
    cout << endl << "EXEMPLO1210 - Method09 - v0.0" << endl;

    // ler dados
    int_matrix2.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

    // operar dados
    int_matrix3 = int_matrix1 * int_matrix2;

    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // definir dados
    Matrix <int> int_matrix ( 3, 3 );
    int x = 0;
    int y = 0;

    // identificar
    cout << endl << "EXEMPLO1210 - Method10 - v0.0" << endl;

    // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );

    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );
    
    // operar dados
    for ( int x = 0; x < int_matrix.getLines( ); x=x+1 )
    {
        for ( int y = 0; y < int_matrix.getColumns( ); y=y+1 )
        {
            int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
        } // end for
    } // end for

    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
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
        IO_id ("ED12 - Exemplo 1201 - 1210");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Exemplo 1" << endl;
        cout << " 2 - Exemplo 2" << endl;
        cout << " 3 - Exemplo 3" << endl;
        cout << " 4 - Exemplo 4" << endl;
        cout << " 5 - Exemplo 5" << endl;
        cout << " 6 - Exemplo 6" << endl;
        cout << " 7 - Exemplo 7" << endl;
        cout << " 8 - Exemplo 8" << endl;
        cout << " 9 - Exemplo 9" << endl;
        cout << "10 - Exemplo 10" << endl;

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

