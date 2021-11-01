/*
Title  : sort strings in 2D array
Author : vaageesh
Date   : Saturday 31 October 2020 05:16:33 PM IST
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int city_sort(const void* city1, const void* city2) ;
int main()
{
        char cities[][10] = {"Hyderabad", "Bangalore", "bangalore"};
        int size = sizeof(cities) / sizeof(char*) ;

        printf("cities before sort:\n");
        for(int i = 0; i< size ; i++)
        {
            printf("%s\n", cities+i);
        }

        qsort(cities, 3,10, city_sort);

        printf("cities after sort:\n");
        for(int i = 0; i< size ; i++)
        {
            printf("%s\n", cities+i);
        }
        return 0;
}

int city_sort(const void* city1, const void* city2)
 {

    int ret = strcasecmp( (char*)city1, (char*)city2);
    if (ret == 0)
        return 0;
    else if (ret > 0)
        return 1;
    else
    return -1;
}
















