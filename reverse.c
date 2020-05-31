#include <stdio.h>
#include <stdlib.h>

#define FILENAME "ReaperFile.txt"

int main()
{
    FILE *fp = NULL;

    int cnt = 0;
    int i = 0;
    char ch = ' ';

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return -1;
    }

    printf("\nOriginal contents in '%s' file:\n--------------------------------------------------\n",FILENAME);
    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);

    printf("\n\n\nReversed contents in '%s' file:\n--------------------------------------------------\n",FILENAME);
    // moves the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // get the position of the file pointer
    cnt = ftell(fp);

    while (i < cnt)
    {
        i++;
        fseek(fp, -i, SEEK_END);
        printf("%c", fgetc(fp));
    }

    printf("\n");
    fclose(fp);
    fp = NULL;

    return 0;
}
