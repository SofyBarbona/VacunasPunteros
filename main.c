#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DOSIS 5

///Crear un programa que permita administrar las 5 posibles dosis
///de un ciudadano vacunado contra el COVID-19. Para realizar este
///ejercicio se pide que se utilice fuertemente punteros y se
///respeten las siguientes estructuras y funciones y procedimientos:

struct Vacuna{
    char nombre[20];
    char lote[11]; //CODIGO aleatorio alfanumerico
};
struct Ciudadano{
    char nombreyApellido[30];
    int nroCiudadano; //Entero aleatorio de 6 cifras
    struct Vacuna vacunas[DOSIS];

};

//Funciones de vacuna
void cargarVacuna(struct Vacuna * v);
void mostrarVacuna(struct Vacuna * v);
//Funciones de ciudadano
void cargarCiudadano(struct Ciudadano * c);
void mostrarCiudadano(struct Ciudadano * c);
int buscarVacuna(struct Ciudadano * c, char nombreVacuna[20]);

void codigo(char alfanumerico[10]);

int main()
{
    srand(time(0));

    struct Ciudadano Ciu1;
    cargarCiudadano(&Ciu1);
    mostrarCiudadano(&Ciu1);

    printf("\nLa vacuna esta en la posicion %d\n", buscarVacuna(&Ciu1,"MODERNA"));

    return 0;
}
int buscarVacuna(struct Ciudadano * c, char nombreVacuna[20]){
    int pos = -2;
    for(int i=0;i<DOSIS;i++){
            if(strcmp(c->vacunas[i].nombre,nombreVacuna)==0){ // Para estructuras se utiliza ".", pero para desreferenciar
                pos=i;                                         // un puntero de struct se usa "->" osea, (*Puntero).nombre = puntero->nombre
                i=6;
            }
    }
    return pos;
}
void codigo(char alfanumerico[10]){ //Recordar que los arrays funcionan como punteros
    char caracteres[] = "qwertyuiopasdfghjklzxcvbnm0123456789";
    int aleatorio;

    for(int i=0;i<10;i++){
        aleatorio = rand() % strlen(caracteres);
        alfanumerico[i] = caracteres[aleatorio];
    }
    alfanumerico[10]= '\0';
}
void mostrarVacuna(struct Vacuna* v){
    printf("\nEl nombre de la vacuna es: %s\n",v->nombre);
    printf("El lote de la vacuna es: %s\n",v->lote);
}
void mostrarCiudadano(struct Ciudadano* c){
    printf("\nNombre y apellido: %s\n", c->nombreyApellido);
    printf("NRO de ciudadano: %d\n", c->nroCiudadano);

    for(int i=0;i<DOSIS;i++){
        mostrarVacuna(&(c->vacunas[i]));
    }
}
void cargarVacuna(struct Vacuna * v){
    printf("Ingrese el nombre de la vacuna\n");
    fflush(stdin);
    gets(v->nombre);

    codigo(v->lote);
}
void cargarCiudadano(struct Ciudadano* c){
    printf("\nIngrese el nombre y apellido del ciudadano\n");
    fflush(stdin);
    gets(c->nombreyApellido);

    c->nroCiudadano = 100000+rand()%900000;

    printf("\nCargue sus vacunas: \n");
    for(int i=0;i<DOSIS;i++){
        cargarVacuna(&(c->vacunas[i]));
    }

}
