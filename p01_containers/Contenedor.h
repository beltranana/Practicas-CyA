// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 17/09/2026
// Archivo: p01_containers/Contenedor.h
// Declaración de la clase Contenedor, un contenedor dinámico de enteros
// con operaciones básicas de gestión y acceso a sus elementos.

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
