// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include "../include/DispersionFunction.h"
#include "../include/ExplorationFunction.h"
#include "../include/Sequence.h"

/* Clase abstracta HashTable */
template<class Key>
class HashTable {
  private:
    // Doble puntero de la clase Sequence.
    Sequence<Key>** table;
    // Puntero de la clase ExplorationFunction inicializado a nullptr.
    ExplorationFunction<Key>* fe = nullptr;
    // Puntero de la clase DispersionFunction.
    DispersionFunction<Key>* fd;
    // Atributo que define el tamaño de la tabla.
    int tablesize_;
    // Atributo que define el tamaño del bloque inicializado a 0.
    int blocksize_ = 0;

  public:
    /* Constructor Tabla Hash */
    HashTable(ExplorationFunction<Key> *fexp, DispersionFunction<Key> *fdis, int size, int block) : fe(fexp), fd(fdis), tablesize_(size), blocksize_(block) {
      table = new Sequence<Key> *[tablesize_];
      if (fe == nullptr) {
        for (int i = 0; i < tablesize_; i++) {
          table[i] = new SeqList<Key>();
        }
      }
      else {
        for (int i = 0; i < tablesize_; i++) {
          table[i] = new SeqBlock<Key>(blocksize_);
        }
      } 
    }

    /* Destructor Tabla Hash */
    ~HashTable() {
      for (int i = 0; i < tablesize_; i++) {
        delete table[i];
      }
      delete table;
    }

    /* Método SEARCH, encargado de la búsqueda de una clave */
    bool search(const Key& k) const {
      bool flag = false;
      int pos1 = (*fd)(k);
      if (fe != nullptr) {
        for (int i =0; i < tablesize_; ++i) {
          int pos2 = (*fe)(k,i);
          if (table[(pos1 + pos2) % tablesize_]->search(k)) {
            return true;
          }
          if (!table[pos1]->isFull()) {
            return false;
          }
        }
      }
      if (table[pos1]->search(k)) { 
        return true;
      } else {
        flag = false;
        return flag;
      }
    }

    /* Método INSERT, encargado de la inserción de una clave */
    bool insert(const Key& k) {
      int pos1 = (*fd)(k);
      if (fe != nullptr) {
        for (int i = 0; i < tablesize_; ++i) {
          int pos2 = (*fe)(k,i);
          if (!table[(pos1 + pos2) % tablesize_]->search(k) && !table[(pos1 + pos2) % tablesize_]->isFull()) {
            table[(pos1 + pos2) % tablesize_]->insert(k);
            return true;
          }
          if (table[(pos1 + pos2) % tablesize_]->search(k)) {
            return false;
          }
        }
        return false;
      }
      if (!table[pos1]->search(k)) {
        table[pos1]->insert(k);
        return true;
      } else {
        return false;
      }
    }
};

#endif