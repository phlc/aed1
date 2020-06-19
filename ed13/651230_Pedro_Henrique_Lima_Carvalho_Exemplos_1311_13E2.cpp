/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 13
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.hpp"

// ----------------------------------------------- classes
#include "Extras.hpp" // classe para tratar dados de pessoas

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
    IO_id ("ED 13 - Exemplo 1311");

    // definir dados
    Contato *p_pessoa = new Contato ();

    //atribuir nome
    p_pessoa->setNome();

    //mostrar nome
    cout << "Nome do contato: " << p_pessoa->getNome() << endl;

    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1312");

    // definir dados
    Contato *p_pessoa = new Contato ();

    //atribuir telefone
    p_pessoa->setFone();

    //mostrar telefone
    cout << "Telefone do contato: " << p_pessoa->getFone() << endl;

    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1313");

    // definir dados
    Contato *p_pessoa = new Contato ();

    //atribuir telefone
    p_pessoa->setFone("99976-8878");

    //mostrar telefone se valido
    if (p_pessoa->getErro())
    {
        cout << "Telefone Invalido" << endl;
    }
    else
    {
        cout << "Telefone do contato: " << p_pessoa->getFone() << endl;
    }
    
    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1314");

    // definir dados
    Contato *p_pessoa = new Contato ();

    //atribuir telefone
    p_pessoa->fromFile("contato.txt");

    //mostrar telefone se valido
    if (p_pessoa->getErro())
    {
        cout << "Telefone Invalido" << endl;
    }
    else
    {
        cout << p_pessoa->toString() << endl;
    }
    
    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1315");

    // definir dados
    Contato *p_pessoa = new Contato ("Pedro", "99098-3737", "99038-3939");

    // gravar contato em arquivo
    p_pessoa->toFile("contato_out.txt");
    
    //liberar memoria
    delete p_pessoa;
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1316");

    // definir dados
    Contato *p_pessoa = new Contato ("Pedro", "99098-3737", "99038-3939");

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    
    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1317");

    // definir dados
    Contato *p_pessoa1 = new Contato ("Pedro", "99098-3737", "99038-3939");
    Contato *p_pessoa2 = new Contato ("Joao", "asd", "99038-3939");
    Contato *p_pessoa3 = new Contato ("Jose", "99098-3737", "ads");
    Contato *p_pessoa4 = new Contato ("Maria", "sds", "ads");

    // mostrar numero de telefones validos e contatos
    cout << "Quantidade de fones: " << p_pessoa1->getNValidFones() << endl;
    cout << p_pessoa1->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa2->getNValidFones() << endl;
    cout << p_pessoa2->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa3->getNValidFones() << endl;
    cout << p_pessoa3->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa4->getNValidFones() << endl;
    cout << p_pessoa4->toString() << endl;

    //liberar memoria
    delete p_pessoa1;
    delete p_pessoa2;
    delete p_pessoa3;
    delete p_pessoa4;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1318");

    // definir dados
    Contato *p_pessoa = new Contato ( );

    // atribuir numeros
    p_pessoa->setNome("Pedro");
    p_pessoa->setFone("99987-9098");
    p_pessoa->setFone2("93445-9388");

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa->getNValidFones() << endl;

    
    //liberar memoria
    delete p_pessoa;
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1319");

    // definir dados
    Contato *p_pessoa = new Contato ( );

    // atribuir numeros
    p_pessoa->setNome("Pedro");
    p_pessoa->setFone("99987-9098");
    p_pessoa->setFone2("93445-9388");

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa->getNValidFones() << endl;

    //alterar telefone secundario
    p_pessoa->changeFone2("90000-0000");

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa->getNValidFones() << endl;

    
    //liberar memoria
    delete p_pessoa;

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 1320");

    // definir dados
    Contato *p_pessoa = new Contato ( );

    // atribuir numeros
    p_pessoa->setNome("Pedro");
    p_pessoa->setFone("99987-9098");
    p_pessoa->setFone2("93445-9388");

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa->getNValidFones() << endl;

    //alterar telefone secundario
    p_pessoa->removeFone2( );

    // mostrar contato
    cout << p_pessoa->toString() << endl;
    cout << "Quantidade de fones: " << p_pessoa->getNValidFones() << endl;

    // encerrar
    delete p_pessoa;
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method11.
*/
void method11 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 13E1");

    // definir dados
    Extras *p_pessoa = new Extras ( );

    // atribuir numeros
    p_pessoa->setNome("Pedro");
    p_pessoa->setFone("99987-9098");
    p_pessoa->setFone2("93445-9388");

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // atribuir 5 numeros a lista de telefones
    for (int x=0; x<5; x++)
    {
        p_pessoa->newFone("99999-9999");
    }

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // remover pos 2
    p_pessoa->removeFone(2);

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // sobrescrever pos 3
    p_pessoa->overwriteFone("88888-8888", 3);

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // incluir mais 6 numeros a lista de telefones
    for (int x=0; x<6; x++)
    {
        p_pessoa->newFone("99999-9999");
    }

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // remover ultima pos
    p_pessoa->removeFone(9);

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // encerrar
    delete p_pessoa;
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method12.
*/
void method12 ( )
{
    // identificar
    IO_id ("ED 13 - Exemplo 13E2");

    // definir dados
    Extras *p_pessoa = new Extras ( );

    // atribuir numeros
    p_pessoa->setNome("Pedro");
    p_pessoa->setFone("99987-9098");
    p_pessoa->setFone2("93445-9388");

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // atribuir 5 numeros a lista de telefones
    for (int x=0; x<5; x++)
    {
        p_pessoa->newFone("99999-9999");
    }

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // adicionar endereco profissional
    p_pessoa->setEnd_prof("Rua Azul, 35");

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // adicionar endereco residencial
    p_pessoa->setEnd_resid("Rua Amarela, 89");

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // remove endereco profissional
    p_pessoa->removeEnd_prof( );

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // adicionar endereco residencial
    p_pessoa->removeEnd_resid();

    // mostrar contato
    cout << p_pessoa->toString() << endl;

    // encerrar
    delete p_pessoa;
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
        IO_id ("ED 13 - Exemplos 1311 - 13E2");
    
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Ler nome do teclado" << endl;
        cout << " 2 - Ler telefone do teclado" << endl;
        cout << " 3 - Testa novo metodo que testa telefone valido" << endl;
        cout << " 4 - Ler contato de arquivo" << endl;
        cout << " 5 - Grava contato em arquivo" << endl;
        cout << " 6 - Testa alteracao contato p/ 3 telefones" << endl;
        cout << " 7 - Mostra numero de telefones em contato" << endl;
        cout << " 8 - Testa metodo para atribuir valor ao segundo telefone" << endl;
        cout << " 9 - Testa metodo para alterar o valor do segundo telefone" << endl;
        cout << "10 - Testa metodo para remover o valor do segundo telefone" << endl;
        cout << "11 - Testa altercao de contato para lidar com ate 10 telefones" << endl;
        cout << "12 - Testa alteracao de contato para lidar com enderecos" << endl;

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
    v1- Funcinou como esperado

method01:
    v1- Tentativa de usar getline(). Problemas com lixo.
    v2- usando std:: cin >> nome; funcionou com esperado.

method02:
    v1- usando std:: cin >> fone; funcionou com esperado.

method03:
    v1- funcionou com esperado

method04:
    v1- funcinou com esperado

method05:
    v1- funcinou como esperado

method06:
    v1- method05 preciso ser alterado.

method07:
    v1- funcionou como esperado

method08:
    v1- funcinou como esperado

method09:
    v1- funcinou como esperado

method10:
    v1- funcionou como esperado

method11:
    v1- mostrando numero inexistente, quanto existente. Erro no if
    v2- funcionou como esperado

method12:
    v1- 


------------------------------------Testes
method01:   Pedro

method02:   99009-0090

method03:   9900-0008 99098-7878

method04:   contato.txt

method05:   contato_out.txt

method06:   method05 pre

method07:   pessoa1 pessoa2 pessoa3 pessoa4

method08:   0, 1 no 1o, 1 no 2o e 2 telefones validos

method09:   com e sem telefone secundario

method10:   teste previstos no metodos

method11:   diversos testes previstos no metodo, com e sem numeros validos

method12:   com um e dois enderecos

*/
