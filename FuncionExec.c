#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main()  
{ 
  char *args[] = {"ls", "-l", NULL};   //Argumentos para el comando "ls -l" 
  printf("Ejecutando exec...\n"); 
  execvp(args[0], args);               // Reemplaza el proceso actual con "ls -l" 
  // Si execvp falla, se ejecutará esta línea 
  perror("execvp fallo"); 
  return EXIT_FAILURE; 
}
