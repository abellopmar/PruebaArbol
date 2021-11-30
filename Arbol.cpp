#include "Arbol.hpp"

Arbol::Arbol() {
    raiz = NULL;//A 200 en pacientes
}

void Arbol::insertar(int val) {
    this->raiz = insertar(this->raiz, val);
}

void Arbol::inorden() {
    inorden(this->raiz);
    cout << endl;
}

void Arbol::dibujar() {
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1) output[i - 1] += string(j + 1 - size, ' ');
                
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ') jj++;
                    
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                        
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ') jj--;
                    
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }
    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i) cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

int Arbol::buscarMenor(bool left) {
    if (left) return buscarMenor(this->raiz->izq);
    return buscarMenor(this->raiz->der);
}

int Arbol::buscarMayor(bool left) {
    if (left) return buscarMayor(this->raiz->izq);
    return buscarMayor(this->raiz->der);
}

int Arbol::contarImpares() {
    return contarImpares(this->raiz);
}

void Arbol::mostrarHojas() {
    mostrarHojas(this->raiz);
    cout << endl;
}

void Arbol::borrarElemento(int e) {
    //borrarElemento(this->raiz, e);
}

// FUNCIONES PRIVADAS

pnodoAbb Arbol::insertar(pnodoAbb nodo, int val) {
    pnodoAbb nuevo = new NodoArbol(val);
    if(!nodo)
        return nuevo;
    if(val <= nodo->dato) {
        nodo->izq = insertar(nodo->izq, val);
    } else {
        nodo->der = insertar(nodo->der, val);
    }
    return nodo;
}

void Arbol::inorden(pnodoAbb nodo) {
    if (nodo) {
        inorden(nodo->izq);
        cout << nodo->dato << "  ";
        inorden(nodo->der);
    }
}

int Arbol::altura(pnodoAbb nodo) {
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar) {
    if(!nodo)

        return;

    int h = output.size();

    string SP = " ";

    if(p < 0) {

        string extra(-p, ' ');

        for(string& s : output)

            if(!s.empty())

                s = extra + s;

        for(string& s : linkAbove)

            if(!s.empty())

                s = extra + s;
    }

    if(nivel < h - 1)

        p = max(p, (int)output[nivel + 1].size());

    if(nivel > 0)

        p = max(p, (int)output[nivel - 1].size());

    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        string izqdato = SP + to_string(nodo->izq->dato) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0) output[nivel] += string(space, ' ');
    
    string nododato = SP + to_string(nodo->dato) + SP;
    output[nivel] += nododato;
    space = p + SP.size() - linkAbove[nivel].size();

    if(space > 0) linkAbove[nivel] += string(space, ' ');

    linkAbove[nivel] += linkChar;

    if(nodo->der) dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

int Arbol::buscarMenor(pnodoAbb nodo) {
    if (nodo->izq) return buscarMenor(nodo->izq);
    return nodo->dato;
}

int Arbol::buscarMayor(pnodoAbb nodo) {
    if (nodo->der) return buscarMayor(nodo->der);
    return nodo->dato;
}

int Arbol::contarImpares(pnodoAbb nodo) {
    if (!nodo) return 0;
    if (nodo->dato % 2 == 1) return 1 + contarImpares(nodo->izq) + contarImpares(nodo->der);
    return contarImpares(nodo->izq) + contarImpares(nodo->der);
}

void Arbol::mostrarHojas(pnodoAbb nodo) {
    if (nodo) {
        mostrarHojas(nodo->izq);
        if (!nodo->izq and !nodo->der) cout << nodo->dato << "  ";
        mostrarHojas(nodo->der);
    }
}

Arbol::~Arbol() {
}