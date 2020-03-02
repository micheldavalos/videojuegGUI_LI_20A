#include "personaje.h"

Personaje::Personaje()
{

}

void Personaje::setNombre(string n)
{
    nombre = n;
}

string Personaje::getNombre()
{
    return nombre;
}

string Personaje::getTipo() const
{
    return tipo;
}

void Personaje::setTipo(const string &value)
{
    tipo = value;
}

int Personaje::getFuerza() const
{
    return fuerza;
}

void Personaje::setFuerza(int value)
{
    fuerza = value;
}

int Personaje::getSalud() const
{
    return salud;
}

void Personaje::setSalud(int value)
{
    salud = value;
}
