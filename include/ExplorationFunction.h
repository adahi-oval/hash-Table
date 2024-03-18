// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo ExplorationFunction.h

#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H

#include <iostream>

/* Clase abstracta Exploration Function */
template<class Key>
class ExplorationFunction {
  public:
    // Método virtual que será utilizado por las clases hijas.
    virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

/* Clase derivada Lineal */
template<class Key>
class feLineal: public ExplorationFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    feLineal() {};
    // Destructor.                                                           
    ~feLineal();

    // Método encargado de realizar la función Lineal.
    unsigned operator()(const Key& k, unsigned i) const {                      
      return i;
    }
};

/* Clase derivada Cuadrática */
template<class Key>
class feCuadratic : public ExplorationFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    feCuadratic() {};                                                          
    // Destructor.
    ~feCuadratic();                                                            

    // Método encargado de realizar la función Cuadrática.
    unsigned operator()(const Key& k, unsigned i) const {
      return i * i;
    }
};

/* Clase derivada Doble Dispersión */
template<class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
  private:
    // Puntero tipo Dispersion Function.
    DispersionFunction<Key>& fd;
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    feDoubleDispersion(DispersionFunction<Key>& funcion) : fd(funcion) {}
    // Destructor.
    ~feDoubleDispersion();

    // Método encargado de realizar la función Doble Dispersión.
    unsigned operator()(const Key& k, unsigned i) const {
      return (i * fd(k)); 
    }
};


/* Clase derivada Redispersión */
template<class Key>
class feReDispersion : public ExplorationFunction<Key> {
  private:
    // Atributo que define el tamaño de la tabla.
    unsigned tablesize_;

  public:
    // Constructor.
    feReDispersion() {};
    // Destructor.
    ~feReDispersion();

    // Método encargado de realizar la función Doble Dispersión.
    unsigned operator()(const Key& k, unsigned i) const {
      srand(k);
      int random = 0;
      for (unsigned j = 0; j < i; ++j) {
        random = rand();
      }
      return random; 
    }
};

#endif