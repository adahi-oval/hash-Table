// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo Clave.h

#ifndef CLAVE_H
#define CLAVE_H

#include <iostream>

#include "../include/DispersionFunction.h"
#include "../include/ExplorationFunction.h"
#include "../include/Sequence.h"

/* Clase abstracta Clave */
template<class Key>
class Clave {
  private:
    long clavefinal_;
    struct {
      long clave1_;
      long clave2_; 
    } clave;
       
  public:
    Clave(long clave1_, long clave2_) {
      std::cout << "Introduzca la primera clave, por favor." << std::endl;
      std::cin >> clave1_;
      
      std::cout << "Introduzca la segunda clave, por favor." << std::endl;
      std::cin >> clave2_;

      clavefinal_ = clave1_ + clave2_;
    }
};

#endif