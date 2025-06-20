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

void guardarEnArchivoBinario(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar." << endl;
        return;
    }

    archivo.write(reinterpret_cast<char*>(&cantidadProductos), sizeof(int));
    for (int i = 0; i < cantidadProductos; i++) {
        archivo.write(reinterpret_cast<char*>(&listaProductos[i].codigo), sizeof(int));

        size_t longitud = listaProductos[i].nombre.size();
        archivo.write(reinterpret_cast<char*>(&longitud), sizeof(size_t));
        archivo.write(listaProductos[i].nombre.c_str(), longitud);

        archivo.write(reinterpret_cast<char*>(&listaProductos[i].precio), sizeof(float));
        archivo.write(reinterpret_cast<char*>(&listaProductos[i].stock), sizeof(int));

        longitud = listaProductos[i].categoria.size();
        archivo.write(reinterpret_cast<char*>(&longitud), sizeof(size_t));
        archivo.write(listaProductos[i].categoria.c_str(), longitud);

        archivo.write(reinterpret_cast<char*>(&listaProductos[i].activo), sizeof(bool));
    }

    archivo.close();
    cout << "Datos guardados." << endl;
}
void cargarDesdeArchivoBinario(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cout << "No se encontró el archivo." << endl;
        return;
    }

    delete[] listaProductos;
    archivo.read(reinterpret_cast<char*>(&cantidadProductos), sizeof(int));
    listaProductos = new Producto[cantidadProductos];

    for (int i = 0; i < cantidadProductos; i++) {
        int codigo;
        float precio;
        int stock;
        bool activo;
        size_t longitud;

        archivo.read(reinterpret_cast<char*>(&codigo), sizeof(int));

        archivo.read(reinterpret_cast<char*>(&longitud), sizeof(size_t));
        string nombre(longitud, ' ');
        archivo.read(&nombre[0], longitud);

        archivo.read(reinterpret_cast<char*>(&precio), sizeof(float));
        archivo.read(reinterpret_cast<char*>(&stock), sizeof(int));

        archivo.read(reinterpret_cast<char*>(&longitud), sizeof(size_t));
        string categoria(longitud, ' ');
        archivo.read(&categoria[0], longitud);

        archivo.read(reinterpret_cast<char*>(&activo), sizeof(bool));

        listaProductos[i] = { codigo, nombre, precio, stock, categoria, activo };
    }

    archivo.close();
    cout << "Datos cargados." << endl;
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

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: mostrarProductos(); break;
            case 3: buscarProductoPorCodigo(); break;
            case 4: modificarProducto(); break;
            case 5: eliminarProducto(); break;
            case 6: guardarEnArchivoBinario(nombreArchivo); break;
            case 7:
			guardarEnArchivoBinario(nombreArchivo);
                delete[] listaProductos;
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 7);

    return 0;
}


