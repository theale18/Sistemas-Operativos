#include <stdio.h>     // printf, perror
#include <stdlib.h>    // EXIT_SUCESS, EXIT_FAILURE, exit
#include <unistd.h>    // fork, getpid, sleep
#include <sys/wait.h>  // wait, WEXITSTATUS
 
int main()  
{ 
    pid_t pid = fork();         // Crear un proceso hijo 
    if (pid == -1)              // -1 --> ERROR AL CREAR PROCESO
    { 
        perror("Error al crear el proceso hijo"); 
        return EXIT_FAILURE; 
    }  
    else if (pid == 0)         // 0 --> ESTAMOS EN EL PROCESO HIJO
    { 
    // Código del proceso hijo 
        printf("Soy el proceso hijo con PID %d\n", getpid()); 
        sleep(2);              // SIMULACION: EL HIJO TRABAJA 2 SEG 
        printf("Proceso hijo termina\n"); 
        exit(EXIT_SUCCESS);    // EL HIJO TERMINA CORRECTAMENTE
    }  
    else                       // >0 --> ESTAMOS EN EL PROCESO PADRE
    { 
    // Código del proceso padre 
        printf("Soy el proceso padre esperando al hijo...\n"); 
        int status; 
        wait(&status);         // EL PADRE ESPERA HASTA QUE EL HIJO TERMINE
                               // STATUS GUARDA INFO SOBRE COMO TERMINO EL HIJO
        printf("Proceso hijo finalizado con estado %d\n", 
        WEXITSTATUS(status));  // EXTRAE EL CODIGO DE SALIDA DEL HIJO
                               // SERIA 0, PORQUE EL HIJO HIZO "exit(EXIT_SUCESS)"
    } 
    return EXIT_SUCCESS; 
} 
/*    EJEMPLO:
Soy el proceso padre esperando al hijo...
Soy el proceso hijo con PID 1234
Proceso hijo termina
Proceso hijo finalizado con estado 0
*/
