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
# Descripción: Reglas de compilación del ejercicio 1.
# Historial de revisiones:
# 17/09/2026 - Actualización para p01_single_grades.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = p01_single_grades
OBJECTS = main.o Estudiante.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cc Estudiante.h
	$(CXX) $(CXXFLAGS) -c main.cc

Estudiante.o: Estudiante.cc Estudiante.h
	$(CXX) $(CXXFLAGS) -c Estudiante.cc

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
