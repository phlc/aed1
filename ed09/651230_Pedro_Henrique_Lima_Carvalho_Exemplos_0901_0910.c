/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 09
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//definicoes
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void printIntMatrix ( int lines, int columns, int matrix[][columns] )
{
    // definir dado local
    int x = 0;
    int y = 0;

    // mostrar valores na matriz
    for ( x=0; x<lines; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            // mostrar valor
            IO_printf ( "%3d\t", matrix [ x ][ y ] );
        } // fim repetir
    
    IO_printf ( "\n" );
    } // fim repetir
} // printIntMatrix ( )

/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
    // definir dado
    int matrix [ ][3] = { {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}
                        };

    // identificar
    IO_id ( "EXEMPLO0910 - Method01 - v0.0" );

    // executar o metodo auxiliar
    printIntMatrix ( 3, 3, matrix );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
readIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void readIntMatrix ( int lines, int columns, int matrix[][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars ( STR_SIZE );

    // ler e guardar valores em arranjo
    for ( x=0; x<lines; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            // ler valor
            strcpy ( text, STR_EMPTY );
            z = IO_readint ( IO_concat (
                            IO_concat ( IO_concat ( text, IO_tostring_d ( x ) ), ", " ),
                            IO_concat ( IO_concat ( text, IO_tostring_d ( y ) ), " : " ) ) );
            
            // guardar valor
            matrix [ x ][ y ] = z;
        } // fim repetir
    } // fim repetir
} // readIntMatrix ( )

/**
Method02.
*/
void method02 ( )
{
    // definir dados
    int n = 2; // quantidade de valores
    int matrix [ n ][ n ];

    // identificar
    IO_id ( "EXEMPLO0910 - Method02 - v0.0" );

    // ler dados
    readIntMatrix ( n, n, matrix );

    // mostrar dados
    IO_printf ( "\n" );
    printIntMatrix ( n, n, matrix );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, int lines, int columns, int matrix[][columns] )
{
    // definir dados locais
    FILE* arquivo = fopen ( fileName, "wt" );
    int x = 0;
    int y = 0;

    // gravar quantidade de dados
    IO_fprintf ( arquivo, "%d\n", lines );
    IO_fprintf ( arquivo, "%d\n", columns );

    // gravar valores no arquivo
    for ( x=0; x<lines; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            // gravar valor
            IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
        }// fim repetir
    } // fim repetir

    // fechar arquivo
    fclose ( arquivo );
} // fprintIntMatrix ( )

/**
Method03.
*/
void method03 ( )
{
    // definir dados
    int lines = 0;
    int columns = 0;

    // identificar
    IO_id ( "EXEMPLO0910 - Method03 - v0.0" );

    // ler dados
    lines = IO_readint ( "\nlines = " );
    columns = IO_readint ( "\ncolumns = " );
    IO_printf ( "\n" );
    
    if ( lines <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Valor invalido." );
    }
    else
    {
        // reservar espaco
        int matrix [ lines ][ columns ];

        // ler dados
        readIntMatrix ( lines, columns, matrix );

        // mostrar dados
        IO_printf ( "\n" );
        printIntMatrix ( lines, columns, matrix );

        // gravar dados
        IO_printf ( "\n" );
        fprintIntMatrix( "MATRIX1.TXT", lines, columns, matrix );
    } // fim se
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
@return quantidade de linhas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixRows ( chars fileName )
{
    // definir dados locais
    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
    ints array = NULL;

    // ler a quantidade de dados
    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } // fim se

    // retornar dado lido
    return ( n );
} // freadMatrixRows ( )

/**
freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
@return quantidade de colunas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixColumns ( chars fileName )
{
    // definir dados locais
    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );

    // ler a quantidade de dados
    IO_fscanf ( arquivo, "%d", &n );
    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } // fim se

    // retornar dado lido
    return ( n );
} // freadMatrixColumns ( )

/**
freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void freadIntMatrix ( chars fileName, int lines, int columns, int matrix[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    FILE* arquivo = fopen ( fileName, "rt" );

    // ler a quantidade de dados
    IO_fscanf ( arquivo, "%d", &x );
    IO_fscanf ( arquivo, "%d", &y );
    if ( lines <= 0 || lines > x ||
        columns <= 0 || columns > y )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while ( ! feof ( arquivo ) && x < lines )
        {
            y = 0;
            while ( ! feof ( arquivo ) && y < columns )
            {
                // ler valor
                IO_fscanf ( arquivo, "%d", &z );

                // guardar valor
                matrix [ x ][ y ] = z;

                // passar ao proximo
                y = y+1;
            } // fim repetir
        // passar ao proximo
        x = x+1;
        } // fim repetir
    } // fim se
} // freadIntMatrix ( )

/**
Method04.
*/
void method04 ( )
{
    // definir dados
    int lines = 0;
    int columns = 0;

    // identificar
    IO_id ( "EXEMPLO0910 - Method04 - v0.0" );
    
    // ler dados
    lines = freadMatrixRows ( "MATRIX1.TXT" );
    columns = freadMatrixColumns ( "MATRIX1.TXT" );
    if ( lines <= 0 || columns <= 0 )
    {   
        IO_println ( "\nERRO: Valor invalido." );
    }
    else    
    {
        // definir armazenador
        int matrix [ lines ][ columns ];
        
        // ler dados
        freadIntMatrix ( "MATRIX1.TXT", lines, columns, matrix );
        
        // mostrar dados
        IO_printf ( "\n" );
        printIntMatrix ( lines, columns, matrix );
    } // fim se
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
copyIntMatrix - Copiar matriz com valores inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void copyIntMatrix ( int lines, int columns,
int matrix2[ ][columns], int matrix1[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    if ( lines <= 0 || columns <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
        // copiar valores em matriz
        for ( x = 0; x < lines; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                // copiar valor
                matrix2 [ x ][ y ] = matrix1 [ x ][ y ];
            } // fim repetir
        } // fim repetir
    } // fim se
} // copyIntMatrix ( )

/**
Method05.
*/
void method05 ( )
{
    // definir dados
    int lines = 0;
    int columns = 0;

    // identificar
    IO_id ( "EXEMPLO0910 - Method05 - v0.0" );

    // ler dados
    lines = freadMatrixRows ( "MATRIX1.TXT" );
    columns = freadMatrixColumns ( "MATRIX1.TXT" );
    if ( lines <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Valor invalido." );
    }
    else
    {
        // definir armazenadores
        int matrix [ lines ][ columns ];
        int other [ lines ][ columns ];
        
        // ler dados
        freadIntMatrix ( "MATRIX1.TXT", lines, columns, matrix );

        // copiar dados
        copyIntMatrix ( lines, columns, other, matrix );

        // mostrar dados
        IO_printf ( "\nOriginal\n" );
        printIntMatrix ( lines, columns, matrix );

        // mostrar dados
        IO_printf ( "\nCopia\n" );
        printIntMatrix ( lines, columns, other );
    } // fim se

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
transposeIntMatrix - Transpor valores inteiros em matriz.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix2 - grupo de valores inteiros (transposto)
@param matrix1 - grupo de valores inteiros
*/
void transposeIntMatrix ( int lines, int columns,
int matrix2[ ][lines] , int matrix1[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;

    // percorrer a matriz
    for ( x = 0; x<lines; x=x+1 )
    {
        for ( y = 0; y<columns; y=y+1 )
        {
            matrix2[ y ][ x ] = matrix1 [ x ][ y ];
        } // fim repetir
    } // fim repetir
} // transposeIntMatrix ( )

/**
Method06.
*/
void method06 ( )
{
    // definir dados
    int matrix1 [ ][2] = { {1, 0} ,
                           {0, 1} };
    int matrix2 [ ][2] = { {0, 0} ,
                           {0, 0} };
    int matrix3 [ ][3] = { {1, 2, 3} ,
                           {4, 5, 6} };
    int matrix4 [ ][3] = { {1, 2, 3} ,
                           {4, 5, 6} };

    // identificar
    IO_id ( "EXEMPLO0910 - Method06 - v0.0" );

    // testar dados
    IO_println ( "\nMatrix1 " );
    printIntMatrix( 2, 2, matrix1 );
    transposeIntMatrix ( 2, 2, matrix2, matrix1 );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );
    IO_println ( "\nMatrix3" );
    printIntMatrix( 2, 3, matrix3 );
    transposeIntMatrix ( 2, 3, matrix4, matrix3 );
    IO_println ( "\nMatrix4" );
    printIntMatrix( 3, 2, matrix4 );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
isIdentity - Testar se matriz identidade.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
bool isIdentity ( int lines, int columns, int matrix[ ][columns] )
{
    // definir dados locais
    bool result = true;
    int x = 0;
    int y = 0;

    // testar condicao de existencia
    if ( lines <= 0 || columns <= 0 ||
         lines != columns )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
        result = false;
    }
    else
    {
        // testar valores na matriz
        x = 0;
        while ( x<lines && result )
        {
            y = 0;
            while ( y<columns && result )
            {
                // testar valor
                if ( x == y )
                {
                    result = result && ( matrix [ x ][ y ] == 1 );
                }
                else
                {
                    result = result && ( matrix [ x ][ y ] == 0 );
                }// fim se
                
                // passar ao proximo
                y = y + 1;
            } // fim repetir
        // passar ao proximo
        x = x + 1;
        } // fim repetir
    } // fim se

    // retornar resposta
    return ( result );
} // isIdentity ( )

/**
Method07.
*/
void method07 ( )
{
    // definir dados
    int matrix1 [ ][2] = { {0, 0} ,
                           {0, 0} };
    int matrix2 [ ][3] = { {1, 2, 3} ,
                           {4, 5, 6} };
    int matrix3 [ ][2] = { {1, 0} ,
                           {0, 1} };

    // identificar
    IO_id ( "EXEMPLO0910 - Method07 - v0.0" );

    // testar dados
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );
    IO_printf ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 3, matrix2 );
    IO_printf ( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) );
    IO_println ( "\nMatrix3" );
    printIntMatrix( 2, 2, matrix3 );
    IO_printf ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
isEqual - Testar se matrizes iguais.
@return - true, se todos os dados forem iguais;
false, caso contrario
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix1 - grupo de valores inteiros (1)
@param matrix2 - grupo de valores inteiros (2)
*/
bool isEqual ( int lines, int columns,
               int matrix1[ ][columns], int matrix2[ ][columns] )
{
    // definir dados locais
    bool result = true;
    int x = 0;
    int y = 0;

    // mostrar valores na matriz
    x = 0;
    while ( x<lines && result )
    {
        y = 0;
        while ( y<columns && result )
        {
            // testar valor
            result = result &&
                    (matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );

            // passar ao proximo
            y = y + 1;
        } // fim repetir
        
        // passar ao proximo
        x = x + 1;
    } // fim repetir

    // retornar resposta
    return ( result );
} // isEqual ( )

/**
Method08.
*/
void method08 ( )
{
    // definir dados
    int matrix1 [ ][2] = { {0, 0} ,
                           {0, 0} };
    int matrix2 [ ][2] = { {1, 2} ,
                           {3, 4} };
    int matrix3 [ ][2] = { {1, 0} ,
                           {0, 1} };

    // identificar
    IO_id ( "EXEMPLO0910 - Method08 - v0.0" );

    // testar dados
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );
    IO_printf ( "isEqual (matrix1, matrix2) = %d",
    isEqual (2, 2, matrix1, matrix2) );
    copyIntMatrix ( 2, 2, matrix1, matrix3 );
    copyIntMatrix ( 2, 2, matrix2, matrix3 );
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );
    IO_println ( "\nMatrix3" );
    printIntMatrix( 2, 2, matrix2 );
    IO_printf ( "isEqual (matrix1, matrix2) = %d",
    isEqual (2, 2, matrix1, matrix2) );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
addIntMatrix - Somar matrizes com inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix3 - grupo de valores inteiros resultante
@param matrix1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo termo
@param matrix2 - grupo de valores inteiros (2)
*/
void addIntMatrix ( int lines, int columns,
                    int matrix3[ ][columns],
                    int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;

    // mostrar valores na matriz
    for ( x=0; x<lines; x=x+1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            // somar valores
            matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];
        } // fim repetir
    } // fim repetir
} // addIntMatrix ( )

/**
Method09.
*/
void method09 ( )
{
    // definir dados
    int matrix1 [ ][2] = { {1, 2},
                           {3, 4} };
    int matrix2 [ ][2] = { {1, 0},
                           {0, 1} };
    int matrix3 [ ][2] = { {0, 0},
                           {0, 0} };

    // identificar
    IO_id ( "EXEMPLO0910 - Method09 - v0.0" );

    // testar dados
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );

    // soamr matrizes
    addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );
    IO_println ( "\nMatrix3" );
    printIntMatrix( 2, 2, matrix3 );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
mulIntMatrix - Multiplicar matrizes com inteiros.
@param lines3 - quantidade de linhas da matriz (3)
@param columns3 - quantidade de colunas da matriz (3)
@param matrix3 - grupo de valores inteiros resultante
@param lines1 - quantidade de linhas da matriz (1)
@param columns1 - quantidade de colunas da matriz (1)
@param matrix1 - grupo de valores inteiros (1)
@param lines2 - quantidade de linhas da matriz (2)
@param columns2 - quantidade de colunas da matriz (2)
@param matrix2 - grupo de valores inteiros (2)
*/
void mulIntMatrix ( int lines3, int columns3,
                    int matrix3[ ][columns3],
                    int lines1, int columns1,
                    int matrix1[ ][columns1],
                    int lines2, int columns2,
                    int matrix2[ ][columns2] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    int soma = 0;
    if ( lines1 <= 0 || columns1 == 0 ||
         lines2 <= 0 || columns2 == 0 ||
         lines3 <= 0 || columns3 == 0 ||
         columns1 != lines2 ||
         lines1 != lines3 ||
         columns2 != columns3 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        // percorrer valores na matriz resultante
        for ( x=0; x<lines3; x=x+1 )
        {
            for ( y = 0; y < columns3; y = y + 1 )
            {
                // somar valores
                soma = 0;
                for ( z = 0; z < columns1; z = z + 1 )
                {
                    soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];
                } // fim repetir

                // guardar a soma
                matrix3 [ x ][ y ] = soma;
            } // fim repetir
        } // fim repetir
    } // fim se
} // mulIntMatrix ( )
/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ( "EXEMPLO0910 - Method10 - v0.0" );

    // definir dados
    int matrix1 [ ][2] = { {1, 2},
                           {3, 4} };
    int matrix2 [ ][2] = { {1, 0},
                           {0, 1} };
    int matrix3 [ ][2] = { {0, 0},
                           {0, 0} };

    // identificar
    IO_id ( "EXEMPLO0910 - Method09 - v0.0" );

    // testar produto
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );

    // multiplicar matrizes
    mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );
    IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );
    printIntMatrix( 2, 2, matrix3 );

    // outro teste
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );
    IO_println ( "\nMatrix1" );
    printIntMatrix( 2, 2, matrix1 );

    // multiplicar matrizes
    mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );
    IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );
    printIntMatrix( 2, 2, matrix3 );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Funcao Principal - Apresenta menu de escolhas de metodos
*/

int main ()
{
    //definir dados
    int x = 0;

    //apresentar menu
    do
    {
        //identidicar
        printf ("\n");
        IO_id ("ED09 - Exemplos 0901 - 0910");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Mostra Matriz");
        IO_println ("2- Ler Matriz");
        IO_println ("3- Gravar Matriz");
        IO_println ("4- Ler Matriz Arquivo");
        IO_println ("5- Copia Matriz");
        IO_println ("6- Transpor Matriz");
        IO_println ("7- Teste Matriz Identidade");
        IO_println ("8- Teste Matrizes Iguais");
        IO_println ("9- Soma Matrizes");
        IO_println ("10- Multiplica Matrizes");

        //ler teclado
        x = IO_readint ("Escolha uma das opcoes:");

        //chamar metodo de acordo com opcao
        switch (x)
        {
            case 0:
            method00 ();
            break;

            case 1:
            method01 ();
            break;

            case 2:
            method02 ();
            break;

            case 3:
            method03 ();
            break;

            case 4:
            method04 ();
            break;

            case 5:
            method05 ();
            break;            

            case 6:
            method06 ();
            break;

            case 7:
            method07 ();
            break;

            case 8:
            method08 ();
            break;

            case 9:
            method09 ();
            break;            

            case 10:
            method10 ();
            break;

            default:
            IO_pause ("Numero Invalido");
        }
                
    } while (x!=0); //fim while
    
    //encerrar
    IO_pause ("Aperte ENTER para terminar");

    //retorno
    return (0);

}//fim main

