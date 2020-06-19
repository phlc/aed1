/*
651230_mymatrix.hpp
Author: Pedro Henrique Lima Carvalho
*/
// ----------------------------------------------- definicoes globais
#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

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
using std::ifstream; // para ler arquivo

template < typename T >
class Matrix
{
private: // area reservada
    int lines ;
    int columns;
    T** data ;

public: // area aberta
    Matrix ( int lines, int columns )
    {
        // definir valores iniciais
        this->lines = lines;
        this->columns = columns;
        
        // reservar area
        data = new T* [ lines ];
        for ( int x = 0; x < lines; x=x+1 )
        {
            data [x] = new T [ columns ];
        } // end for
    } // end constructor

    //construtor de Matrix com numeros aleatorios
    Matrix ( int lines, int columns, int inferior, int superior)
    {
        // definir valores inicial
        this->lines = lines;
        this->columns = columns;

        //reservar area
        data = new int* [lines];
        for (int x=0; x<lines; x++)
        {
            data[x] = new int[columns];
        }//fim for

        //semear rand
        srand (time(NULL));

        //preencer matriz com numeros aleatorios
        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                data[x][y] = inferior + 1 + (rand() % (superior - inferior - 1));
            }//fim for
        }//fim for

    } //fim construtor de Matriz com numeros aleatorios

    ~Matrix ( )
    {
        if ( data != nullptr )
        {
            for ( int x = 0; x < lines; x=x+1 )
            {
                if ( data [x] != nullptr )
                {
                    delete ( data [ x ] );
                }// end if
            } // end for
            delete ( data );
        } // end if
    } // end destructor ( )

    void set ( int line, int column, T value )
    {
        if ( line < 0 || line >= lines ||
            column < 0 || column >= columns )
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data [ line ][ column ] = value;
        } // end if
    } // end set ( )

    T get ( int line, int column )
    {
        T value = 0; // value has type dependency
        if ( line < 0 || line >= lines ||
            column < 0 || column >= columns )
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data [ line ][ column ];
        } // end if
        
        return (value);
    }

    void print ( )
    {
        cout << endl;
        for ( int x = 0; x < lines; x=x+1 )
        {
            for ( int y = 0; y < columns; y=y+1 )
            {
                cout << data[ x ][ y ] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )

    void read ( )
    {
        cout << endl;
        for ( int x = 0; x < lines; x=x+1 )
        {
            for ( int y = 0; y < columns; y=y+1 )
            {
                cout << setw( 2 ) << x << ", "
                    << setw( 2 ) << y << " : ";
                cin >> data[ x ][ y ];
            } // end for
        } // end for
        cout << endl;
    } // end read ( )

    void fprint ( string fileName )
    {
        ofstream afile;
        afile.open ( fileName );
        afile << lines << endl;
        afile << columns << endl;
        for ( int x = 0; x < lines; x=x+1 )
        {   
            for ( int y = 0; y < columns; y=y+1 )
            {
                afile << data[ x ][ y] << endl;
            } // end for
        } // end for
        afile.close ( );
    } // end fprint ( )

    void fread ( string fileName )
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open ( fileName );
        afile >> m;
        afile >> n;
        if ( m <= 0 || n <= 0 )
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        }
        else
        {            
            // guardar a quantidade de dados
            lines = m;
            columns = n;

            // reservar area
            data = new T* [ lines ];
            for ( int x = 0; x < lines; x=x+1 )
            {
                data [x] = new T [ columns ];
            } // end for
            // ler dados
            for ( int x = 0; x < lines; x=x+1 )
            {
                for ( int y = 0; y < columns; y=y+1 )
                {
                    afile >> data[ x ][ y ];
                } // end for
            } // end for
        } // end if
        afile.close ( );
    } // end fread ( )

    Matrix& operator= ( const Matrix <T>  other )
    {
        if ( other.lines == 0 || other.columns == 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else

        {
            this->lines = other.lines; 
            this->columns = other.columns;
            this->data = new T* [ lines ];
            for ( int x = 0; x < lines; x=x+1 )
            {
                this->data [x] = new T [ columns ];
            } // end for
            for ( int x = 0; x < this->lines; x=x+1 )
            {
                for ( int y = 0; y < this->columns; y=y+1 )
                {
                    data [ x ][ y ] = other.data [ x ][ y ];
                } // end for
            } // end for
        } // end if
        return ( *this );
    } // end operator= ( )

    bool isZeros ( )
    {
        bool result = true;
        int x = 0;
        int y = 0;
        while ( x < lines && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                result = result && ( data [ x ][ y ] == 0 );
                y = y + 1;
            } // end for
            x = x + 1;
        } // end while
        return ( result );
    } // end isZeros ( )

    bool operator!= ( const Matrix <T> other )
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if ( other.lines == 0 || lines != other.lines ||
             other.columns == 0 || columns != other.columns )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            x = 0;
            while ( x < lines && ! result )
            {
                y = 0;
                while ( y < columns && ! result )
                {
                    result = ( data [ x ][ y ] != other.data [ x ][ y ] );
                    y = y + 1;
                } // end for
                x = x + 1;
            } // end for
        } // end if
        return ( result );
    } // end operator!= ( )

    Matrix& operator- ( const Matrix <T> other )
    {
        static Matrix <T> result ( 1, 1 );
        int x = 0;
        int y = 0;
        result = other;
        if ( other.lines == 0 || lines != other.lines ||
             other.columns == 0 || columns != other.columns )
        {       
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            for ( int x = 0; x < result.lines; x=x+1 )
            {
                for ( int y = 0; y < result.columns; y=y+1 )
                {
                    result.data [ x ][ y ] = data [ x ][ y ] - other.data [ x ][ y ];
                } // end for
            } // end for
        } // end if
        return ( result );
    } // end operator- ( )

    Matrix& operator* ( const Matrix <T> other )
    {
        static Matrix <T> result ( 1, 1 );
        int x = 0;
        int y = 0;
        int z = 0;
        int sum = 0;
        if ( lines <= 0 || columns == 0 ||
        other.lines <= 0 || other.columns == 0 ||
        columns != other.lines )
        {
            cout << endl << "ERROR: Invalid data." << endl;
            result.data [ 0 ][ 0 ] = 0;
        }
        else
        {
            result.lines = lines;
            result.columns = other.columns;
            result.data = new T* [ result.lines ];
            for ( int x = 0; x < result.lines; x=x+1 )
            {
                result.data [x] = new T [ result.columns ];
            } // end for
            for ( x = 0; x < result.lines; x = x + 1 )
            {
                for ( y = 0; y < result.columns; y = y + 1 )
                {
                    sum = 0;
                    for ( z = 0; z < columns; z = z + 1 )
                    {
                        sum = sum + data [ x ][ z ] * other.data [ z ][ y ];
                    } // end for
                    result.data [ x ][ y ] = sum;
                } // end for
            } // end for
        } // end if
        return ( result );
    } // end operator* ( )

    const int getLines ( )
    {
        return ( lines );
    } // end getLines ( )

    const int getColumns ( )
    {
        return ( columns );
    } // end getColumns ( )

    // Escalar os valores da matriz por uma constante
    void scale (T k)
    {
        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                data[x][y] = data[x][y] * k;
            }//fim for
        }//fim for
    }//fim scale

    // Testar se matriz identidade
    bool isIdentity ()
    {
        bool result = true;

        if (lines != columns)
        {
            result = false;
        }//fim if

        for (int x=0; x<lines && result; x++)
        {
            for (int y=0; y<columns && result; y++)
            {
                if (x==y)
                {
                    result = (data[x][y] == 1);
                }// fim if
                else
                {
                    result = (data[x][y] == 0);
                }
            }//fim for
        }//fim for

        return (result);
    }// fim isIdentity

    //oparador testa igualdade
    bool operator==(const Matrix <T> other)
    {
        bool result = false;

        if (this->lines == other.lines || this->columns == other.columns)
        {
            result = true;
            for (int x=0; x<this->lines && result; x++)
            {
                for (int y=0; y<this->columns && result; y++)
                {
                    if (this->data[x][y] != other.data[x][y])
                    {
                        result = false;
                    }//fim if
                }//fim for
            }//fim for
        }//fim else

        return (result);
    }//fim operator==

    //operador soma
    Matrix& operator+ (Matrix <T> other)
    {
        static Matrix <T> result (1, 1);

        if (this->lines != other.lines || this->columns != other.columns)
        {
            std:: cout << "Dimensoes diferentes - Erro ao somar" <<  std:: endl;
        }//fim if
        else
        {
            result.lines = this->lines;
            result.columns = this->columns;
            result.data = new T* [result.lines];
            for (int x=0; x<lines; x++)
            {
                result.data[x] = new T [result.columns];
            }//fim for

            for (int x=0; x<result.lines; x++)
            {
                for (int y=0; y<result.columns; y++)
                {
                    result.data[x][y] = this->data[x][y] + other.data[x][y];
                }//fim for
            }//fim for
        }//fim else

        return (result);
    }//fim operator+

    void addLines (int l1, int l2, int k)
    {
        //verificar inputs
        if (l1 < 0 || l1 > lines || l2< 0 || l2 > lines)
        {
            std:: cout << "Erro: inputs fora dos limites" << std:: endl;
        }//fim if
        else
        {
            for (int y=0; y<columns; y++)
            {
                data[l1][y] = data[l1][y] + data[l2][y] * k;
            }//fim for
        }//fim else               
    }//fim addLines

    void subLines (int l1, int l2, int k)
    {
        //verificar inputs
        if (l1 < 0 || l1 > lines || l2< 0 || l2 > lines)
        {
            std:: cout << "Erro: inputs fora dos limites" << std:: endl;
        }//fim if
        else
        {
            for (int y=0; y<columns; y++)
            {
                data[l1][y] = data[l1][y] - data[l2][y] * k;
            }//fim for
        }//fim else               
    }//fim subLines

    int searchLines (T value)
    {
        int line = -1;

        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                if (data[x][y] == value)
                {
                    line = x;
                }//fim if
            }//fim for
        }//fim for

        return (line);
    }// fim searchLines

    int searchColumns (T value)
    {
        int column = -1;

        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                if (data[x][y] == value)
                {
                    column = y;
                }// fim if
            }//fim for
        }//fim for

        return (column);
    }// fim searchLines

    Matrix& transpose ()
    {
        static Matrix <T> transp (this->columns, this->lines);

        for (int x=0; x<transp.lines; x++)
        {
            for (int y=0; y<transp.columns; y++)
            {
                transp.data[x][y] = this->data[y][x];
            }//fim for
        }//fim for

        return (transp);
    }//fim transpose

    bool increase_horizontal ()
    {
        bool result = true;
        int controle = 1;

        for (int x=0; x<lines && result; x++)
        {
            for (int y=0; y<columns && result; y++)
            {
                if (data[x][y] != controle)
                {
                    result = false;
                }//fim if
                controle++;
            }//fim for
        }//fim for

        return (result);
    }//fim increase_horizontal

    bool increase_vertical ()
    {
        bool result = true;
        int controle = 1;

        for (int y=0; y<columns && result; y++)
        {
            for (int x=0; x<lines && result; x++)
            {
                if (data[x][y] != controle)
                {
                    result = false;
                }//fim if
                controle++;
            }//fim for
        }//fim for

        return (result);
    }//fim increase_vertical

};

#endif