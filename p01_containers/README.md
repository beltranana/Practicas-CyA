<!--
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 1: Contenedores
Autor: Beltrán Rodrigo Barrios González
Correo: alu0101718330@ull.edu.es
Fecha: 17/09/2026
Archivo: p01_containers/README.md
Descripción: Ejercicio 1, gestión de calificaciones.
Historial de revisiones:
17/09/2026 - Implementación inicial del ejercicio 1 y de --delete.
-->

# Práctica 1 - Ejercicio 1

El programa `p01_single_grades` lee un fichero de calificaciones. Cada línea
válida debe contener un identificador de estudiante y una nota, separados por
espacios, comas o punto y coma. Las líneas que empiezan por `#` se ignoran.

## Compilación

```bash
make
```

## Ejecución

Para mostrar las calificaciones:

```bash
./p01_single_grades grades.txt
```

Para eliminar del fichero todos los estudiantes cuya nota sea menor que el
umbral indicado:

```bash
./p01_single_grades grades.txt --delete 4
```

El programa muestra un mensaje por cada estudiante eliminado. Si no hay ningún
estudiante que cumpla la condición, muestra:

```text
No se han encontrado estudiantes
```

La opción `--delete` actualiza el fichero original después de realizar la
eliminación.

## Limpieza

```bash
make clean
```
