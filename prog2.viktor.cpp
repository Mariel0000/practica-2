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

void agregarProducto() {
    Producto* nuevoArreglo = new Producto[cantidadProductos + 1];

    for (int i = 0; i < cantidadProductos; i++) {
        nuevoArreglo[i] = listaProductos[i];
    }

    cout << "Ingrese el código: ";
    cin >> nuevoArreglo[cantidadProductos].codigo;
    cin.ignore();
    cout << "Ingrese el nombre: ";
    getline(cin, nuevoArreglo[cantidadProductos].nombre);
    cout << "Ingrese el precio: ";
    cin >> nuevoArreglo[cantidadProductos].precio;
    cout << "Ingrese el stock: ";
    cin >> nuevoArreglo[cantidadProductos].stock;
    cin.ignore();
    cout << "Ingrese la categoría: ";
    getline(cin, nuevoArreglo[cantidadProductos].categoria);
    nuevoArreglo[cantidadProductos].activo = true;

    delete[] listaProductos;
    listaProductos = nuevoArreglo;
    cantidadProductos++;

    cout << "Producto agregado." << endl;
}

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
