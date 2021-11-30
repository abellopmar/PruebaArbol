#include "Arbol.hpp"

Arbol::Arbol() {
    raiz = NULL;
}

void Arbol::insertar(int val) {
    //cout << "\n\n" << this->altura(this->raiz) << "\n\n";
    pnodoAbb nuevo = new NodoArbol(val);
    if (!this->raiz) this->raiz = nuevo;
    else {
        if (val <= this->raiz->dato){
            if (!this->raiz->izq) this->raiz->izq = nuevo;
            else this->raiz->izq = this->insertar(this->raiz->izq, val);
        } else {
            if (!this->raiz->der) this->raiz->der = nuevo;
            else this->raiz->der = this->insertar(this->raiz->der, val);
        }
    }
}

void Arbol::inorden() {
    
}

void Arbol::dibujar() {
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');
    for (int i = 1; i < h; i++) {
        for (int j = 0; j < linkAbove[i].size(); j++) {
            int size = output[i - 1].size();
            if(size < j + 1)
                output[i - 1] += string(j + 1 - size, ' ');
            int jj = j;
            if(linkAbove[i][j] =='L') {
                while(output[i - 1][jj] == ' ')
                    jj++;
                for(int k = j + 1;  k < jj - 1; k++) {
                    output[i - 1][k] = '_';
                }
            }
            else if(linkAbove[i][j] == 'R') {
                while(output[i - 1][jj] == ' ')
                    jj--;
                for(int k = j - 1; k > jj + 1; k--)
                    output[i - 1][k] = '_';
            }
            linkAbove[i][j] = '|';
        }
    }
    cout << '\n' << '\n';
    for(int i =0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

//FUNCIONES PRIVADAS

pnodoAbb Arbol::insertar(pnodoAbb nodo, int val) {
    pnodoAbb nuevo = new NodoArbol(val);
    if (val <= nodo->dato){
        if (!nodo->izq) nodo->izq = nuevo;
        else nodo->izq = this->insertar(nodo->izq, val);
    } else {
        if (!nodo->der) nodo->der = nuevo;
        else nodo->der = this->insertar(nodo->der, val);
    }
    return nodo;
}

void Arbol::inorden(pnodoAbb nodo) {
    
}

int Arbol::altura(pnodoAbb nodo) {
    if (!nodo) return -1;
    if (!nodo->izq) {
        if (!nodo->der) return 0;
        else return 1 + altura(nodo->der);
    } else {
        if (!nodo->der) return 1 + altura(nodo->der);
        else return 1 + max(altura(nodo->izq), altura(nodo->der));
    }
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar) {
    if (!nodo)
        return;
    int h = output.size();
    string SP = " ";
    if (p < 0) {
        string extra (-p, ' ');
        for (string& s : output)
            if (!s.empty())
                s = extra + s;
        for (string& s : linkAbove)
            if (!s.empty())
                s = extra + s;
    }
    if (nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if (nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());
    if (nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->dato;    // En vez de este valor, tenéis que coger el nº de habitación
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel  + 1].size());
    }
    int space = p - output[nivel].size();
    if (space > 0) output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
            nodo->dato;    // En vez de este valor, tenéis que coger el nº de habitación
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;
    space = p + SP.size() - linkAbove[nivel].size();
    if (space > 0) linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;
    if (nodo->der) dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

Arbol::~Arbol() {
}