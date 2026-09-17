/*
 * Proyecto: Practica 1 - Contenedores en C++
 * Fichero: Makefile
 * Descripcion: Compilacion del programa del contenedor dinamico.
 * Autor: Copilot
 * Fecha: 2026-09-17
 */

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
