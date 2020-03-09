#include "videojuego.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

Videojuego::Videojuego()
{

}

void Videojuego::agregar(const Personaje &p)
{
    arreglo.push_back(p);
}

void Videojuego::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre" <<
            setw(10) << "Tipo" <<
            setw(7) << "Fuerza" <<
            setw(7) << "Salud" << endl;
    for (size_t i = 0; i < arreglo.size(); i++) {
        Personaje &p = arreglo[i];
        cout << p << endl;
    }
}

void Videojuego::respaldar(const string &ubicacion)
{
    fstream archivo(ubicacion, ios::out);

    if (archivo.is_open()) {
        for (size_t i = 0; i < arreglo.size(); i++) {
            Personaje &p = arreglo[i];

            archivo << p.getNombre() << endl;
            archivo << p.getTipo() << endl;
            archivo << p.getFuerza() << endl;
            archivo << p.getSalud() << endl;
        }
    }
}

void Videojuego::recuperar(const string &ubicacion)
{
    fstream archivo(ubicacion, ios::in);
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            string linea;
            Personaje p;

            getline(archivo, linea);
            if (archivo.eof()) {
                break;
            }
            p.setNombre(linea);

            getline(archivo, linea);
            p.setTipo(linea);

            getline(archivo, linea);
            int fuerza = stoi(linea);
            p.setFuerza(fuerza);

            getline(archivo, linea);
            int salud = stoi(linea);
            p.setSalud(salud);

            agregar(p);
        }
    }
}

void Videojuego::insertar(const Personaje &per, size_t p)
{
    arreglo.insert(arreglo.begin()+p, per);
}

void Videojuego::inicializar(const Personaje &p, size_t n)
{
    arreglo = vector<Personaje>(n, p);
}

void Videojuego::eliminar(size_t p)
{
    arreglo.erase(arreglo.begin()+p);
}

void Videojuego::ordenar()
{
    sort(arreglo.begin(), arreglo.end());
}

Personaje* Videojuego::buscar(const Personaje &p)
{
    auto it = find(arreglo.begin(), arreglo.end(), p);

    if (it == arreglo.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }


}



