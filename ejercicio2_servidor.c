#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PUERTO 8080

// Función para convertir Celsius a Fahrenheit
float celsiusAFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

// Función para convertir Fahrenheit a Celsius
float fahrenheitACelsius(float f) {
    return (f - 32) * 5 / 9;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };

    // Crear socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Error en la creación del socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PUERTO);

    // Asociar socket al puerto
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Error en el bind");
        exit(EXIT_FAILURE);
    }

    // Escuchar conexiones
    if (listen(server_fd, 3) < 0) {
        perror("Error en listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor esperando conexiones...\n");

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Error en accept");
            exit(EXIT_FAILURE);
        }

        read(new_socket, buffer, 1024);
        printf("Petición recibida: %s\n", buffer);

        char tipo;
        float valor, resultado;
        sscanf(buffer, "%c/%f", &tipo, &valor);

        char respuesta[50];

        if (tipo == 'C') {
            resultado = celsiusAFahrenheit(valor);
            sprintf(respuesta, "F/%.2f", resultado);
        }
        else if (tipo == 'F') {
            resultado = fahrenheitACelsius(valor);
            sprintf(respuesta, "C/%.2f", resultado);
        }
        else {
            strcpy(respuesta, "ERROR/Formato inválido");
        }

        send(new_socket, respuesta, strlen(respuesta), 0);
        printf("Respuesta enviada: %s\n", respuesta);

        close(new_socket);
    }

    return 0;
}
