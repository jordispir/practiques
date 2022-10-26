#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *txt;
    FILE *final_txt;

    char f;
    int contIteracions = 0;
    int contOk = 0;
    int contDefectuosos = 0;
    int i;

    int arrayDefectuoso[12];

    float far;
    float cel;

    float valorTotal;
    float valorMitja;

    txt = fopen("temp1.txt", "r");

    final_txt = fopen("temp1_convert.txt", "w");

    while (f != EOF)
    {
        f = fscanf(txt, "%f", &far);

        if (far != -999.9f)
        {
            cel = (far - 32)/1.8;
            valorTotal = valorTotal + cel;

            printf("%f | %f \n", far, cel);
            fprintf(final_txt, "%f \n", cel);

            contOk ++;

        }

        else
        {
            arrayDefectuoso[contDefectuosos] = contIteracions;
            contDefectuosos ++;
         
        }

        contIteracions ++;

    }

    printf("El valor mitja de les temperatures en celcius es %f\n", valorTotal / contOk);
    printf("La cantidad de sensores defectuosos es de %d\n", contDefectuosos);

    for (i = 0; i < contDefectuosos; i++)
    {
        printf("valor defectuoso en la posicion %d\n", arrayDefectuoso[i]);
    }

    fclose(txt);
    fclose(final_txt);
    
    return 0;
}