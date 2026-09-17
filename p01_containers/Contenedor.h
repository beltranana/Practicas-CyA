/*
 * Proyecto: Practica 1 - Contenedores en C++
 * Fichero: Contenedor.h
 * Descripcion: Declaracion de un contenedor dinamico de enteros.
 * Autor: Copilot
 * Fecha: 2026-09-17
 */

#ifndef CONTENEDOR_H_
#define CONTENEDOR_H_

class Contenedor {
 public:
  Contenedor();
  explicit Contenedor(int capacidad_inicial);
  ~Contenedor();

  void insertarFinal(int valor);
  bool eliminarFinal();
  int obtener(int indice) const;
  void establecer(int indice, int valor);
  int tamano() const;
  int capacidad() const;
  bool vacio() const;
  void limpiar();
  void mostrar() const;

 private:
  int* datos_;
  int tamano_;
  int capacidad_;

  void reservarMasEspacio();
};

#endif  // CONTENEDOR_H_
