#include <sys/types.h>  // define tipos como pid_t (tipo de dato para IDs de procesos). 
#include <unistd.h>     // contiene funciones del sistema Unix como fork(), getpid(), getppid().
#include <stdio.h>      // printf()
 
int main() 
{ 
    pid_t pid;      // Se declara pid, que almacenará el valor devuelto por fork().
    pid = fork(); 
    if (pid == 0) 
    { /* hijo */ 
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(), getppid()); 
//  getpid() → PID del proceso actual (el hijo)
//  getppid() → PID del padre del proceso (el padre)    
    } 
    else 
    { /* padre */ 
        printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid()); 
    } 
    return 0; 
}

/*
Supongamos que el PID del padre es 1000
y el del hijo 1001.

La salida podría ser:
Soy el padre (1000, hijo de 950)
Soy el hijo (1001, hijo de 1000)

*/
