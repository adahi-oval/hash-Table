// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo Sequence.h

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>

template<class Key>
class Sequence {
  private:
    // Puntero tipo Key.
    Key *key;                                                                  

  public:
    // Método SEARCH, utilizado en ambas clases derivadas.
    virtual bool search(const Key& k) const = 0;
    // Método INSERT, utilizado en ambas clases derivadas.
    virtual bool insert(const Key& k) = 0;
    // Método ISFULL, utilizado en ambas clases derivadas.
    virtual bool isFull() const = 0;
};

/* Clase genérica SeqList que deriva de Sequence */
template<class Key>
class SeqList : public Sequence<Key> {
  private:
    // Atributo full.
    int full;
    // Vector de Key.
    std::vector<Key> vector;

  public:
    /* Método SEARCH, encargado de buscar la clave */
    bool search(const Key& k) const {
      for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] == k) {
          return true;
        }
      }
      return false;
    }

    /* Método ISFULL, encargado de comprobar si la tabla está llena */
    bool isFull() const {
      return false;
    }

    /* Método INSERT, encargado de insertar la clave */
    bool insert(const Key& k) {
      if (!search(k)) {
        vector.push_back(k);
        return true;
      }
      return false;
    }
};

/* Clase genérica SeqBlock que deriva de Sequence */
template<class Key>
class SeqBlock : public Sequence<Key> {
  private:
    // Atributo del tamaño del bloque.
    int blocksize_;
    // Vector de Key.
    std::vector<Key> vector;

  public:
    // Constructor.
    SeqBlock(int b) : blocksize_(b) {
      vector.reserve(b);
    }

    /* Método SEARCH, encargado de buscar la clave */
    bool search(const Key& k) const {
      for (int i = 0; i < blocksize_; i++) {
        if (vector[i] == k) {
          return true;
        }
      }
      return false;
    }

    /* Método ISFULL, encargado de comprobar si la tabla está llena */
    bool isFull() const {
      if (vector.size() >= blocksize_) {
        return true;
      }
      return false;
    }
    
    /* Método INSERT, encargado de insertar la clave */
    bool insert(const Key& k) {
      if (!isFull() && !search(k)) {
        vector.push_back(k);
        return true;
      }
      return false;
    }
};

#endif