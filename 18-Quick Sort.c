#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    float height;
    int weight;
} student[10];

void swap(struct Student *a, struct Student *b)
{
    struct Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Student s[], int low, int high)
{
    int i, pivot;

    pivot = high;
    i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (strcmp(s[j].name, s[pivot].name) < 0)
        {
            i++;
            swap(&s[i], &s[j]);
        }
    }

    swap(&s[i + 1], &s[pivot]);

    return i + 1;
}

void quickSort(struct Student s[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(s, low, high);

        quickSort(s, low, partitionIndex - 1);
        quickSort(s, partitionIndex + 1, high);
    }
}

void main()
{
    int i = 0, n;
    char lastName[50];
    FILE *fp;

    printf("Student details from unsorted file:\n\n");
    fp = fopen("unsorted.txt", "r");
    
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %f %d", student[i].name, lastName, &student[i].height, &student[i].weight);
        strcat(student[i].name, " ");
        strcat(student[i].name, lastName);
        printf("Name: %s\tHeight: %.1f\tWeight: %d\n", student[i].name, student[i].height, student[i].weight);
        i++;
    }
    n = i;
    fclose(fp);

    quickSort(student, 0, n - 1);

    fp = fopen("sorted.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%s %.1f %d\n", student[i].name, student[i].height, student[i].weight);
    // fwrite (&student[i], sizeof (student[i]), 1, fp);
    fclose(fp);

    printf("\nStudent details from sorted file:\n\n");
    fp = fopen("sorted.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s %s %f %d", student[i].name, lastName, &student[i].height, &student[i].weight);
        // fread (&student[i], sizeof (student[i]), 1, fp);
        printf("Name: %s %s\tHeight: %.1f\tWeight: %d\n", student[i].name, lastName, student[i].height, student[i].weight);
    }
    fclose(fp);
}