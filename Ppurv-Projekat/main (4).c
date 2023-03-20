/*Predmetni projekat iz PPuRV*/

/*Bozidar Krunic RA160/2019*/

/*Zadatak ovog projekta je odredjivanje nzd Euklidovim algoritmom.
Pritom hardverski nisu podrzane operacije deljenja i ostatka.
Potrbno je napraviti euclid modul i realizovati ga kao dinamicku
biblioteku sa dinamickim povezivanjem tokom punjenja */

/*Resenje: zadatak sam realizovao tako sto sam prvo napravio funkciju
koja ce da izvrsava proces deljenja preko oduzimanja. Zatim sam implementirao
funkciju koja ce da odredjuje ostatak pri deljenju. Euklidov algoritam odredjivanja
nzd-a odredjuje nzd za dva broja, pa je bilo potrebno osmisliti nacin kako ce da odredi
nzd za vise brojeva. Napravio sam jednu funkciju za nzd za dva broja. Druga funkcija
predstavlja nzd za vise brojeva. Broje vi se prosledjuju u nizu, prvo se radi nzd za prva dva
pa onda nzd za sledeci i rezultat nzd od prethodna dva i tako dalje.*/

/*Posto je ovo odredjivanje nzd po Euklidovom algoritmu koji radi sa celim brojevima bez zareza,
tako da se koriste promenljive int tipa. Koristim int_fast32_t zbog optimizacije koda usled matematickih operacija.*/

/*Ogranicenje 32bitne vrednosti, pa ni niz ne moze premasiti toliki broj elemenata, dolazi
do overflow-a*/

/*Dilema je bila da li gcd moze biti negativan, a odgovor je da moze ali se uvek gledaju apsolutne vr,
npr delioci broja -3 su -3/-1/1/3 pa se uzima 3 kao apsolutna*/

/*Kod je proveren po MISRI i zadovoljava sve, jedino u main.c se javljaju warninzi zbog koriscenja printf,
i prilikom deljenja gde se zaokruzuje zbog int*/





#include "euclidgcd.h"
#pragma CHECK_MISRA("none")
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#pragma CHECK_MISRA("all")

int main(void){


    /*Division*/

    /*int_fast32_t d1 = division(30,0);*/ /*Assert if num2 == 0*/
    int_fast32_t d2 = division(0, 54);
    int_fast32_t d3 = division(-45, 23);
    int_fast32_t d4 = division(-160000000000000, -4550000444000);
    int_fast32_t d5 = division(12000400, 60000000000000000);

    printf("Print of division\n");
    printf("%"PRIdFAST32"\n", d2);
    printf("%"PRIdFAST32"\n", d3);
    printf("%"PRIdFAST32"\n", d4);
    printf("%"PRIdFAST32"\n", d5);



    /*Remainder of division*/

    int_fast32_t r1 = findRem(0, 51);
    /*int_fast32_t r2 = findRem(53, 0);*/ /*Assert in div for num2 == 0*/
    int_fast32_t r3 = findRem(44, 21);
    int_fast32_t r4 = findRem(-51, 11);
    int_fast32_t r5 = findRem(-160000, -34050);

    printf("Print of remainder\n");
    printf("%"PRIdFAST32"\n", r1);
    /*printf("%"PRIdFAST32"\n", r2);*/
    printf("%"PRIdFAST32"\n", r3);
    printf("%"PRIdFAST32"\n", r4);
    printf("%d\n", abs(r5));


    /*GCD of two numbers*/

    int_fast32_t g1 = gcd(0, 50);
    int_fast32_t g2 = gcd(51, 0);
    int_fast32_t g3 = gcd(66, 42);
    int_fast32_t g4 = gcd(-50, 51);
    int_fast32_t g5 = gcd(-69408, -6790);

    printf("Print of gcd\n");
    printf("%"PRIdFAST32"\n", g1);
    printf("%"PRIdFAST32"\n", g2);
    printf("%"PRIdFAST32"\n", g3);
    printf("%"PRIdFAST32"\n", g4);
    printf("%"PRIdFAST32"\n", g5);

    /*Find gcd for multiple numbers*/

    int_fast32_t arr1[] = {4, 12, 8, 64};
    int_fast32_t arr2[] = {3450, 0, 55532, -541, 40};
    int_fast32_t arr3[] = {0, 0, 0, 540, 450, 320, 0};
    /*int_fast32_t arr4[] = {3000000000000000000, 540000, 4350};*/ /*Prvi broj veci nego sto int32 moze prihvatiti*/

    int_fast32_t n1 = division(sizeof(arr1), sizeof(arr1[0]));
    int_fast32_t n2 = division(sizeof(arr2), sizeof(arr2[0]));
    int_fast32_t n3 = division(sizeof(arr3), sizeof(arr3[0]));
    /*int_fast32_t n4 = division(sizeof(arr4), sizeof(arr4[0]));*/

    int_fast32_t c1 = findGCD(arr1, n1);
    int_fast32_t c2 = findGCD(arr2, n2);
    int_fast32_t c3 = findGCD(arr3, n3);
    /*int_fast32_t c4 = findGCD(arr4, n4);*/

    printf("Print of multiple gcd\n");
    printf("%"PRIdFAST32"\n", c1);
    printf("%"PRIdFAST32"\n", c2);
    printf("%"PRIdFAST32"\n", c3);
    /*printf("%"PRIdFAST32"\n", c4);*/

    /*
    int_fast32_t arr_err[1000000000] = {};
    int_fast32_t i;

    for (i=0; i< 1000000000; i++)
    {
        arr_err[i] = i;
    }

    int_fast32_t err = division(sizeof(arr_err), sizeof(arr_err[0]));
    int_fast32_t gcd_err = findGCD(arr_err, err);
    */
   /*Baca error zato sto niz ne moze prihvatiti ovoliko elemenata*/

    return 0;

}
