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
    int buscarMenor(bool left);
    int buscarMayor(bool left);
    int contarImpares();
    void mostrarHojas();
    void borrarElemento(int e);
    ~Arbol();
    
private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb nodo, int val);
    void inorden(pnodoAbb nodo);
    int altura(pnodoAbb nodo);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    int buscarMenor(pnodoAbb nodo);
    int buscarMayor(pnodoAbb nodo);
    int contarImpares(pnodoAbb nodo);
    void mostrarHojas(pnodoAbb nodo);
    pnodoAbb borrarElemento(pnodoAbb nodo, int e);
    pnodoAbb borrarNodo(pnodoAbb nodo);
    int maximo(pnodoAbb nodo);
};

#endif // ARBOL_HPP
