// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo DispersionFunction.h

#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H

#include <iostream>

/* Clase abstracta Dispersion Function */
template<class Key>
class DispersionFunction {
  public:
    // Método virtual que será utilizado por las clases hijas.
    virtual unsigned operator()(const Key& k) const = 0;
};

/* Clase derivada Módulo */
template<class Key>
class fdModule: public DispersionFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    fdModule(const unsigned n) : tablesize_(n) {}

    // Método encargado de hacer la función del módulo.
    unsigned operator()(const Key& k) const {
      return k % tablesize_; 
    }
};

/* Clase derivada Suma */
template<class Key>
class fdSuma : public DispersionFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    fdSuma(const unsigned n) : tablesize_(n) {}      
    ~fdSuma();                           

    // Método encargado de hacer la función de la suma.
    unsigned operator()(const Key& k) const {
      int d = 0;
      int x = 0;
      int y = 0;
      x = k;
      while (x > 0) {
        y = x % 10;
        d = d + y;
        x = x / 10;
      }
      return (d % tablesize_);
    }
};

/* Clase derivada Pseudoaleatoria */
template<class Key>
class fdPseudoaleatoria : public DispersionFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    fdPseudoaleatoria(const unsigned n): tablesize_(n) {}

    // Método encargado de hacer la función pseudoaleatoria.
    unsigned operator()(const Key& k) const {
      srand(k);
      return rand() % tablesize_;
    }
};

#endif