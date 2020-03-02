#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Personaje
{
public:
    Personaje();
    void setNombre(string n);
    string getNombre();

    string getTipo() const;
    void setTipo(const string &value);

    int getFuerza() const;
    void setFuerza(int value);

    int getSalud() const;
    void setSalud(int value);

    friend ostream& operator<<(ostream &out,const Personaje &p)
    {
        out << setw(10) << p.nombre;
        out << setw(10) << p.tipo;
        out << setw(7) << p.fuerza ;
        out << setw(7) << p.salud;

        return out;
    }
    friend istream& operator>>(istream &in, Personaje &p)
    {
        string s;
        int valor;

        cout << "Nombre: ";
        getline(cin, s);
        p.setNombre(s);

        cout << "Tipo: ";
        getline(cin, s);
        p.setTipo(s);

        cout << "Fuerza: ";
        cin >> valor;
        p.setFuerza(valor);

        cout << "Salud: ";
        cin >> valor; cin.ignore();
        p.setSalud(valor);
        return in;
    }

    bool operator<(const Personaje &p) const
    {
        return nombre < p.nombre;
    }
    bool operator==(const Personaje &p) const
    {
        return nombre == p.nombre;
    }

private:
    string nombre;
    string tipo;
    int fuerza;
    int salud;
};

#endif // PERSONAJE_H
