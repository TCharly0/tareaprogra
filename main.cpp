#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>  // Incluye la cabecera <string> para usar std::string


using namespace std;

void crear() {
    string nombre, frase;  // Usa std::string para la variable local "nombre"

    cout << "Escriba un nombre para el archivo: ";
    cin >> nombre;

    ofstream archivo("C:/tareamanejodearchivos/" + nombre + ".txt", ios::out);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
    } else {
        cout << "\nDigite el texto del archivo: ";
        cin.ignore();  // Limpia el carácter de nueva línea del búfer de entrada
        getline(cin, frase);
        archivo << frase;
        archivo.close();
    }
}

void modificar() {
    string nombre;
    cout << "Ingrese el nombre del archivo a modificar: ";
    cin >> nombre;

    // Construye la ruta completa del archivo
    string ruta = "C:/tareamanejodearchivos/" + nombre + ".txt";

    // Abre el archivo en modo lectura
    ifstream archivo_lectura(ruta);
    if (!archivo_lectura.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    } else {
        // Lee el contenido actual del archivo
        string contenido;
        getline(archivo_lectura, contenido);
        archivo_lectura.close();

        // Muestra el contenido actual del archivo
        cout << "Contenido actual del archivo:\n" << contenido << endl;

        // Solicita el nuevo contenido al usuario
        cout << "Ingrese el texto adicional para agregar al archivo: ";
        cin.ignore();  // Limpia el carácter de nueva línea del búfer de entrada
        string texto_adicional;
        getline(cin, texto_adicional);

        // Abre el archivo en modo escritura (modo append)
        ofstream archivo_escritura(ruta, ios::app);
        if (!archivo_escritura.is_open()) {
            cout << "No se pudo abrir el archivo para escritura." << endl;
            return;
        } else {
            // Escribe el nuevo contenido en el archivo
            archivo_escritura << texto_adicional << endl;  // Agrega una nueva línea al final
            archivo_escritura.close();

            cout << "Texto agregado exitosamente al archivo." << endl;
        }
    }
}


void mover() {
    string destino;
    string nombre;
    cout << "Ingrese el nombre del archivo a mover: ";
    cin >> nombre;

    // Construye las rutas completas tanto para el antiguo como para el nuevo nombre de archivo
    string ruta_antiguo = "C:/tareamanejodearchivos/" + nombre + ".txt";
    string ruta_nuevo = "C:/ruta 1/" + nombre + ".txt";

    // Intenta mover el archivo
    if (rename(ruta_antiguo.c_str(), ruta_nuevo.c_str()) == 0) {
        cout << "Archivo movido exitosamente a ruta 1 " << destino << ".txt" << endl;
    } else {
        cout << "Error al intentar mover el archivo. Verifique el nombre y la ruta." << endl;
    }
}

void eliminar() {
    string nombre;
    cout << "Ingrese el nombre del archivo a eliminar: ";
    cin >> nombre;
    string ruta = "C:/tareamanejodearchivos/" + nombre + ".txt";

    if (remove(ruta.c_str()) != 0) {
        cout << "Error al intentar eliminar el archivo." << endl;
    } else {
        cout << "Archivo eliminado exitosamente." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "Que desea hacer?" << endl;
        cout << "Crear archivo[1] Eliminar archivo[2] Modificar[3] Mover archivo[4] Salir[5] " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                crear();
                break;
            case 2:
                eliminar();
                break;
            case 3:
                modificar();
                break;
            case 4:
                mover();
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "opcion no valida" << endl;
        }

        system("pause");
    } while (opcion != 5);
    return 0;
}

