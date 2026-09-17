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
// Descripción: Programa del ejercicio 1 para gestionar calificaciones.
// Historial de revisiones:
// 17/09/2026 - Implementación de la opción --delete.

#include "Estudiante.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

void MostrarUso(const char* programa) {
  std::cerr << "Uso: " << programa << " FICHERO [--delete NOTA]" << std::endl;
}

bool LeerEstudiantes(const std::string& nombre_fichero,
                     std::vector<Estudiante>* estudiantes) {
  std::ifstream fichero(nombre_fichero);
  if (!fichero) {
    std::cerr << "No se puede abrir el fichero: " << nombre_fichero
              << std::endl;
    return false;
  }

  std::string linea;
  while (std::getline(fichero, linea)) {
    std::istringstream entrada(linea);
    std::string identificador;
    double nota;

    // Las líneas vacías y los comentarios se ignoran. Se aceptan como
    // separadores espacios, comas y puntos y coma.
    if (linea.empty() || linea.find_first_not_of(" \t") == std::string::npos ||
        linea[linea.find_first_not_of(" \t")] == '#') {
      continue;
    }
    std::replace(linea.begin(), linea.end(), ',', ' ');
    std::replace(linea.begin(), linea.end(), ';', ' ');
    entrada.clear();
    entrada.str(linea);

    if (!(entrada >> identificador >> nota)) {
      std::cerr << "Línea ignorada por formato incorrecto: " << linea
                << std::endl;
      continue;
    }
    estudiantes->emplace_back(identificador, nota);
  }
  return true;
}

bool GuardarEstudiantes(const std::string& nombre_fichero,
                        const std::vector<Estudiante>& estudiantes) {
  std::ofstream fichero(nombre_fichero, std::ios::trunc);
  if (!fichero) {
    std::cerr << "No se puede escribir el fichero: " << nombre_fichero
              << std::endl;
    return false;
  }

  fichero << std::setprecision(10);
  for (const Estudiante& estudiante : estudiantes) {
    fichero << estudiante.identificador() << ' ' << estudiante.nota() << '\n';
  }
  return true;
}

}  // namespace

int main(int argc, char* argv[]) {
  if (argc != 2 && argc != 4) {
    MostrarUso(argv[0]);
    return 1;
  }

  const std::string nombre_fichero = argv[1];
  std::vector<Estudiante> estudiantes;
  if (!LeerEstudiantes(nombre_fichero, &estudiantes)) {
    return 1;
  }

  if (argc == 2) {
    for (const Estudiante& estudiante : estudiantes) {
      std::cout << estudiante.identificador() << ' ' << estudiante.nota()
                << std::endl;
    }
    return 0;
  }

  if (std::string(argv[2]) != "--delete") {
    MostrarUso(argv[0]);
    return 1;
  }

  double umbral;
  try {
    std::size_t caracteres_leidos = 0;
    umbral = std::stod(argv[3], &caracteres_leidos);
    if (caracteres_leidos != std::string(argv[3]).size()) {
      throw std::invalid_argument("nota no numérica");
    }
  } catch (const std::exception&) {
    std::cerr << "La nota debe ser un número válido." << std::endl;
    return 1;
  }

  const auto nuevo_final = std::remove_if(
      estudiantes.begin(), estudiantes.end(), [umbral](const Estudiante& estudiante) {
        if (estudiante.nota() < umbral) {
          std::cout << "El estudiante " << estudiante.identificador()
                    << " ha sido borrado con éxito" << std::endl;
          return true;
        }
        return false;
      });

  const bool hay_borrados = nuevo_final != estudiantes.end();
  estudiantes.erase(nuevo_final, estudiantes.end());

  if (!hay_borrados) {
    std::cout << "No se han encontrado estudiantes" << std::endl;
    return 0;
  }

  return GuardarEstudiantes(nombre_fichero, estudiantes) ? 0 : 1;
}
