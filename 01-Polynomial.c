//Polynomial addition

#include <stdio.h>
#define size 100

struct polynomial
{
  int coef, exp;
}term[size], temp;

int readPoly(int n)
{
  static int x=-1;
  for(int k=0;k<n;k++)
  {
    x++;
    scanf("%d %d", &term[x].coef, &term[x].exp);
  }

  return x;
}

void sort(int first, int last)
{
  for(int i=first; i<last; i++)
    for(int j=first+1; j<=last; j++)
      if(term[j].exp>term[j-1].exp)
      {
        temp=term[j];
        term[j]=term[j-1];
        term[j-1]=temp;
      }
}

void displayPoly(int first, int last)
{
  for(int i=first; i<last; i++)
    printf("%dx^%d + ",term[i].coef,term[i].exp);
  printf("%dx^%d\n",term[last].coef,term[last].exp);
}

int addPoly(int af, int al, int bf, int bl, int cf)
{ 
  int p, q, sum, cl, free;
  p=af;
  q=bf;
  free=cf;
  while((p<=al) && (q<=bl))
  {
    sum=0;
    if(term[p].exp==term[q].exp)
    {
      sum=term[p].coef+term[q].coef;
      if(sum!=0)
        free=newterm(sum, term[p].exp, free);
      p++;
      q++;
    }
    
    else if(term[p].exp<term[q].exp)
    {
      free=newterm(term[q].coef, term[q].exp, free);
      q++;
    }

    else if(term[p].exp>term[q].exp)
    {
      free=newterm(term[p].coef, term[p].exp, free);
      p++; 
    }

  }

  if(p<=al)
  {
    free=newterm(term[p].coef, term[p].exp, free);
    p++;
  }

  if(q<=bl)
  {
    free=newterm(term[q].coef, term[q].exp, free);
  }

  cl=free-1;
  return cl;
}

int newterm(int coef, int exp, int free)
{ 
  if(free>=size)
  printf("Array overflow");
  else
  { 
    term[free].coef=coef;
    term[free].exp=exp;
    free++;
  } 
  return free;
}

void main()
{
  int af=0, al, bf, bl, cf, cl, n1, n2;

  printf("Enter the number of terms in first polynomial\n");
  scanf("%d", &n1);
  printf("\nEnter the first polynomial\n");
  al=readPoly(n1);
  bf=al+1;
  sort(af, al);

  printf("\nEnter the number of terms in second polynomial\n");
  scanf("%d", &n2);
  printf("\nEnter the second polynomial\n");
  bl=readPoly(n2);
  cf=bl+1;
  sort(bf, bl);

  cl=addPoly(af, al, bf, bl, cf);
  sort(cf, cl);

  printf("\nFirst polynomial:\n");
  displayPoly(af, al);

  printf("\nSecond polynomial:\n");
  displayPoly(bf, bl);

  printf("\nSum of the two polynomials:\n");
  displayPoly(cf, cl);
}