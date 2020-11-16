#include<stdio.h>
#include<string.h>

struct Student
{
  char name[50];
  float height;
  int weight;
}s[10];


void quickSort (struct Student n[], int l, int f)
{
  int i, j, pivot;
  char temp[50];
  float nh;
  int nw;
  struct Student t;

  if (l < f)
  {
    pivot = l;
    i = l;
    j = f;

    while (i < j)
  	{
  	  while ((strcmp (n[i].name, n[pivot].name))<0 && i<=f)
  	    i++;

  	  while ((strcmp (n[j].name, n[pivot].name))>0 && j>=l)
  	    j--;

  	  if (i < j)
  	    {
  	      t = n[i];
  	      n[i] = n[j];
  	      n[j] = t;
  	    }
  	}

    t = n[pivot];
    n[pivot] = n[j];
    n[j] = t;


    quickSort (n, l, j-1);
    quickSort (n, j+1, f);
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

  quickSort (s, 0, n-1);

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