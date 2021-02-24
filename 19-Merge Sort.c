#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    float height;
    int weight;
} student[10];

void mergeSort(struct Student s[], int n)
{
    struct Student aux[n];

    // i - index for first set, j - index for second set, k - index for auxiliary array
    // l1, l2 - lower bounds of first and second set, u1, u2 - upper bounds of first and second set
    // size - size of auxiliary array (multiples of 2)
    int i, j, k, l1, l2, u1, u2, size;
    size = 1;

    while (size < n)
    {
        l1 = 0;
        k = 0;
        
        while (l1 + size < n)
        {
            l2 = l1 + size;
            u1 = l2 - 1;

            if (l2 + size - 1 < n)  
                u2 = l2 + size - 1;
            else // if another set is not possible, set upper bound of second set to last index n - 1
                u2 = n - 1;

            for (i = l1, j = l2; i <= u1 && j <= u2; k++)
            {
                if (s[i].height <= s[j].height) // copy smaller element to auxiliary array
                    aux[k] = s[i++];
                else
                    aux[k] = s[j++];
            }

            while (i <= u1) // second set is over and first isn't
                aux[k++] = s[i++];

            while (j <= u2) // first set is over and second isn't
                aux[k++] = s[j++]; 

            l1 = u2 + 1; // set lower bound of next first set to u2 + 1 
        }

        for (i = l1; k < n; i++) //copy elements not included in any set to auxiliary array
            aux[k++] = s[i];

        for (i = 0; i < n; i++) // copy auxiliary array to main array
            s[i] = aux[i];

        size *= 2; //update to next size of set
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

    mergeSort(student, n);

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