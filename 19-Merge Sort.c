#include<stdio.h>
#include<string.h>

struct Student
{
  char name[50];
  float height;
  int weight;
}s[10];

void mergeSort (struct Student x[], int n)
{
  struct Student aux[n];
  int i, j, k, l1, l2, size, u1, u2;
  size = 1;

  while (size < n)
  {
    l1 = 0;
    k = 0;
    while (l1 + size < n)
    {
      l2 = l1 + size;
      u1 = l2 - 1;
      u2 = (l2+size-1 < n) ? (l2+size-1) : n-1;

      for (i = l1, j = l2; i <= u1 && j <= u2; k++)
      {
        if (x[i].height <= x[j].height)
          aux[k] = x[i++];
        else
          aux[k] = x[j++];
      }
      while (i <= u1)
      {
        aux[k++] = x[i++];
      }
      for (; j <= u2; k++)
        aux[k] = x[j++];
      l1 = u2 + 1;
    }

    for (i = l1; k < n; i++)
      aux[k++] = x[i];
    for (i = 0; i < n; i++)
      x[i] = aux[i];
    size *= 2;
  }
}

void main ()
{
  int i = 0, n;
  FILE *fp;

  printf ("Student details from unsorted file:\n\n");
  fp = fopen ("unsorted.txt", "r");
  char b[50];

  while (!feof (fp))
  {
    fscanf (fp, "%s %s %f %d", s[i].name, b, &s[i].height, &s[i].weight);
    strcat (s[i].name, " ");
    strcat (s[i].name, b);
    printf ("Name: %s\tHeight: %.1f\tWeight: %d\n", s[i].name, s[i].height, s[i].weight);
    i++;
  }
  n = i;
  fclose (fp);

  mergeSort (s, n);

  fp = fopen ("sorted.txt", "w");
  for (i = 0; i < n; i++)
    fprintf(fp, "%s %.1f %d\n", s[i].name, s[i].height, s[i].weight);
    // fwrite (&s[i], sizeof (s[i]), 1, fp);
  fclose (fp);

  printf ("\nStudent details from sorted file:\n\n");
  fp = fopen ("sorted.txt", "r");
  for (i = 0; i < n; i++)
  {
    fscanf (fp, "%s %s %f %d", s[i].name, b, &s[i].height, &s[i].weight);
    // fread (&s[i], sizeof (s[i]), 1, fp);
    printf ("Name: %s %s\tHeight: %.1f\tWeight: %d\n", s[i].name, b, s[i].height, s[i].weight);
  }
  fclose (fp);
}