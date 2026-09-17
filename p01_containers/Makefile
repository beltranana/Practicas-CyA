# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 1: Contenedores
# Autor: Beltrán Rodrigo Barrios González
# Correo: alu0101718330@ull.edu.es
# Fecha: 17/09/2026
# Archivo: p01_containers/Makefile
# Fichero de reglas para compilar y limpiar el programa de demostración
# del contenedor dinámico de enteros.
# Referencias:
# Enlaces de interés:
# Historial de revisiones:
# 17/09/2026 - Creación (primera versión) del código.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = contenedor
OBJECTS = main.o Contenedor.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cc Contenedor.h
	$(CXX) $(CXXFLAGS) -c main.cc

Contenedor.o: Contenedor.cc Contenedor.h
	$(CXX) $(CXXFLAGS) -c Contenedor.cc

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
