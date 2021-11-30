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
    pnodoAbb insertar(pnodoAbb, int);
    void inorden(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    int buscarMenor(pnodoAbb);
    int buscarMayor(pnodoAbb);
    int contarImpares(pnodoAbb);
    void mostrarHojas(pnodoAbb);
    void borrarElemento(pnodoAbb, int);
    void borrarNodo(pnodoAbb, int);
};

#endif // ARBOL_HPP
