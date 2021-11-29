#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"
#include <vector>
using namespace std;

class Arbol {
public:
    Arbol();
    void insertar(int val);
    void inorden();
    void dibujar();
    int altura(pnodoAbb);//////////////////
    ~Arbol();
    
private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, int);
    void inorden(pnodoAbb);
    //int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
};

#endif // ARBOL_HPP
