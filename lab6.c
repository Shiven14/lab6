// lab6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 54769
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(server_fd, 3);
    printf("Ping-Pong server listening on port %d...\n", PORT);

    socklen_t addrlen = sizeof(address);
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);

    read(new_socket, buffer, BUFFER_SIZE);
    printf("Received: %s\n", buffer);

    if (strcmp(buffer, "ping") == 0) {
        send(new_socket, "pong", strlen("pong"), 0);
        printf("Sent: pong\n");
    } else {
        send(new_socket, "unknown", strlen("unknown"), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
