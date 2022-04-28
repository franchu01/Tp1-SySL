#include <stdio.h>
#include <stdlib.h>

// Funcion para punto 1 - Funciona

int tamanoCadena (char c[])
{
    int contador = 0;
    for(int i=0;c[i]!='\0';i++)
        contador++;
    return contador-1;
}


//Funcion para punto 2 - Funciona

int caracterValido(const char cad)
{
    return cad >= '0' && cad <= '9';
}

int cadenaANumero(const char *cad, int tam)
{
    int i = tam - 1;
    int entero = 0;
    int pos = 1;
    while(i >= 0)
    {
        while(caracterValido(cad[i]))
        {
            entero = entero + (cad[i] - 48) * pos;
            pos = pos*10;
            i--;
        }
        pos = 1;
        i--;
    }
    return entero;
}

// Funcion punto 3 - Funciona

void cadenaAMayusculas(char cad[])
{
    char aux;
    for(int i=0; cad[i] != '\n'; i++)
    {
        if(cad[i] >= 97 && cad[i] <= 122)
            cad[i]=cad[i]-32;
    }
}

//Funcion punto 4

void eliminarOcurrencias(char cad[], char caracter)
{
    int j=0;
    for(int i=0; cad[i] != '\0'; i++)
    {
        if(cad[i]!=caracter)
        {
            cad[j]=cad[i];
            j++;
        }
    }
}

// Funcion punto 5

void concatenarCadenas(char cadena1[], char cadena2[])
{
    int tamanoCadena1=0;
    for(int i=0; cadena1[i] != 0; i++)
        tamanoCadena1++;

    for(int i=0; cadena2[i] != 0; i++)
        {
            cadena1[tamanoCadena1]=cadena2[i];
            tamanoCadena1++;
        }
}

// Funcion punto 6

void instertarCaracter(char cad[], char caracter, int pos)
{
    char auxAnterior=0, aux=0;
    int estado=0;

    for(int i=0; cad[i-1] != 0; i++)
    {
        auxAnterior=aux;
        if(i==pos-1 && estado==0)
        {
            auxAnterior=cad[i];
            cad[i]=caracter;
            estado=1;

        }
        if(estado==1)
        {
            aux=cad[i];
            cad[i]=auxAnterior;
        }
    }
}


int main(){

    //Punto 1 - Funciona

    char cadena[100];
    printf("Ingrese la cadena para calcular el tamano: ");
    fflush(stdin);
    fgets(cadena, sizeof(cadena), stdin);
    int tamano = tamanoCadena(cadena);
    printf("Tamano: %d\n",tamano);

    // Punto 2 - Funciona

    char cadenaNum[10];
    int tamano2 = 10;
    printf("Ingrese la cadena de digitos a convertir: ");
    fflush(stdin);
    fgets(cadenaNum, sizeof(cadenaNum), stdin);
    printf("%d\n", cadenaANumero(cadenaNum, tamano2));

    // Punto 3 - Funciona

    char cadenaAMayus[100];
    printf("Ingrese la cadena a pasar a mayusculas: ");
    fflush(stdin);
    fgets(cadenaAMayus, sizeof(cadenaAMayus), stdin);
    cadenaAMayusculas(cadenaAMayus);
    printf("La cadena en mayusucula es: %s\n",cadenaAMayus);

    // Punto 4

    char cadenaAModificar[100], caracterEliminar;
    printf("Ingrese cadena\n");
    scanf("%s",&cadenaAModificar);
    printf("Ingrese caracter a eliminar de la cadena\n");
    fflush(stdin);
    scanf("%c",&caracterEliminar);
    eliminarOcurrencias(cadenaAModificar,caracterEliminar);
    printf("Cadena sin el caracter: %s\n",cadenaAModificar);

    // Punto 5

    char cadena1[100];
    char cadena2[100];
    printf("Ingrese cadena 1 \n");
    scanf("%s",&cadena1);
    printf("Ingrese cadena 2 \n");
    fflush(stdin);
    scanf("%s",&cadena2);
    concatenarCadenas(cadena1,cadena2);
    printf("Cadena concatenada: %s\n",cadena1);

    // Punto 6

    char cadenaAAgregar[100], caracterInsertar;
    int pos=0;
    printf("Ingrese cadena\n");
    scanf("%s",&cadenaAAgregar);
    printf("Ingrese caracter a ingresar en la cadena\n");
    fflush(stdin);
    scanf("%c",&caracterInsertar);
    printf("Ingrese posicion a insertar caracter\n");
    fflush(stdin);
    scanf("%d",&pos);
    instertarCaracter(cadenaAAgregar,caracterInsertar,pos);
    printf("Cadena con el caracter ingresado: %s\n",cadenaAAgregar);

    printf("\n\n\n");

    system("pause");

    return 0;
}





