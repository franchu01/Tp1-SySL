#include <stdio.h>
#include <stdlib.h>

// Funcion para punto 1

int tamanoCadena (char c[])
{
    int contador = 0;
    for(int i=0; c[i]!='\0'; i++)
        contador++;
    return contador;
}


//Funcion para punto 2

int caracterValido(const char cad)
{
    return cad >= '0' && cad <= '9';
}

int cadenaANumero(char cad[])
{
    int i = tamanoCadena(cad) - 1;
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
        i--;
    }
    return entero;
}

// Funcion para punto 3

void cadenaAMayusculas(char cad[])
{
    char aux;
    int i=0;
    for(i; cad[i] != '\0'; i++)
    {
        if(cad[i] >= 97 && cad[i] <= 122)
            cad[i]=cad[i]-32;
    }
}

// Funcion para punto 4

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
    cad[j]='\0';
}

// Funcion para punto 5

void concatenarCadenas(char cadena1[], char cadena2[])
{
    int tamanoCadena1 = tamanoCadena(cadena1);

    for(int i=0; cadena2[i] != '\0'; i++)
        {
            cadena1[tamanoCadena1]=cadena2[i];
            tamanoCadena1++;
        }
    cadena1[tamanoCadena1]='\0';
}

// Funcion para punto 5

void instertarCaracter(char cad[], char caracter, int i)
{
    char auxAnterior = '\0', aux = '\0';
    int estado = 0;

    for(i; cad[i] != '\0'; i++)
    {
        auxAnterior=aux;
        if(estado==0)
        {
            aux=cad[i];
            cad[i]=caracter;
            estado=1;

        }else{
            aux=cad[i];
            cad[i]=auxAnterior;
        }
    }
    cad[i]=aux;
    cad[i+1] = '\0';
}


int main(){
    int tamano=0;

    //Punto 1

    char cadena[100];
    printf("Ingrese la cadena para calcular el tamano: ");
    fflush(stdin);
    fgets(cadena, sizeof(cadena), stdin);
    tamano = tamanoCadena(cadena);
    cadena[tamano-1]='\0';          //Ponemos esta linea dado que la funcion fgets toma a \n como valor previo al \0.
                                    //De esta manera, calculamos el tamaño de una cadena y le restamos 1 para reemplazar ese \n por un \0.
    tamano = tamanoCadena(cadena);  //Luego, calculamos su valor nuevamente con esta modificación.
    printf("Tamano: %d\n",tamano);  //Este paso se repite en las cadenas de los otros puntos.

    // Punto 2

    char cadenaNum[100];
    printf("Ingrese la cadena de digitos a convertir: ");
    fflush(stdin);
    fgets(cadenaNum, sizeof(cadenaNum), stdin);
    printf("%d\n", cadenaANumero(cadenaNum));

    // Punto 3

    char cadenaAMayus[100];
    printf("Ingrese la cadena a pasar a mayusculas: ");
    fflush(stdin);
    fgets(cadenaAMayus, sizeof(cadenaAMayus), stdin);
    tamano = tamanoCadena(cadenaAMayus);
    cadenaAMayus[tamano-1]='\0';
    cadenaAMayusculas(cadenaAMayus);
    printf("La cadena en mayusucula es: %s\n",cadenaAMayus);

    // Punto 4

    char cadenaAModificar[100], caracterEliminar;
    printf("Ingrese cadena para eliminar un caracter\n");
    fflush(stdin);
    fgets(cadenaAModificar, sizeof(cadenaAModificar), stdin);
    tamano = tamanoCadena(cadenaAModificar);
    cadenaAModificar[tamano-1]='\0';
    printf("Ingrese caracter a eliminar de la cadena\n");
    fflush(stdin);
    scanf("%c",&caracterEliminar);
    eliminarOcurrencias(cadenaAModificar,caracterEliminar);
    printf("Cadena sin el caracter: %s\n",cadenaAModificar);

    // Punto 5

    char cadena1[100];
    char cadena2[100];
    printf("Ingrese cadena 1 \n");
    fflush(stdin);
    fgets(cadena1, sizeof(cadena1), stdin);
    tamano = tamanoCadena(cadena1);
    cadena1[tamano-1]='\0';
    printf("Ingrese cadena 2 \n");
    fflush(stdin);
    fgets(cadena2, sizeof(cadena2), stdin);
    tamano = tamanoCadena(cadena2);
    cadena2[tamano-1]='\0';
    concatenarCadenas(cadena1,cadena2);
    printf("Cadena concatenada: %s\n",cadena1);

    // Punto 6

    char cadenaAAgregar[100], caracterInsertar;
    int pos=0;
    printf("Ingrese cadena para ingresarle un caracter\n");
    fflush(stdin);
    fgets(cadenaAAgregar, sizeof(cadenaAAgregar), stdin);
    tamano = tamanoCadena(cadenaAAgregar);
    cadenaAAgregar[tamano-1]='\0';
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
