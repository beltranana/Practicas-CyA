// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 17/09/2026
// Archivo: p01_containers/main.cc
// Programa cliente que contiene la función main y utiliza la clase
// Contenedor para demostrar la inserción, consulta, modificación,
// visualización y eliminación de elementos.
// Referencias:
// Enlaces de interés:
// Historial de revisiones:
// 17/09/2026 - Creación (primera versión) del código.

#include "Contenedor.h"

#include <iostream>

int main() {
  Contenedor contenedor(4);

  contenedor.insertarFinal(10);
  contenedor.insertarFinal(20);
  contenedor.insertarFinal(30);

  std::cout << "Tamano: " << contenedor.tamano() << std::endl;
  std::cout << "Capacidad: " << contenedor.capacidad() << std::endl;
  std::cout << "Elemento 1: " << contenedor.obtener(1) << std::endl;

  contenedor.establecer(1, 99);
  std::cout << "Elemento 1 modificado: " << contenedor.obtener(1) << std::endl;

  contenedor.insertarFinal(40);
  contenedor.insertarFinal(50);
  contenedor.insertarFinal(60);

  std::cout << "Contenido: ";
  contenedor.mostrar();

  contenedor.eliminarFinal();
  std::cout << "Tras eliminar el ultimo: ";
  contenedor.mostrar();

  return 0;
}
