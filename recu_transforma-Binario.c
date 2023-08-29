#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>


void mostrar(FILE *);
int Convierte_a_Letra(char[]);
int error(char *);
void pausa(void);

int main(){
    FILE *archivo;
    char nom1[80] = "textoBinario.txt", cad[81]; // nombre físico del archivo
    system("cls");
    if ((archivo = fopen(nom1, "r")) == NULL)
        exit(error(nom1)); // crea el archivo para escritura y lectura;
    printf("\n El archivo %s se ha abierto satisfactoriamente", nom1);
    printf("\n Presione una tecla para visualizar el contenido del archivo:%s\n\n", nom1);
    pausa();
    system("cls");
    rewind(archivo);
    printf("\n El contenido del archivo %s es:\n\n", nom1);
    mostrar(archivo);
    pausa();
    rewind(archivo);
    printf("\nMOSTRAMOS EL MENSAJE\n\n");
    while (fgets(cad, 81, archivo) != NULL)    {
        // aqui mostramos cada letra del mensaje en binario
        // una al lado de la otra
    }
    printf("\n\n");
    pausa();
    fclose(archivo);

    return (0);
}


void mostrar(FILE *x){
    int cant = 0;
    fread(&cant, sizeof(cant), 1, x); // Leer la cantidad de caracteres del archivo
    char binario[cant + 1]; // +1 para el carácter nulo al final
    fread(binario, sizeof(char), cant, x); // Leer la cadena binaria del archivo
    binario[cant] = '\0'; // Agregar el carácter nulo al final de la cadena

    printf("Texto en binario: %s\n", binario);

    printf("Mensaje convertido:\n");
    Convierte_a_Letra(binario); // Llamar a la función para convertir y mostrar el mensaje
}

int error(char *x){
    fprintf(stderr, "No se pudo abrir el archivo %s", x);
    return (1);
}

int Convierte_a_Letra(char x[]){
    int i;
    int cant = 81;
    char letra; 
    char binario[9];
    binario[8] = '\0'; // Revisa que el último elemento de binario sea nulo

    for (i = 0; i < cant; i += 8) // avanza de 8 en 8 bits (1 byte)
    {
        strncpy(binario, x + i, 8); // copia 8 bits en binario desde la posición actual de la cadena x
        letra = strtol(binario, NULL, 2); // convierte el bloque binario en un carácter ASCII
        printf("%c", letra); // muestra en pantalla
    }

    return 1;
}

void pausa(){
    printf("\n>>> Presione Enter para continuar...\n");
    fflush(stdin);
    while (getchar() != '\n');
}
