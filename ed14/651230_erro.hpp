/**
Autor: Pedro Henrique Lima Carvalho
erro.hpp
*/

// dependencias
#include <string>

//definicoes
#ifndef _ERRO_HPP_
#define _ERRO_HPP_

/**
* Classe para tratar erro.
*/

class Erro
{
    /*
    * tratamento de erro.
    Codigos de erro:
    0. Nao ha' erro.
    1. Erro: nao foi possivel inicializar;
    2. Erro: nao foi possivel realizar conversao
    3. Erro: parametro sem fim
    */

    /**
    * atributos privados.
    */
    private:
        int erro;

    /**
    * definicoes publicas.
    */
    public:
        
        /**
        * Destrutor.
        */
        ~Erro ( ) { };

        /**
        * Construtor padrao.
        */
        Erro ( ) { };
        
        /**
        * Constante da classe.
        */
        static const std::string NO_ERROR;
        static const std::string ERROR_01;
        static const std::string ERROR_02;
        static const std::string ERROR_03;


// ------------------------------------------- metodos para acesso
        /**
        * Funcao para obter o codigo de erro.
        * @return codigo de erro guardado
        */
        int getErro ( )
        {
            return ( this->erro );
        } // fim getErro( )

        /**
        * Funcao para testar se ha' erro.
        * @return true, se houver;
        * false, caso contrario
        */
        bool hasError ( )
        {
            return (this->getErro()!=0);
        };

        /**
        * Funcao para obter mensagem
        * relativa ao código de erro.
        * @return mensagem sobre o erro
        */
        virtual std::string getErroMsg ( )
        {
            int tipo = this->getErro();
            std::string mensagem;
            
            switch (tipo)
            {
            case 0:
                mensagem = NO_ERROR;
                break;
            
            case 1:
                mensagem = ERROR_01;
                break;

            case 2:
                mensagem = ERROR_02;
                break;
            
            case 3:
                mensagem = ERROR_03;
                break;
            }

            return ( mensagem );
        } // end getErroMsg ( )

    /**
    * definicoes com acesso restrito.
    */
    protected:

// ------------------------------------------- metodos para acesso restrito
        /**
        * Metodo para estabelecer novo codigo de erro.
        * @param codigo a ser guardado
        */
        void setErro ( int codigo )
        {
            this->erro = codigo;
        }
}; // fim class Erro

//inicializacao das constantes
const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";
const std::string Erro::ERROR_01 = "[ERRO] Nao foi possivel inicializar.";
const std::string Erro::ERROR_02 = "[ERRO] Nao foi possivel realizar conversao.";
const std::string Erro::ERROR_03 = "[ERRO] Parametro sem fim.";

#endif