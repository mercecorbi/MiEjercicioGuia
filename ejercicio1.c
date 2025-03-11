#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Funci�n para verificar si un nombre es pal�ndromo
int esPalindromo(char* str) {
    int i, j;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) { //funcion tolower. la convierte en min�sculas
            return 0; // No es pal�ndromo
        }
    }
    return 1; // Es pal�ndromo
}

// Funci�n para convertir un nombre a may�sculas
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

    // Procesar la petici�n separada por "/"
    char* p = strtok(peticion, "/");
    codigo = atoi(p);
    p = strtok(NULL, "/");
    strcpy(nombre, p);
    p = strtok(NULL, "/");
    edad = atoi(p);
    p = strtok(NULL, "/");
    altura = atof(p);

    printf("C�digo: %d, Nombre: %s, Edad: %d, Altura: %.2f\n", codigo, nombre, edad, altura);

    // Verificar si el nombre es pal�ndromo
    if (esPalindromo(nombre)) {
        printf("El nombre '%s' es un pal�ndromo.\n", nombre);
    }
    else {
        printf("El nombre '%s' NO es un pal�ndromo.\n", nombre);
    }

    // Convertir el nombre a may�sculas
    convertirMayusculas(nombre);
    printf("Nombre en may�sculas: %s\n", nombre);

    return 0;
}
