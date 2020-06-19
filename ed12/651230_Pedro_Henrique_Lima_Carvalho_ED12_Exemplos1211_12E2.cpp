/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 12
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
    // identificar
    IO_id ("ED 12 - Exemplo 1211");

    //definir dados
    int inferior = 0;
    int superior = 0;
    int linhas = 0;
    int colunas = 0;

    //ler dados do teclado garantindo valores validos
    do 
    {
        cout << "Entre com numero de linhas: ";
        cin >> linhas;
        cout << endl;
    }while (linhas < 1);

    do
    {
        cout << "Entre com numero de colunas: ";
        cin >> colunas;
        cout << endl;
    }while (colunas < 1);

    cout << "Entre com valor do limite inferior: ";
    cin >> inferior;
    cout << endl;

    do
    {
        cout << "Entre com valor do limite superior: ";
        cin >> superior;
        cout << endl;
    }while (superior <= inferior);

    //construir matrix
    Matrix <int> matrix(linhas, colunas, inferior, superior);

    //gravar matrix em arquivo
    matrix.fprint("DADOS.TXT");

    //mostrar matrix
    matrix.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1212");

    //definir dados
    Matrix <int> matrix (1, 1);

    //ler matrix do arquivo
    matrix.fread ("DADOS.TXT");

    //mostrar matrix
    matrix.print();

    //escalar matrix
    matrix.scale(2);

    //mostrar matrix escalada
    matrix.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo1213");

    //definir dados
    Matrix <int> matrix (3, 3);

    //definir elmentos de matrix
    matrix.set ( 0, 0, 1 );
    matrix.set ( 0, 1, 0 );
    matrix.set ( 0, 2, 0 );
    matrix.set ( 1, 0, 0 );
    matrix.set ( 1, 1, 1 );
    matrix.set ( 1, 2, 0 );
    matrix.set ( 2, 0, 0 );
    matrix.set ( 2, 1, 0 );
    matrix.set ( 2, 2, 1 );

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.isIdentity())
    {
        cout << "Matrix Identidade" << endl;
    }
    else
    {
        cout << "Matrix nao e' identidade" << endl;
    }

    //alterar matrix
    matrix.fread("DADOS.TXT");

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.isIdentity())
    {
        cout << "Matrix Identidade" << endl;
    }
    else
    {
        cout << "Matrix nao e' identidade" << endl;
    }

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1214");

    //definir dados
    Matrix <int> matrix1 (1, 1);
    Matrix <int> matrix2 (1, 1);

    //preencher matrizes
    matrix1.fread("DADOS.TXT");
    matrix2.fread("DADOS.TXT");

    //mostrar matrizes
    matrix1.print();
    matrix2.print();

    if (matrix1 == matrix2)
    {
        cout << "Matrizes sao iguais" << endl;
    }// fim if
    else
    {
        cout << "Matrizes sao diferentes" << endl;
    }// fim if

    //escalar matrix2
    matrix2.scale(2);

    //mostrar matrizes
    matrix1.print();
    matrix2.print();

    if (matrix1 == matrix2)
    {
        cout << "Matrizes sao iguais" << endl;
    }// fim if
    else
    {
        cout << "Matrizes sao diferentes" << endl;
    }// fim if

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1215");
    
    //definir dados
    Matrix <int> matrix1 (1, 1);
    Matrix <int> matrix2 (1, 1);
    Matrix <int> matrix3 (1, 1);

    //preencher matrizes
    matrix1.fread("DADOS.TXT");
    matrix2.fread("DADOS.TXT");

    //mostrar matrizes
    matrix1.print();
    matrix2.print();

    //somar matrizes
    matrix3 = matrix1 + matrix2;

    //mostar matriz somada
    matrix3.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1216");

    //definir dados
    Matrix <int> matrix (1, 1);

    //preencher matrix com dados do arquivo
    matrix.fread("DADOS.TXT");

    //mostrar matriz
    matrix.print();

    //operar matriz
    matrix.addLines (0, 1, 2);

    //mostrar matriz
    matrix.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1217");

    //definir dados
    Matrix <int> matrix (1, 1);

    //preencher matrix com dados do arquivo
    matrix.fread("DADOS.TXT");

    //mostrar matriz
    matrix.print();

    //operar matriz
    matrix.subLines (0, 1, 2);

    //mostrar matriz
    matrix.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1218");

    //definir dados
    Matrix <int> matrix (1, 1);
    int linha = -2;

    //preencher matrix com dados do arquivo
    matrix.fread("DADOS.TXT");

    //mostrar matriz
    matrix.print();

    //procurar valor
    linha = matrix.searchLines(-8);

    //mostrar linha do valor
    if (linha == -1)
    {
        cout << "Numero nao encontrado" << endl;
    }//fim if
    else
    {
        cout << "Valor (-8) encontrado na linha: " << linha << endl;  
    }//fim else

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1219");

//definir dados
    Matrix <int> matrix (1, 1);
    int coluna = -2;

    //preencher matrix com dados do arquivo
    matrix.fread("DADOS.TXT");

    //mostrar matriz
    matrix.print();

    //procurar valor
    coluna = matrix.searchColumns(-8);

    //mostrar linha do valor
    if (coluna == -1)
    {
        cout << "Numero nao encontrado" << endl;
    }//fim if
    else
    {
        cout << "Valor (-8) encontrado na coluna: " << coluna << endl;  
    }//fim else

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ("ED 12 - Exemplo 1220");

    //definir dados
    Matrix <int> matrix (1, 1);
    Matrix <int> matrix_transp (1, 1);

    //preencher matrix com dados do arquivo
    matrix.fread("DADOS.TXT");

    //operar matriz
    matrix_transp = matrix.transpose();

    //mostrar matrizes
    matrix.print();
    matrix_transp.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method11.
*/
void method11 ( )
{
    // identificar 
    IO_id ("ED 12 - Exemplo 12E1");

    //definir dados
    Matrix <int> matrix (3, 3);

    //definir elmentos de matrix
    matrix.set ( 0, 0, 1 );
    matrix.set ( 0, 1, 2 );
    matrix.set ( 0, 2, 3 );
    matrix.set ( 1, 0, 4 );
    matrix.set ( 1, 1, 5 );
    matrix.set ( 1, 2, 6 );
    matrix.set ( 2, 0, 7 );
    matrix.set ( 2, 1, 8 );
    matrix.set ( 2, 2, 9 );

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.increase_horizontal())
    {
        cout << "Matrix segue padrao" << endl;
    }
    else
    {
        cout << "Matrix nao segue padrao" << endl;
    }

    //alterar matrix
    matrix.fread("DADOS.TXT");

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.increase_horizontal())
    {
        cout << "Matrix segue padrao" << endl;
    }
    else
    {
        cout << "Matrix nao segue padrao" << endl;
    }

    // encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // fim method 11 ( )

/**
Method12.
*/
void method12 ( )
{
    // identificar
    IO_id ("ED 12 =  Exemplo 12E2");

    //definir dados
    Matrix <int> matrix (3, 3);

    //definir elmentos de matrix
    matrix.set ( 0, 0, 1 );
    matrix.set ( 0, 1, 4 );
    matrix.set ( 0, 2, 7 );
    matrix.set ( 1, 0, 2 );
    matrix.set ( 1, 1, 5 );
    matrix.set ( 1, 2, 8 );
    matrix.set ( 2, 0, 3 );
    matrix.set ( 2, 1, 6 );
    matrix.set ( 2, 2, 9 );

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.increase_vertical())
    {
        cout << "Matrix segue padrao" << endl;
    }
    else
    {
        cout << "Matrix nao segue padrao" << endl;
    }

    //alterar matrix
    matrix.fread("DADOS.TXT");

    //mostrar matrix
    matrix.print();

    // testar matriz
    if (matrix.increase_vertical())
    {
        cout << "Matrix segue padrao" << endl;
    }
    else
    {
        cout << "Matrix nao segue padrao" << endl;
    }

    // encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // fim method 12 ( )


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
        IO_id ("ED 12 - Exemplos 1211 - 12E2");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Gera matriz com numeros aleatorios e grava em arquivo" << endl;
        cout << " 2 - Escala matriz multiplicando valores por constante" << endl;
        cout << " 3 - Verifica se matriz e'identidade" << endl;
        cout << " 4 - Verifica se duas matrizes sao iguai" << endl;
        cout << " 5 - Soma duas matrizes" << endl;
        cout << " 6 - Operar duas linhas da matriz (l1 = l1 + l2*k)" << endl;
        cout << " 7 - Operar duas linhas da matriz (l1 = l1 - l2*k)" << endl;
        cout << " 8 - Diz em qual linha esta determinado valor se houver" << endl;
        cout << " 9 - Diz em qual coluna esta determinado valor se houver" << endl;
        cout << "10 - Mostra a matriz transposta" << endl;
        cout << "11 - Verifica se a matriz segue padrao de crescimento horizontal" << endl;
        cout << "12 - Verifica se a matriz segue padrao de crescimento vertical" << endl;

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

            case 11:
            method11 ( );
            break;

            case 12:
            method12 ( );
            break;
            
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // fim escolher
    }while ( x != 0 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )

/*
------------------------------------Comentarios
Main:   
    v1- funcinou como esperado

method01:
    v1- funcinou como esperado

method02:
    v1- funcinou como esperado

method03:
    v1- funcionou como esperado

method04:
    v1- funcionou como esperado

method05:
    v1- funcionou como esperado

method06:
    v1- funcionou como esperado

method07:
    v1- funcionou como esperado

method08:
    v1- funcionou como esperado

method09:
    v1- funcionou como esperado

method10:
    v1- funcionou como esperado

method11:
    v1- funcionou como esperado

method12:
    v1- funcionou como esperado

------------------------------------Testes
method01:   3, 3, -10, 10

method02:   DADOS.TXT 2

method03:   Identidade e DADOS.TXT

method04:   DADOS.TXT e DADOS.TXT; DADOS.TXT e escalada

method05:   DADOS.TXT e DADOS.TXT;

method06:   DADOS.TXT

method07:   DADOS.TXT

method08:   DADOS.TXT 10 e -8

method09:   DADOS.TXT 10 e -8

method10:   DADOS.TXT

method11:   Crescente e DADOS.TXT

method12:   Crescente e DADOS.TXT
*/
