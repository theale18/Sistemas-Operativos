#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
/*
Parte,Función
char * --> Tipo: Puntero a caracteres (String).
args[] --> Estructura: Un array para guardar múltiples strings.
    ls --> El ejecutable
    -l --> El parámetro.
  NULL --> El terminador obligatorio de la lista.
*/
int main()  
{ 
//  char *args[] --> Un Array donde cada elemento es un Puntero a 1 Caracter
    char *args[] = {"ls", "-l", NULL};   //Argumentos para el comando "ls -l" 
//  ls --> ES EL 1° ELEMENTO
//  -1 --> ES EL 2° ELEMENTO
    printf("Ejecutando exec...\n"); 
    execvp(args[0], args);               // Reemplaza el proceso actual con "ls -l" 
/*
    REEMPLAZA EL PROCESO ACTUAL
    CARGA EL PROGRAMA LS EN MEMORIA
    EL CODIGO ANTERIOR DEJA DE EXISTIR
    NO VUELVE EL MAIN()
*/
// Si execvp falla, se ejecutará esta línea 
    perror("execvp fallo");         // MSJ DE ERROR SI execvp FALLA
    return EXIT_FAILURE; 
}
