#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 200

// File line len by counting chars until newline or end of file
int fine_line_len(char *line, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (line[i] == '\n' || line[i] == '\0')
        {
            return i;
        }
    }
    return len;
}

// fine mutual element in both chars
char find_mutual(char *line1, char *line2, int len1, int len2)
{
    printf("Comparing %s and %s\n", line1, line2);
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (line1[i] == line2[j])
            {
                printf("Found mutual element %c\n", line1[i]);
                return line1[i];
            }
        }
    }

    exit(1);
}
// Lowercase item types a through z have priorities 1 through 26.
// Uppercase item types A through Z have priorities 27 through 52.
int char_to_int(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 27;
    }
    else
    {
        exit(1);
    }
}

// Find mutual char in 3 strings
char find_mutual_3(char *line1, char *line2, char *line3, int len1, int len2, int len3)
{
    printf("Comparing %s and %s and %s\n", line1, line2, line3);

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            for (int k = 0; k < len3; k++)
            {
                if (line1[i] == line2[j] && line1[i] == line3[k])
                {
                    printf("Found mutual element %c (%d %d %d)\n", line1[i], i, j, k);
                    return line1[i];
                }
            }
        }
    }

    exit(1);
}

// Load file from input.txt and iterate over lines
int main()
{
    FILE *file_ptr;

    file_ptr = fopen("input.txt", "r");
    if (file_ptr == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    int score = 0;

    // Read three lines at a time until EOF
    while (1)
    {
        char elf1_rucksack[MAX_LINE_LEN];
        char elf2_rucksack[MAX_LINE_LEN];
        char elf3_rucksack[MAX_LINE_LEN];

        char *r = fgets(elf1_rucksack, MAX_LINE_LEN, file_ptr);
        
        // We have reached EOF
        if (r == NULL)
        {
            break;
        }

        fgets(elf2_rucksack, MAX_LINE_LEN, file_ptr);
        fgets(elf3_rucksack, MAX_LINE_LEN, file_ptr);

        int elf1_rucksack_len = fine_line_len(elf1_rucksack, MAX_LINE_LEN);
        int elf2_rucksack_len = fine_line_len(elf2_rucksack, MAX_LINE_LEN);
        int elf3_rucksack_len = fine_line_len(elf3_rucksack, MAX_LINE_LEN);

        char mutual = find_mutual_3(elf1_rucksack, elf2_rucksack, elf3_rucksack, elf1_rucksack_len, elf2_rucksack_len, elf3_rucksack_len);
        int char_score = char_to_int(mutual);
        score += char_score;
    }

    printf("Final score: %d\n", score);

    fclose(file_ptr);
    return 0;
}