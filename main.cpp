#include <Arbol.hpp>
#include <time.h>

int main() {
    int e;
    
	srand(time(0));
    vector<int> A;
    A.push_back(100);
    cout << endl << "Lista de elementos a insertar en el ABB: " << 100;
    for(int i =0; i < 15; i++) {
        int x = rand() % 200;
        A.push_back(x);
        cout << " " << x;
    }
    Arbol abb;
    for(int i : A) abb.insertar(i);
        
    cout << endl << "\nMi Abb: ";
    
    abb.dibujar();
    
    cout << "inorden\n";
    abb.inorden();
    
    cout << "Mayores y menores\n";
    cout << abb.buscarMenor(true) << endl;
    cout << abb.buscarMayor(true) << endl;
    cout << abb.buscarMenor(false) << endl;
    cout << abb.buscarMayor(false) << endl;
    
    cout << "Hay " << abb.contarImpares() << " impares" << endl;
    
    cout << "Mostrar de hojas\n";
    abb.mostrarHojas();
    
    
    cout << "\n\nQue elemento quiere eliminar?" << endl;
    cin >> e;
    cout << "\nArbol antes de eliminar el elemento " << e << endl;
    abb.dibujar();
    abb.borrarElemento(e);
    cout << "\nArbol despues de eliminar el elemento " << e << endl;
    abb.dibujar();
	return 0;
}
