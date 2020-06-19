
// ----------------------------------------------- definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream ; // para ler arquivo

template < typename T >
class Array
{
    private: // area reservada
        int length;
        T *data;

    public: // area aberta
        Array ( int n )
        {
            // definir valor inicial
            length = n;
            data = NULL;

            // reservar area
            if ( n > 0 )
            {
                data = new T [ length ];
            }
        }// end constructor

        Array ( ) // construtor padrao
        {
            // definir valor inicial
            length = 0;
        
            // reservar area
            data = NULL;
        } // end constructor

        // construtor randomico
        Array (int n, int menor, int maior)
        {
            //definir valor inicial
            length = n;
            data = NULL;

            //reservar area
            if ( n > 0)
            {
                data = new T [ length ];
            }// fim if

            //semear rand
            srand(time(NULL));

            //preencher
            for (int x=0; x<length; x++)
            {
                data[x] = (menor+1 + rand()%(maior - menor - 1));
            }//fim for

        }// end constructor

        // contrutor baseado em copia
        Array ( int length, int other [ ] )
        {
            if ( length == 0 )
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                // criar copia
                this->length = length;

                // reservar area
                data = new T [ this->length ];

                // ler dados
                for ( int x = 0; x < this->length; x=x+1 )
                {
                    data [ x ] = other [ x ];
                } // end for
            } // end if
        } // end constructor ( )

        Array ( const Array& other )
        {
            if ( other.length == 0 )
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                // criar copia
                length = other.length;

                // reservar area
                data = new T [ other.length ];
                
                // ler dados
                for ( int x = 0; x < length; x=x+1 )
                {
                    data [ x ] = other.data [ x ];
                } // end for
            } // end if
        } // end constructor ( )

        Array& operator= ( const Array <T> other )
        {
            if ( other.length == 0 )
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                this->length = other.length;
                this->data = new T [ other.length ];
                for ( int x = 0; x < this->length; x=x+1 )
                {
                    data [ x ] = other.data [ x ];
                } // end for
            } // end if
            return ( *this );
        } // end operator= ( )

        bool operator== ( const Array <T> other )
        {
            bool result = true;
            int x = 0;
            if ( other.length == 0 || length != other.length )
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                x = 0;
                while ( x < this->length && result )
                {
                    result = result && (data [ x ] == other.data [ x ] );
                    x = x + 1;
                } // end for
            } // end if
            return ( result );
        } // end operator== ( )

        Array& operator+ ( const Array <T> other )
        {
            static Array <T> result ( other );
            if ( other.length == 0 )
            {
                cout << "\nERROR: Missing data.\n" << endl;
            }
            else
            {
                for ( int x = 0; x < this->length; x=x+1 )
                {
                    result.data [ x ] = result.data [ x ] + this->data [ x ];
                } // end for
            } // end if
            return ( result );
        } // end operator+ ( )

        T& operator[]( const int position )
        {
            static T value = 0; // return value has type dependency
            if ( position < 0 || length <= position )
            {
                cout << endl << "\nERROR: Invalid position.\n" << endl;
            }
            else
            {
                value = data [ position ];
            } // end if
            return ( value );
        } // end operator[]

        //verifica se arranjos sao diferentes
        bool operator!=(const Array <T> other)
        {
            bool resultado = true;

            if (other.length != length || length == 0)
            {
                std:: cout << std:: endl << "Arranjos de tamanhos diferentes ou 0" << std:: endl;
            }//fim if
            else
            {
                resultado = false;

                for (int x=0; x<length && !resultado; x++)
                {
                    if (data[x] != other.data[x])
                    {
                        //mudar resultado para verdadeiro
                        resultado = true;
                    }//fim if
                }//fim for
            }//fim else

            return (resultado);
        }//fim operator!=

        Array& operator-(const Array <T> other)
        {
            static Array <T> resultado (other);

            if (other.length != this->length || other.length == 0)
            {
                std:: cout << std:: endl << "Erro tamanhos incompativeis" << std:: endl;
            }//fim if
            else
            {
                for (int x=0; x<other.length; x++)
                {
                    resultado.data[x] = resultado.data[x] - this->data[x];
                }//fim for
            }//fim else
            
            return (resultado);
        }//end operator-

    void free ( )
    {
        if ( data != NULL )
        {
            delete ( data );
            data = NULL;
        } // end if
    } // end free ( )

    void set ( int position, T value )
    {
        if ( 0 <= position && position <= length )
        {
            data [ position ] = value;
        } // end if
    } // end set ( )

    T get ( int position )
    {
        T value = 0; // return value has type dependency
        if ( 0 <= position && position <= length )
        {
            value = data [ position ];
        } // end if
        
        return ( value );
    } // end get ( )

    //retorna o maior elemento
    T biggest ( )
    {
        T big = 0; // tipo depende

        //big igual ao primeiro elemento
        big = data [0];

        for (int x=1; x<length; x++)
        {
            if (data[x] > big)
            {
                big = data[x];
            }//fim if
        }//fim for

        return (big);
    } // end biggest ( )

    //retorna o menor elemento
    T smallest ( )
    {
        T small = 0; // tipo depende

        //small igual ao primeiro elemento
        small = data [0];

        for (int x=1; x<length; x++)
        {
            if (data[x] < small)
            {
                small = data[x];
            }//fim if
        }//fim for

        return (small);
    } // end smallest ( )

    //retorna a soma dos elementos
    T sumall ( )
    {
        T sum = 0; //tipo depende

        //soma todos elementos
        for (int x=0; x<length; x++)
        {
            sum = sum + data[x];
        }//fim for

        return (sum);
    }// end sumall

    //retorna a media dos elemento
    double average ( )
    {
        double average = 0; //tipo depente

        //soma todos elementos
        for (int x=0; x<length; x++)
        {
            average = average + (double) data[x];
        }//fim for

        //calcula a media
        average = average/ (double) length;

        return (average);
    }//end average

    //retorna se todos valores iguais a zero
    bool allzero ( )
    {
        bool zero = true;

        //testar elementos do arranjo
        for (int x=0; x<length && zero; x++)
        {
            if (data[x] != 0)
            {
                zero = false;
            }//fim if
        }//fim for

        return (zero);
    }//end allzero

    //retorna se valores estao em ordem crescente
    bool sorted ( )
    {
        bool sorted = true;

        //testar ordem dos elementos
        for (int x=1; x<length && sorted; x++)
        {
            if (data[x-1] > data[x])
            {
                sorted = false;
            }//fim if
        }//fim for

        return (sorted);
    }//fim sorted

    //retorna se valor esta no arranjo
    //recebe valor como parametro e intervalo de posicoes
    bool find (T value, int init, int end)
    {
        bool found = false;
        
        //testar parametros
        if (init < 0 || end > length-1)
        {
            std:: cout << std:: endl << "Erro: parametros invalidos"
                       << std:: endl;
        }//fim if
        else
        {
            for (int x=init; x<end+1 && !found; x++)
            {
                if (value == data[x])
                {
                    found = true;
                }//fim if
            }//fim for
        }//fim else
        
        return (found);
    }//end find

    //retorna referencia de arranjo multiplicado por constante
    Array& escalar (T constante)
    {
        static Array <T> escalado (length);

        //multiplicar elementos do arranjo
        for (int x=0; x<length; x++)
        {
            escalado.data[x] = data[x]*constante;
        }//fim for

        return (escalado);
    }//fim escalar

    //ordena os elementos do arranjo
    void sort ( )
    {
        T buffer = 0; //depende do tipo
        bool sorted = false;

        //repetir ate estar ordenado
        while (sorted == false)
        {
            sorted = true;

            //verificar todos elementos
            for (int x=1; x<length; x++)
            {
                if (data[x-1] > data[x])
                {
                    //mudar sorted
                    sorted = false;

                    //trocar elementos
                    buffer = data[x-1];
                    data[x-1] = data[x];
                    data[x] = buffer;
                }//fim if
            }//fim for
        }//fim while
    }//fim sort

    void print ( )
    {
        cout << endl;
        for ( int x = 0; x < length; x=x+1 )
        {
            cout << setw( 3 ) << x << " : "
            << setw( 9 ) << data[ x ]
            << endl;
        } // end for

        cout << endl;
    } // end print ( )

    void read ( )
    {
        cout << endl;
        for ( int x = 0; x < length; x=x+1 )
        {
            cout << setw( 3 ) << x << " : ";
            cin >> data[ x ];
        } // end for
        cout << endl;
    } // end read ( )

    void fprint ( string fileName )
    {
        ofstream afile; // output file
        afile.open ( fileName );
        afile << length << endl;
        for ( int x = 0; x < length; x=x+1 )
        {
            afile << data[ x ] << endl;
        } // end for
        afile.close ( );
    } // end fprint ( )

    void fread ( string fileName )
    {
        ifstream afile; // input file
        int n = 0;
        afile.open ( fileName );
        afile >> n;
        if ( n <= 0 )
        {
            cout << "\nERROR: Invalid length.\n" << endl;
        }
        else
        {
            // guardar a quantidade de dados
            length = n;
            // reservar area
            data = new T [ n ];
            // ler dados
            for ( int x = 0; x < length; x=x+1 )
            {
                afile >> data[ x ];
            } // end for
        } // end if
        afile.close ( );
    } // end fread ( )

    const int getLength ( )
    {
        return ( length );
    } // end getLength ( )

};
#endif