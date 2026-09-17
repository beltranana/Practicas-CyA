/*
 * Proyecto: Practica 1 - Contenedores en C++
 * Fichero: p01_containers/Contenedor.cc
 * Descripcion: Implementacion de un contenedor dinamico de enteros.
 * Autor: Beltrán, Rodrigo Barrios Gonzalez
 * Fecha: 2026-09-17
 */

#include "Contenedor.h"

#include <iostream>

Contenedor::Contenedor() : Contenedor(8) {
}

Contenedor::Contenedor(int capacidad_inicial) {
  capacidad_ = capacidad_inicial > 0 ? capacidad_inicial : 1;
  datos_ = new int[capacidad_];
  tamano_ = 0;
}

Contenedor::~Contenedor() {
  delete[] datos_;
}

void Contenedor::insertarFinal(int valor) {
  if (tamano_ == capacidad_) {
    reservarMasEspacio();
  }

  datos_[tamano_] = valor;
  tamano_++;
}

bool Contenedor::eliminarFinal() {
  if (vacio()) {
    return false;
  }

  tamano_--;
  return true;
}

int Contenedor::obtener(int indice) const {
  if (indice < 0 || indice >= tamano_) {
    std::cerr << "Indice fuera de rango." << std::endl;
    return 0;
  }

  return datos_[indice];
}

void Contenedor::establecer(int indice, int valor) {
  if (indice < 0 || indice >= tamano_) {
    std::cerr << "Indice fuera de rango." << std::endl;
    return;
  }

  datos_[indice] = valor;
}

int Contenedor::tamano() const {
  return tamano_;
}

int Contenedor::capacidad() const {
  return capacidad_;
}

bool Contenedor::vacio() const {
  return tamano_ == 0;
}

void Contenedor::limpiar() {
  tamano_ = 0;
}

void Contenedor::mostrar() const {
  std::cout << "[";
  for (int i = 0; i < tamano_; ++i) {
    std::cout << datos_[i];
    if (i < tamano_ - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

void Contenedor::reservarMasEspacio() {
  int nueva_capacidad = capacidad_ * 2;
  int* nuevo_datos = new int[nueva_capacidad];

  for (int i = 0; i < tamano_; ++i) {
    nuevo_datos[i] = datos_[i];
  }

  delete[] datos_;
  datos_ = nuevo_datos;
  capacidad_ = nueva_capacidad;
}
