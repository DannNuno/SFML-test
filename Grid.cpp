#include "Grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->next = vector<vector<int>>(rows,vector<int>(cols,0));
}
Grid::Grid(int n, int w, int h)
{
    this->rows = n;
    this->cols = n;
    this->w = w;
    this->h = h;
    for (int i = 0; i < this->rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < this->cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->next = vector<vector<int>>(rows,vector<int>(cols,0));
}

void Grid::drawTo(RenderWindow &window)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(sizeX, sizeY));
            rect.setPosition(Vector2f(j * sizeX, i * sizeY));
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::Black);
            if (tablero[j][i] == 1)
            {
                rect.setFillColor(Color::Green);
            }
            window.draw(rect);
        }
    }
}

void Grid::toggle(int x, int y)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    int indexX = x / sizeX;
    int indexY = y / sizeY;

    // if (tablero[indexX][indexY] == 0)
    // {
    //     tablero[indexX][indexY] = 1;
    // }
    // else
    // {
    //     tablero[indexX][indexY] = 0;
    // }

    // tablero[indexX][indexY] = tablero[indexX][indexY] == 0 ? 1 : 0;

    tablero[indexX][indexY] = (tablero[indexX][indexY] + 1) % 2;
}

void Grid::update(){
    for(int i=0; i<this->rows; i++){
        for(int j=0; j<this->cols; j++){
            int vecinos = this->contarVecinos(i,j);

            if(this->tablero[i][j]==0){
                if(vecinos == 3){
                    this->next[i][j]==1;
                }
                //si tiene exactamente 3 vecinos nace
            }

            if(this->tablero[i][j]==1){
                if(vecinos>3 || vecinos<=1){
                    this->next[i][j]==0;
                }
                //muere si tiene mas de 3 vecinos o 1 o menos
                if(vecinos==2 || vecinos==3){
                    this->next[i][j]==1;
                }
                //se mantiene vivo con 2 o 3 vecinos
            }
        }
    }
    this->tablero = this->next;
}

int Grid::contarVecinos(int i, int j){
    int vecinos=0;
    if(i==0){
        if(j==0){

        if(this->tablero[i+1][j]==1){
        vecinos++;
        }
        if(this->tablero[i][j+1]==1){
        vecinos++;
        }
        if(this->tablero[i+1][j+1]==1){
        vecinos++;
        }
            
        } else {
            if(j==(cols-1)){

                 if(this->tablero[i+1][j]==1){
                vecinos++;
                }
                if(this->tablero[i][j-1]==1){
                    vecinos++;
                }
                if(this->tablero[i+1][j-1]==1){
                    vecinos++;
                }

            } else {
                if(this->tablero[i+1][j]==1){
                    vecinos++;
                }
                if(this->tablero[i][j-1]==1){
                    vecinos++;
                }
                if(this->tablero[i][j+1]==1){
                    vecinos++;
                }
                if(this->tablero[i+1][j+1]==1){
                    vecinos++;
                }
                if(this->tablero[i+1][j-1]==1){
                    vecinos++;
                }
            }
        }
    }

    if(i==(rows-1)){
        if(j==0){
            if(this->tablero[i-1][j]==1){
            vecinos++;
            }
            if(this->tablero[i-1][j+1]==1){
            vecinos++;
            }
            if(this->tablero[i][j+1]==1){
            vecinos++;
            }
            
        } else {
            if(j==(cols-1)){
                if(this->tablero[i-1][j]==1){
                vecinos++;
                }
                if(this->tablero[i-1][j-1]==1){
                    vecinos++;
                }
                if(this->tablero[i][j-1]==1){
                    vecinos++;
                }

            } else {
                if(this->tablero[i-1][j]==1){
                vecinos++;
                }
                if(this->tablero[i-1][j-1]==1){
                    vecinos++;
                }
                if(this->tablero[i-1][j+1]==1){
                    vecinos++;
                }
                if(this->tablero[i][j-1]==1){
                    vecinos++;
                }
                if(this->tablero[i][j+1]==1){
                    vecinos++;
                }
            }
        }
    }

    if(j==0){
       if(i!=0 && i!=(rows-1)){
            if(this->tablero[i-1][j]==1){
            vecinos++;
            }
            if(this->tablero[i-1][j+1]==1){
                vecinos++;
            }
            if(this->tablero[i+1][j]==1){
                vecinos++;
            }
            if(this->tablero[i][j+1]==1){
                vecinos++;
            }
            if(this->tablero[i+1][j+1]==1){
                vecinos++;
            }

       }
    }

    if(j==(cols-1)){
        if(i!=0 && i!=(rows-1)){
            if(this->tablero[i-1][j]==1){
            vecinos++;
            }
            if(this->tablero[i-1][j-1]==1){
                vecinos++;
            }
            if(this->tablero[i+1][j]==1){
                vecinos++;
            }
            if(this->tablero[i][j-1]==1){
                vecinos++;
            }
            if(this->tablero[i+1][j-1]==1){
                vecinos++;
            }
        }
       
    }


    if(i!=0 && j!=0 && j!=(cols-1) && i!=(rows-1)){
        if(this->tablero[i-1][j]==1){
        vecinos++;
        }

        if(this->tablero[i-1][j-1]==1){
            vecinos++;
        }

        if(this->tablero[i-1][j+1]==1){
            vecinos++;
        }

        if(this->tablero[i+1][j]==1){
            vecinos++;
        }
        if(this->tablero[i][j-1]==1){
            vecinos++;
        }
        if(this->tablero[i][j+1]==1){
            vecinos++;
        }
        if(this->tablero[i+1][j+1]==1){
            vecinos++;
        }
        if(this->tablero[i+1][j-1]==1){
            vecinos++;
        }
    }


    return vecinos;
}

/*

El juego debe empezar "Pausado".
Cuando se de click a una celda, ésta debe cambiar de estado.
Cuando se presiona la barra espaciadora o se da click derecho (tu elección) se empieza a ejecutar el juego.

Subir el repositorio de GitHub y la branch en la que se trabajó.*/