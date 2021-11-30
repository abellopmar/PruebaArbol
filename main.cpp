#include <Arbol.hpp>
#include <time.h>

int main() {
	srand(time(0));
    vector<int> A;
    A.push_back(50);
    cout << endl << "Lista de elementos a insertar en el ABB: " << 50;
    for(int i =0; i < 19; i++) {
        int x = rand() % 100;
        A.push_back(x);
        cout << " " << x;
    }
    Arbol abb;
    for(int i : A) abb.insertar(i);
        
    cout << endl << "\nMi Abb: ";
    
    abb.dibujar();
    
    cout << "inorden\n";
    abb.inorden();
    
    cout << "mayores y menores\n";
    cout << abb.buscarMenor(true) << endl;
    cout << abb.buscarMayor(true) << endl;
    cout << abb.buscarMenor(false) << endl;
    cout << abb.buscarMayor(false) << endl;
    
    cout << "Hay " << abb.contarImpares() << " impares" << endl;
    
    cout << "Mostrar de hojas\n";
    abb.mostrarHojas();
	return 0;
}
