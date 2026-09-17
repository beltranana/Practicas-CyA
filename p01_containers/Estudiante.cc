// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 17/09/2026
// Archivo: p01_containers/Estudiante.cc
// Descripción: Implementación de un estudiante y su calificación.
// Historial de revisiones:
// 17/09/2026 - Creación e implementación del ejercicio 1.

#include "Estudiante.h"

#include <utility>

Estudiante::Estudiante(std::string identificador, double nota)
    : identificador_(std::move(identificador)), nota_(nota) {
}

const std::string& Estudiante::identificador() const {
  return identificador_;
}

double Estudiante::nota() const {
  return nota_;
}
