SI EL GITHUB FUNCIONA DEBE MOSTRAR ESTOXD

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
    string categoria;
    bool activo;
};

Producto* listaProductos = nullptr;
int cantidadProductos = 0;


int main() {
    string nombreArchivo = "Inventario.bin";
    cargarDesdeArchivoBinario(nombreArchivo);

    int opcion;
    do {
        cout << "\n--- Menú ---" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto por código" << endl;
        cout << "4. Modificar producto" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Guardar datos en archivo" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;


    return 0;
}
