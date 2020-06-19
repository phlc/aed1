/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 14
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"
#include "651230_string.hpp"


// using namespace
//Obs: namespace para utilizar o minimo possivel os recursos das classes prontas

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
    IO_id ("Exercicio 1");

    //definir dados
    MyString integer("-103430");

    //mostrar MyString
    std::cout << "String: ";
    integer.print();
    std::cout << std::endl;

    //converter para inteiro e mostrar
    std::cout << "Valor convertido: " << integer.toInteger() << std::endl;

    //verificar erro
    if (integer.hasError())
        std::cout << std::endl << integer.getErroMsg() << std::endl;        

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("Exercicio 2");

    //definir dados
    MyString Double("-103.430");

    //mostrar MyString
    std::cout << "String: ";
    Double.print();
    std::cout << std::endl;

    //converter para double e mostrar
    std::cout << "Valor convertido: " << Double.toDouble() << std::endl;

    //verificar erro
    if (Double.hasError())
        std::cout << std::endl << Double.getErroMsg() << std::endl;        

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("Exercicio 3");

    //definir dados
    MyString boolean("true");

    //mostrar MyString
    std::cout << "String: ";
    boolean.print();
    std::cout << std::endl;

    //converter para boolean e mostrar
    std::cout << "Valor convertido: " << boolean.toBoolean() << std::endl;

    //verificar erro
    if (boolean.hasError())
        std::cout << std::endl << boolean.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ("Exercicio 4");

    //definir dados
    MyString string("olarias");

    //mostrar MyString
    std::cout << "String: ";
    string.print();
    std::cout << std::endl;

    //mostrar parametro e responder se contido
    std::cout << "\"lar\" esta contida na string? R: " << string.contains("lar") << std::endl;

    //verificar erro
    if (string.hasError())
        std::cout << std::endl << string.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ("Exercicio 5");
    
    //definir dados
    MyString string1("12#$bv_DX-lfe*LakD");

    MyString string2 = string1.toUpperCase();

    //mostrar MyStrings
    std::cout << "String original: ";
    string1.print();
    std::cout << std::endl;

    std::cout << "String com maisculas: ";
    string2.print();
    std::cout << std::endl;

    //verificar erro
    if (string1.hasError())
        std::cout << std::endl << "String1: " << string1.getErroMsg() << std::endl;
    
    if (string2.hasError())
        std::cout << std::endl << "String2: " << string2.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ("Exercicio 6");

    //definir dados
    MyString string1("12#$bv_DX-lfe*LakD");

    MyString string2 = string1.toLowerCase();

    //mostrar MyStrings
    std::cout << "String original: ";
    string1.print();
    std::cout << std::endl;

    std::cout << "String com minusculas: ";
    string2.print();
    std::cout << std::endl;

    //verificar erro
    if (string1.hasError())
        std::cout << std::endl << "String1: " << string1.getErroMsg() << std::endl;
    
    if (string2.hasError())
        std::cout << std::endl << "String2: " << string2.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ("Exercicio 7");

    //definir dados
    MyString string1("**lsn32**4@%^SFD**");

    MyString string2 = string1.replace('*', '!');

    //mostrar MyStrings
    std::cout << "String original: ";
    string1.print();
    std::cout << std::endl;

    std::cout << "String com substituicoes: ";
    string2.print();
    std::cout << std::endl;

    //verificar erro
    if (string1.hasError())
        std::cout << std::endl << "String1: " << string1.getErroMsg() << std::endl;
    
    if (string2.hasError())
        std::cout << std::endl << "String2: " << string2.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ("Exercicio 8");

    //definir dados
    MyString string(" inicio word1 2word fim ");
    MyString* sequencia[80];
    int quantidade = 0;

    //mostrar MyString
    std::cout << "String original: ";
    string.print();
    std::cout << std::endl;

    //verificar erro
    if (string.hasError())
        std::cout << std::endl << "String1: " << string.getErroMsg() << std::endl;

    //realizar split por espaco 
    quantidade = string.split(sequencia, ' ');
    
    //mostrar MyStrings do arranjo
    for (int x=0; x<quantidade; x++)
    {
        std::cout << "String da posicao n. " <<  x << ": ";
        sequencia[x]->print();
        std::cout << std::endl;
    
        if (sequencia[x]->hasError())
            std::cout << std::endl << "String2: " << sequencia[x]->getErroMsg() << std::endl; 
    }//fim for

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ("Exercicio 9");

    //definir dados
    MyString original("A Casa tem 5 Z");

    MyString cifrada = original.encrypt(29);

    //mostrar MyStrings
    std::cout << "String original: ";
    original.print();
    std::cout << std::endl;

    std::cout << "String com cifrada: ";
    cifrada.print();
    std::cout << std::endl;

    //verificar erro
    if (original.hasError())
        std::cout << std::endl << "String1: " << original.getErroMsg() << std::endl;
    
    if (cifrada.hasError())
        std::cout << std::endl << "String2: " << cifrada.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ("Exercicio 10");

    //definir dados
    MyString cifrada("D Fdvd whp 5 C");

    MyString decifrada = cifrada.decrypt(29);

    //mostrar MyStrings
    std::cout << "String cifrada: ";
    cifrada.print();
    std::cout << std::endl;

    std::cout << "String com decifrada: ";
    decifrada.print();
    std::cout << std::endl;

    //verificar erro
    if (cifrada.hasError())
        std::cout << std::endl << "String1: " << cifrada.getErroMsg() << std::endl;
    
    if (decifrada.hasError())
        std::cout << std::endl << "String2: " << decifrada.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method11.
*/
void method11 ( )
{
    // identificar
    IO_id ("Exercicio 11");

//definir dados
    MyString string("*inicio*word1*2word*fim*");
    MyString* sequencia[80];
    int quantidade = 0;

    //mostrar MyString
    std::cout << "String original: ";
    string.print();
    std::cout << std::endl;

    //verificar erro
    if (string.hasError())
        std::cout << std::endl << "String1: " << string.getErroMsg() << std::endl;

    //realizar split por espaco 
    quantidade = string.split(sequencia, '*');
    
    //mostrar MyStrings do arranjo
    for (int x=0; x<quantidade; x++)
    {
        std::cout << "String da posicao n. " <<  x << ": ";
        sequencia[x]->print();
        std::cout << std::endl;
    
        if (sequencia[x]->hasError())
            std::cout << std::endl << "String2: " << sequencia[x]->getErroMsg() << std::endl; 
    }//fim for

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method11 ( )

/**
Method12.
*/
void method12 ( )
{
    // identificar
    IO_id ("Exercicio 12");

    //definir dados
    MyString string1("Abcd123 4*");

    MyString string2 = string1.invert();

    //mostrar MyStrings
    std::cout << "String original: ";
    string1.print();
    std::cout << std::endl;

    std::cout << "String invertida: ";
    string2.print();
    std::cout << std::endl;

    //verificar erro
    if (string1.hasError())
        std::cout << std::endl << "String1: " << string1.getErroMsg() << std::endl;
    
    if (string2.hasError())
        std::cout << std::endl << "String2: " << string2.getErroMsg() << std::endl; 

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method12 ( )

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
        IO_id ("ED 14");
    
        // mostrar opcoes
        std::cout << "Opcoes " << std::endl;
        std::cout << " 0 - parar " << std::endl;
        std::cout << " 1 - Exercicio 01" << std::endl;
        std::cout << " 2 - Exercicio 02" << std::endl;
        std::cout << " 3 - Exercicio 03" << std::endl;
        std::cout << " 4 - Exercicio 04" << std::endl;
        std::cout << " 5 - Exercicio 05" << std::endl;
        std::cout << " 6 - Exercicio 06" << std::endl;
        std::cout << " 7 - Exercicio 07" << std::endl;
        std::cout << " 8 - Exercicio 08" << std::endl;
        std::cout << " 9 - Exercicio 09" << std::endl;
        std::cout << "10 - Exercicio 10" << std::endl;
        std::cout << "11 - Exercicio E1" << std::endl;
        std::cout << "12 - Exercicio E2" << std::endl;

        // ler do teclado
        std::cout << std::endl << "Entrar com uma opcao: ";
        std::cin >> x;

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
            std::cout << std::endl << "ERRO: Valor invalido." << std::endl;
        } // fim escolher
    }while ( x != 0 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )

/*
------------------------------------Comentarios
Main:   
    v1- Nao parou no final do parametro. Erro na condicao if || errad
    v2- Funcionou como esperado

method01:
    v1- Funcionou como esperado
    v2- Atualizado para abranger numeros negativos

method02:
    v1- Fazendo a contas dos inteiros desde o ultimo node. Acrescentada a volta
    v2- Resultado errado. Erro na funcao pow para decimais
    v3- Funcinou como esperado
    v4- Atualizado para aceitar o formato ".3443"

method03:
    v1- nao funcionou para F e 0. Novamente erro no || do if!!!
    v2- funcionou como esperado

method04:
    v1- entrou em loop infinito. so estava andando nos nodes quando caracter igual
    v2- funcionou como esperado

method05:
    v1- funcinou como esperado

method06:
    v1- funcinou como esperado

method07:
    v1- funcinou como esperado

method08:
    v1- segmentation fault. Arranjo de MyString com a MyString sendo criada staticamente. troca alocacao dinamica
    v2- funcionou como esperado

method09:
    v1- funcinou como esperado

method10:
    v1- erro nas letras finais. Acrescentado controle de modulo e +26 para nao passar negativo
    v2- funcionou como esperado

method11:
    v1- funcionou como esperado. funcao do exercicio 8 ja aceitava parametro

method12:
    v1- segmentation fault. Trabalhando na string errada em this ao inves de p_nova
    v2- funcionou como esperado.

------------------------------------Testes
method01:   -103430 103430

method02:   103.430 -103.430

method03:   1 0 T F true false g trre falls

method04:   olarias laria olar rias larxis

method05:   12#$bv_DX-lfe*LakD

method06:   12#$bv_DX-lfe*LakD

method07:   **lsn32**4@%^SFD**

method08:   " inicio word1 2word fim "

method09:   "A Casa tem 5 Z"

method10:   "D Fdvd whp 5 C"

method11:   *inicio*word1*2word*fim*

method12:   Abcd123 4*

*/
