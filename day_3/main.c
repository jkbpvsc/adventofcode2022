#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define MAX_LINE_LEN 200

// Load file from input.txt and iterate over lines
int main()
{
    FILE *file_ptr;
    char line[MAX_LINE_LEN];

    file_ptr = fopen("input.txt", "r");
    if (file_ptr == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    int score = 0;

    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL)
    {
        printf("Line: %s", line);
        int len = fine_line_len(line, MAX_LINE_LEN);
        char *cmpr_one = malloc(MAX_LINE_LEN * sizeof(char));
        char *cmpr_two = malloc(MAX_LINE_LEN * sizeof(char));

        memcpy(cmpr_one, line, len / 2);
        memcpy(cmpr_two, &line[len / 2], len / 2);

        char mutual = find_mutual(cmpr_one, cmpr_two, len / 2, len / 2);
        int char_score = char_to_int(mutual);
        score += char_score;
        printf("Mutual: %c, score: %d\n", mutual, char_score);
    }

    printf("Final score: %d\n", score);

    fclose(file_ptr);
    return 0;
}