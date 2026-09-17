/*
 * Proyecto: Practica 1 - Contenedores en C++
 * Fichero: main.cc
 * Descripcion: Programa principal de demostracion del contenedor dinamico.
 * Autor: Copilot
 * Fecha: 2026-09-17
 */

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
