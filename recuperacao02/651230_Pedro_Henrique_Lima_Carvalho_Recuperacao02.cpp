/*
PUC - Minas
Ciencia da Computacao
AED 1
Recuperacao 02
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"
#include "651230_myarray.hpp"
#include "651230_mymatrix.hpp"
#include "651230_produtos.hpp"

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
    IO_id ("Recuperacao 02 - Exercicio 01");

    //definir dados
    Array arranjo(0);

    //ler do arquivo
    arranjo = arranjo.fread("DADOS1.TXT");

    //mostrar arranjo
    arranjo.print();

    //ordenar arranjo
    arranjo.invertSort();

    //mostrar arranjo ordenado
    arranjo.print();

    //gravar arranjo ordenado em arquivo
    arranjo.fprint("DECRESCENTE.TXT");
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 02");

    //definir dados
    Array arranjo(0);
    Array invertido(0);

    //ler do arquivo
    arranjo = arranjo.fread("CRESCENTE.TXT");

    //inverter arranjo
    invertido = invertido.invert(arranjo);

    //mostrar arranjos
    arranjo.print();
    invertido.print();

    //gravar arranjo ordenado em arquivo
    invertido.fprint("INVERTIDOS.TXT");

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 03");

    //definir dados
    Array arranjo(0);
    int segundo_menor = 0;

    //ler do arquivo
    arranjo = arranjo.fread("DADOS1.TXT");

    //mostrar arranjo
    arranjo.print();

    //ordenar arranjo
    segundo_menor = arranjo.lower_2nd();

    //mostrar segundo menor valor
    cout << "Segundo menor valor: " <<  segundo_menor << endl;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 04");

    //definir dados
    Array arranjo1(0);
    Array arranjo2(0);
    Array filtrado(0);

    //ler do arquivo
    arranjo1 = arranjo1.fread("DADOS1.TXT");
    arranjo2 = arranjo2.fread("DADOS2.TXT");

    //filtrar arranjo
    filtrado.filter(arranjo1, arranjo2);

    //mostrar arranjos
    arranjo1.print();
    arranjo2.print();
    filtrado.print();

    //gravar arranjo ordenado em arquivo
    filtrado.fprint("FILTRADOS.TXT");

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 05");

    //definir dados
    int quantidade = 0;
    int binario = 2;

    //ler quantidade de numeros
    do
    {
        cout << "Entre com a quantidade de algarismos a serem inseridos: ";
        cin >> quantidade;
        cout << endl;
    } while (quantidade < 1);

    Array binarios(quantidade);

    //repetir quantidade vezes
    for (int x=0; x<binarios.get_length(); x++)
    {
        do
        {
            //ler valor binario
            cout << "Entre com valor binario (0 ou 1): ";
            cin >> binario;
            cout << endl;        
        } while (binario != 0 && binario != 1);
        binarios.set(x, binario);
    }//fim for

    //mostar arranjo
    binarios.print();

    //mostrar valor em decimal
    cout << "Valor em decimal: " << binarios.convert() << endl;
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 06");

    //definir dados
    int dimensoes = 0;

    //ler dimensoes do teclado
    do
    {
        cout << "Entre com a dimensao da matriz quadrada: ";
        cin >> dimensoes;
        cout << endl;
    } while (dimensoes < 1);

    //criar matriz
    Matrix matriz(dimensoes, dimensoes);

    //preencher matriz com o padrao
    matriz.questao6();

    //mostrar matriz
    matriz.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 07");

    //definir dados
    int dimensoes = 0;

    //ler dimensoes do teclado
    do
    {
        cout << "Entre com a dimensao da matriz quadrada: ";
        cin >> dimensoes;
        cout << endl;
    } while (dimensoes < 1);

    //criar matriz
    Matrix matriz(dimensoes, dimensoes);

    //preencher matriz com o padrao
    matriz.questao7();

    //mostrar matriz
    matriz.print();

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 08");

    //criar matriz
    Matrix matriz(0, 0);

    //preencher matriz com o padrao
    matriz.fread("MATRIZ1.TXT");

    //mostrar matriz
    matriz.print();

    //informar se obedece padrao
    if (matriz.questao8())
    {
        cout << "Matriz obedece ao padrao." << endl;
    }//fim if
    else
    {
        cout << "Matriz NAO obedece ao padrao." << endl;
    };

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 09");

    //criar matrizes
    Matrix matriz1(0, 0);
    Matrix matriz2(0,0);

    //preencher matrizes
    matriz1.fread("MATRIZ1.TXT");
    matriz2.fread("MATRIZ2.TXT");

    //mostrar matrizes
    matriz1.print();
    matriz2.print();

    //comparar matrizes e mostrar resultado da comparacao
    cout << "Resultado da comparacao das matrizes: " << matriz1.compareTo(matriz2) << endl;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ("Recuperacao 02 - Exercicio 10");

    //definir dados
    int quantidade = 0;
    std::string produto = "";
    std::string supermercado = "";
    int codigo = 0;
    double preco = 0.0;

    //ler nome do produto do teclado
    cout << "Entre com o nome do produto a ser pesquisado: ";
    cin >> produto;
    cout << endl;

    //ler quantidade do teclado
    cout << "Entre com a quantidade de supermercados: ";
    do
    {
        cin >> quantidade;
        cout << endl;
    } while (quantidade<1);

    //inicializar produto
    Produto product (produto, quantidade);

    //preencher Produto com dados (1 alem para testar)
    for (int x=0; x<=quantidade; x++)
    {
        cout << "Nome do supermercado: ";
        cin >> supermercado;
        cout << endl << "Codigo do supermercado: ";
        cin >> codigo;
        cout << endl << "Preco do produto: ";
        cin >> preco;
        cout << endl;

        product.insert(supermercado, codigo, preco);
    }//fim for
    
    //mostrar dados
    product.print();

    //mostrar media
    cout << "Media de preco: " << product.average() << endl;

    //mostar supermecados baratos
    product.lower();

    //remover um supermercado
    cout << endl << "Codigo do supermercado a ser removido: ";
    cin >> codigo;
    product.remove(codigo);

    //mostrar dados
    product.print();

    //mostrar media
    cout << "Media de preco: R$" << product.average() << endl;

    //mostar supermecados baratos
    product.lower();
    
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
        IO_id ("Recuperacao 02");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Exercicio 1" << endl;
        cout << " 2 - Exercicio 2" << endl;
        cout << " 3 - Exercicio 3" << endl;
        cout << " 4 - Exercicio 4" << endl;
        cout << " 5 - Exercicio 5" << endl;
        cout << " 6 - Exercicio 6" << endl;
        cout << " 7 - Exercicio 7" << endl;
        cout << " 8 - Exercicio 8" << endl;
        cout << " 9 - Exercicio 9" << endl;
        cout << "10 - Exercicio 10" << endl;

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

/*
------------------------------------Comentarios
Main:   
    v1- Funcionou como esperado

method01:
    v1- funcinou como esperado

method02:
    v1- funcionou como esperado

method03:
    v1- funcinou como esperado

method04:
    v1- funcinou como esperado

method05:
    v1- funcinou como esperado

method06:
    v1- funcionou como esperado

method07:
    v1- preenchendo linhas antes de colunas. Trocado para colunas antes de linhas;
    v2- funcionou como esperado.

method08:
    v1- funcionou como esperado

method09:
    v1- funcinou como esperado

method10:
    v1- erro ao compilar "flexible array not at the end of classe". Nao e' permitido mais de um array flexible
    v2- funcionou com esperado

------------------------------------Testes
method01:   DADOS1.TXT

method02:   CRESCENTE.TXT

method03:   DADOS.TXT

method04:   DADOS1.TXT e DADOS2.TXT

method05:   1011, 21011, 101-11

method06:   4

method07:   4

method08:   MATRIZ1.TXT

method09:   MATRIZ1.TXT e MATRIZ2.TXT, MATRIZ1.TXT e MATRIZ1.TXT, MARTRIZ2.TXT e MATRIZ1.TXT

method10:   insere 6 produtos, retira 1
*/
