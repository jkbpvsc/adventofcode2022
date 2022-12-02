#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *el_1, const void *el_2)
{
    int a = *((int *)el_1);
    int b = *((int *)el_2);

    if (a > b)
        return -1;
    if (b > a)
        return 1;

    return 0;
}

int main()
{
    FILE *file_ptr;
    char str[50];
    char empty_string[] = "\n";

    unsigned int elfs[500] = {0};

    file_ptr = fopen("calories.txt", "r");

    if (file_ptr == NULL)
    {
        printf("Error opening file \n");
        return 1;
    }

    unsigned int elf_index = 0, elf_calories = 0;

    while (fgets(str, 50, file_ptr) != NULL)
    {
        if (strcmp(str, empty_string) == 0)
        {
            elfs[elf_index] = elf_calories;
            elf_index += 1;
            elf_calories = 0;
        }
        else
        {
            elf_calories += atoi(str);
        }
    }

    elfs[elf_index] = elf_calories;

    qsort(elfs, sizeof(elfs) / sizeof(*elfs), sizeof(*elfs), comp);
    int total = elfs[0] + elfs[1] + elfs[2];
    printf("Total: %d\n", total);

    return 0;
}

int first_part()
{
    FILE *file_ptr;
    char str[50];
    char empty_string[] = "\n";

    file_ptr = fopen("calories.txt", "r");

    if (file_ptr == NULL)
    {
        printf("Error opening file \n");
        return 1;
    }

    int elf_index = 0, max_elf_index = 0, elf_calories = 0, max_elf_calories = 0;

    while (fgets(str, 50, file_ptr) != NULL)
    {
        if (strcmp(str, empty_string) == 0)
        {
            if (elf_calories > max_elf_calories)
            {
                max_elf_calories = elf_calories;
                max_elf_index = elf_index;
            }

            elf_index += 1;
            elf_calories = 0;
        }
        else
        {
            elf_calories += atoi(str);
        }
    }

    // Check for last elf
    if (elf_calories > max_elf_calories)
    {
        max_elf_calories = elf_calories;
        max_elf_index = elf_index;
    }

    printf("Elf %d is carrying most calories %d\n", max_elf_index, max_elf_calories);

    return 0;
}