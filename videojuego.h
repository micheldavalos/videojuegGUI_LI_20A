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
    void respaldar();
    void recuperar();
    size_t size()
    {
        return arreglo.size();
    }

    void insertar(const Personaje &per, size_t p);
    void inicializar(const Personaje &p, size_t n);
    void eliminar(size_t p);
    void ordenar();
    Personaje *buscar(const Personaje &p);

};

#endif // VIDEOJUEGO_H
