#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Función para verificar si un nombre es palíndromo
int esPalindromo(char* str) {
    int i, j;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) { //funcion tolower. la convierte en minúsculas
            return 0; // No es palíndromo
        }
    }
    return 1; // Es palíndromo
}

// Función para convertir un nombre a mayúsculas
void convertirMayusculas(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main(int argc, char* argv[]) {
    char peticion[100];

    strcpy(peticion, "3/merce/47/1.78");

    int codigo;
    char nombre[20];
    int edad;
    float altura;

    // Procesar la petición separada por "/"
    char* p = strtok(peticion, "/");
    codigo = atoi(p);
    p = strtok(NULL, "/");
    strcpy(nombre, p);
    p = strtok(NULL, "/");
    edad = atoi(p);
    p = strtok(NULL, "/");
    altura = atof(p);

    printf("Código: %d, Nombre: %s, Edad: %d, Altura: %.2f\n", codigo, nombre, edad, altura);

    // Verificar si el nombre es palíndromo
    if (esPalindromo(nombre)) {
        printf("El nombre '%s' es un palíndromo.\n", nombre);
    }
    else {
        printf("El nombre '%s' NO es un palíndromo.\n", nombre);
    }

    // Convertir el nombre a mayúsculas
    convertirMayusculas(nombre);
    printf("Nombre en mayúsculas: %s\n", nombre);

    return 0;
}
