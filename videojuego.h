#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "personaje.h"
#include <vector>

class Videojuego
{
    vector<Personaje> arreglo;

public:
    Videojuego();
    void agregar(const Personaje &p);
    void mostrar();
    void respaldar(const string &ubicacion);
    void recuperar(const string &ubicacion);
    size_t size()
    {
        return arreglo.size();
    }

    void insertar(const Personaje &per, size_t p);
    void inicializar(const Personaje &p, size_t n);
    void eliminar(size_t p);
    void ordenar();
    void ordenar_tipo();
    void ordenar_salud();
    void ordenar_fuerza();
    Personaje *buscar(const Personaje &p);

    Personaje& operator[](size_t p)
    {
        return arreglo[p];
    }

};

#endif // VIDEOJUEGO_H
