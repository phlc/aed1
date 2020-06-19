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
    IO_id ("ED 11 - Exemplo 1111");

    //definir dados
    int quantidade = 0;
    int menor = 0;
    int maior = 0;

    //garantir quantidade valida
    do
    {
        std:: cout << "Entre com a quantidade de valores a serem gerados: ";
        std:: cin >> quantidade;
    }while (quantidade < 1); 

    //ler intervalo do teclado
    std:: cout << std:: endl << "Entre com valor inferior do intervalo: ";
    std:: cin >> menor;
    
    //garantir intervalo valido
    do
    {
        std:: cout << std:: endl << "Entre com valor superior do intervalo: ";
        std:: cin >> maior;
    }while (maior <= menor);
    std:: cout << std:: endl;

    //criar arranjo
    Array <int> arranjo (quantidade, menor, maior);

    //gravar arranjo em arquivo
    arranjo.fprint("DADOS.TXT");

    // encerrar
    arranjo.free();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1112");

    //definir dados
    Array <int> arranjo;
    int maior = 0;

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir maior
    maior = arranjo.biggest ( );

    //mostrar maior
    std:: cout << std:: endl << "Maior elemento do arranjo: "
               << maior << std:: endl;  

    // encerrar
    arranjo.free();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1113");
    
    //definir dados
    Array <int> arranjo;
    int menor = 0;

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    menor = arranjo.smallest ( );

    //mostrar menor
    std:: cout << std:: endl << "Menor elemento do arranjo: "
               << menor << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1114");

    //definir dados
    Array <int> arranjo;
    int soma = 0;

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    soma = arranjo.sumall ( );

    //mostrar menor
    std:: cout << std:: endl << "Soma dos elementos do arranjo: "
               << soma << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );

} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1115");
    
    //definir dados
    Array <int> arranjo;
    double media = 0.0;

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    media = arranjo.average ( );

    //mostrar menor
    std:: cout << std:: endl << "Media dos elementos do arranjo: "
               << media << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1116");

    //definir dados
    Array <int> arranjo;
    bool resposta = false;
    string answer = " ";

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    resposta = arranjo.allzero ( );

    //escrever verdadeiro ou falso
    if (resposta)
    {
        answer = "Verdadeiro";
    }//fim if
    else
    {
        answer = "Falso";
    }//fim else
    

    //mostrar menor
    std:: cout << std:: endl << "Todos elementos do arranjo iguais a zero: "
               << answer << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1117");

    //definir dados
    Array <int> arranjo;
    bool resposta = false;
    string answer = " ";

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    resposta = arranjo.sorted ( );

    //escrever verdadeiro ou falso
    if (resposta)
    {
        answer = "Verdadeiro";
    }//fim if
    else
    {
        answer = "Falso";
    }//fim else
    

    //mostrar menor
    std:: cout << std:: endl << "Arranjo esta em ordem crescente: "
               << answer << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1118");

    //definir dados
    Array <int> arranjo;
    bool resposta = false;
    string answer = " ";

    //preencher arranjo do arquivo
    arranjo.fread ("DADOS.TXT");

    //pedir menor
    resposta = arranjo.find (55, 5, 7);

    //escrever verdadeiro ou falso
    if (resposta)
    {
        answer = "Verdadeiro";
    }//fim if
    else
    {
        answer = "Falso";
    }//fim else
    

    //mostrar menor
    std:: cout << std:: endl << "55 esta entre as posicoes 5 e 7 do arranjo: "
               << answer << std:: endl;  

    // encerrar
    arranjo.free ();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1119");

    //definir dados
    Array <int> original;
    Array <int> escalado;
    int constante = 0;

    //ler constante do teclado
    std:: cout << std:: endl << "Entre com a constante: ";
    std:: cin >> constante;
    std:: cout << std:: endl;

    //preencher original do arquivo
    original.fread ("DADOS.TXT");

    //igualar escalado a original multiplicado por constante
    escalado = original.escalar(constante);

    //mostrar arranjos
    std:: cout << std:: endl << "Arranjo original: " << std:: endl;
    original.print();
    std:: cout << std:: endl << "Arranjo escalado: " << std:: endl;
    escalado.print ();

    // encerrar
    original.free();
    escalado.free();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 1120");

    //definir dados
    Array <int> arranjo;

    //preencher original do arquivo
    arranjo.fread ("DADOS.TXT");

    //mostrar arranjo antes
    std:: cout << std:: endl << "Arranjo antes: " << std:: endl;
    arranjo.print();

    //ordenar arranjo
    arranjo.sort();

    //mostrar arranjo depois;
    std:: cout << std:: endl << "Arranjo depois: " << std:: endl;
    arranjo.print();

    // encerrar
    arranjo.free();
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method11.
*/
void method11 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 11E1");

    //definir dados
    Array <int> arranjo1;
    Array <int> arranjo2;
    bool resposta = false;
    string answer = " ";

    //preencher arranjo do arquivo
    arranjo1.fread ("DADOS.TXT");

    //igualar arranjos
    arranjo2 = arranjo1;

    for (int x=0; x<2; x++)
    {
        //mostrar arranjos
        std:: cout << std:: endl << "Arranjo1: " << std:: endl;
        arranjo1.print();
        std:: cout << std:: endl << "Arranjo2: " << std:: endl;
        arranjo2.print ();

        //comparar
        //escrever verdadeiro ou falso
        if (arranjo1!=arranjo2)
        {
            answer = "Verdadeiro";
        }//fim if
        else
        {
            answer = "Falso";
        }//fim else
    
        //mostrar resposta
        std:: cout << std:: endl << "Arranjo arranjos sao diferentes: "
                   << answer << std:: endl;  

        //alterar arranjo 2
        arranjo2.sort();
    }//fim for

    // encerrar
    arranjo1.free ();
    arranjo2.free ();
    IO_pause ( "Apertar ENTER para continuar" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method11 ( )

/**
Method12.
*/
void method12 ( )
{
    // identificar
    IO_id ("ED 11 - Exemplo 11E2");

    //definir dados
    Array <int> arranjo1;
    Array <int> arranjo2;
    Array <int> subtraido;

    //preencher original do arquivo
    arranjo1.fread ("DADOS.TXT");
    arranjo2 = arranjo1;

    //subtrair arranjos
    subtraido = arranjo1 - arranjo2;

    //mostrar arranjos
    std:: cout << std:: endl << "Arranjo 1: " << std:: endl;
    arranjo1.print();
    std:: cout << std:: endl << "Arranjo 2: " << std:: endl;
    arranjo2.print ();
    std:: cout << std:: endl << "Arranjo Subtraido: " << std:: endl;
    subtraido.print ();

    // encerrar
    arranjo1.free();
    arranjo2.free();
    subtraido.free();
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
        IO_id ("ED 11 - Exemplos 1111 - 11E2");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Grava em arquivo arranjo com numeros aleatorios" << endl;
        cout << " 2 - Mostra o maior elemento do arranjo" << endl;
        cout << " 3 - Mostra o menor elemento do arranjo" << endl;
        cout << " 4 - Mostra a soma os elementos do arranjo" << endl;
        cout << " 5 - Mostra a media dos elementos do arranjo" << endl;
        cout << " 6 - Verifica se todos elementos do arranjo iguais a zero" << endl;
        cout << " 7 - Verifica se arranjo esta em ordem crescente" << endl;
        cout << " 8 - Verifica se um numero esta entre determinadas posicoes do arranjo" << endl;
        cout << " 9 - Mostra arranjo original e arranjo escalado por constante" << endl;
        cout << "10 - Ordena valores do arranjo" << endl;
        cout << "11 - Verifica se dois arranjos sao diferentes" << endl;
        cout << "12 - Subtrai dois arranjos" << endl;

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
    v1- Funcionou como esperado

method01:
    v1- Funcinou como esperado

method02:
    v1- Mostrando o segundo maior. Erro variavel do if;
    v2- Funcinou como esperado

method03:
    v1- Funcinou como esperado

method04:
    v1- Funcinou como esperado

method05:
    v1- Nao foi possivel chamar uma funcao da classe dentro de outra. Metodo tradicional;
    v2- Funcinou como esperado

method06:
    v1- Funcinou como esperado

method07:
    v1- Funcinou como esperado

method08:
    v1- Funcionou como esperado

method09:
    v1- Funcinou como esperado

method10:
    v1- Não ordenou. Chamando funcao errada, sorted ao inves de sort
    v2- Funcionou como esperado

method11:
    v1- Funcinou como Esperado

method12:
    v1- Funcionou como Esperado.

------------------------------------Testes
method01:   10, -10, 20
            10, 0, 40

method02:   DADOS.TXT

method03:   DADOS.TXT

method04:   DADOS.TXT

method05:   DADOS.TXT

method06:   DADOS.TXT

method07:   DADOS.TXT

method08:   55, 5, 7, DADOS.TXT

method09: DADOS.TXT  

method10: DADOS.TXT

method11: DADOS.TXT e sorted

method12: DADOS.TXT
*/
