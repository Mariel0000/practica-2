
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

void eliminarProducto() {
    int codigoEliminar;
    cout << "Ingrese el código del producto a eliminar: ";
    cin >> codigoEliminar;

    int posicion = -1;
    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].codigo == codigoEliminar) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    Producto* nuevoArreglo = new Producto[cantidadProductos - 1];

    int indiceNuevo = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (i != posicion) {
            nuevoArreglo[indiceNuevo++] = listaProductos[i];
        }
    }

    delete[] listaProductos;
    listaProductos = nuevoArreglo;
    cantidadProductos--;

    cout << "Producto eliminado." << endl;
}

void buscarProductoPorCodigo() {
    int codigoBuscado;
    cout << "Ingrese el código a buscar: ";
    cin >> codigoBuscado;

    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].codigo == codigoBuscado) {
            cout << "Nombre: " << listaProductos[i].nombre
                 << " | Precio: " << listaProductos[i].precio
                 << " | Stock: " << listaProductos[i].stock
                 << " | Categoría: " << listaProductos[i].categoria << endl;
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void modificarProducto() {
    int codigoModificar;
    cout << "Ingrese el código del producto a modificar: ";
    cin >> codigoModificar;

    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].codigo == codigoModificar) {
            cout << "Nuevo precio: ";
            cin >> listaProductos[i].precio;
            cout << "Nuevo stock: ";
            cin >> listaProductos[i].stock;
            cin.ignore();
            cout << "Nueva categoría: ";
            getline(cin, listaProductos[i].categoria);
            cout << "Producto modificado." << endl;
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void mostrarProductos() {
    if (cantidadProductos == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    for (int i = 0; i < cantidadProductos; i++) {
        cout << "Código: " << listaProductos[i].codigo
             << " | Nombre: " << listaProductos[i].nombre
             << " | Precio: " << listaProductos[i].precio
             << " | Stock: " << listaProductos[i].stock
             << " | Categoría: " << listaProductos[i].categoria << endl;
    }
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
