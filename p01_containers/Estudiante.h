// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 17/09/2026
// Archivo: p01_containers/Estudiante.h
// Descripción: Declaración de un estudiante y su calificación.
// Historial de revisiones:
// 17/09/2026 - Creación e implementación del ejercicio 1.

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <string>

class Estudiante {
 public:
  Estudiante(std::string identificador, double nota);

  const std::string& identificador() const;
  double nota() const;

 private:
  std::string identificador_;
  double nota_;
};

#endif  // ESTUDIANTE_H_
