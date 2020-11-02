#include <stdio.h>
#include<stdlib.h>

struct poly
{
  int exp;
  int coef;
  struct poly *next;
};
typedef struct poly node;
node *a = NULL, *b = NULL, *cc = NULL;
void
create (int i, int co, int ex, int w)
{
  node *k, *c;
  k = (node *) malloc (sizeof (node));
  k->coef = co;
  k->exp = ex;
  k->next = NULL;
  if (w == 1)
    {
      if (i == 0)
  {
    a = k;
  }
      else
  {
    c = a;
    while (c->next != NULL)
      {
        c = c->next;
      }
    c->next = k;
  }
    }
  else
    {
      if (i == 0)
  {
    b = k;
  }
      else
  {
    c = b;
    while (c->next != NULL)
      {
        c = c->next;
      }
    c->next = k;
  }
    }

}

void
sort (int i)
{
  node *h, *t1, *t2;
  switch (i)
    {
    case 1:
      h = a;
      break;
    case 2:
      h = b;
      break;
    }
  for (t1 = h; t1->next != NULL; t1 = t1->next)
    {
      for (t2 = t1->next; t2 != NULL; t2 = t2->next)
  {
    if (t2->exp > t1->exp)
      {
        int k;
        k = t1->exp;
        t1->exp = t2->exp;
        t2->exp = k;
        k = t1->coef;
        t1->coef = t2->coef;
        t2->coef = k;
      }
  }
    }
}

void
add ()
{
  node *c, *p, *q, *d;
  p = a;
  q = b;
  c = (node *) malloc (sizeof (node));
  d = c;
  while (p != NULL && q != NULL)
    {
      node *k = (node *) malloc (sizeof (node));
      if (p->exp > q->exp)
  {
    k->coef = p->coef;
    k->exp = p->exp;
    k->next = NULL;
    d->next = k;
    d = d->next;
    p = p->next;
  }
      else if (p->exp < q->exp)
  {
    k->coef = q->coef;
    k->exp = q->exp;
    k->next = NULL;
    d->next = k;
    d = d->next;
    q = q->next;
  }
      else
  {
    int u = 0;
    u = p->coef + q->coef;
    if (u != 0)
      {
        k->coef = u;
        k->exp = p->exp;
        k->next = NULL;
        d->next = k;
        d = d->next;
      }
    p = p->next;
    q = q->next;
  }
    }
  while (p != NULL)
    {
      node *k = (node *) malloc (sizeof (node));
      k->coef = p->coef;
      k->exp = p->exp;
      k->next = NULL;
      d->next = k;
      d = d->next;
      p = p->next;
    }
  while (q != NULL)
    {
      node *k = (node *) malloc (sizeof (node));
      k->coef = q->coef;
      k->exp = q->exp;
      k->next = NULL;
      d->next = k;
      d = d->next;
      q = q->next;
    }
  d->next = NULL;
  cc = c->next;
}

void
display (int i)
{
  node *k;
  if (i == 1)
    {
      k = a;
    }
  else if (i == 2)
    {
      k = b;
    }
  else
    k = cc;
  while (k->next != NULL)
    {
      if (k->coef != 0)
  printf ("%ix^%i + ", k->coef, k->exp);
      k = k->next;
    }
    if (k->coef != 0)
      printf ("%ix^%i", k->coef, k->exp);
  printf ("\n");
}

void
main ()
{
  node *k;
  int n, n2, ex, co;
  printf ("Enter the number of terms in first polynomial\n");
  scanf ("%i", &n);
  printf ("\nEnter the first polynomial\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%i %i", &co, &ex);
      create (i, co, ex, 1);
    }
  printf ("\nEnter the number of terms in second polynomial\n");
  scanf ("%i", &n2);
  printf ("\nEnter the second polynomial\n");
  for (int i = 0; i < n2; i++)
    {
      scanf ("%i %i", &co, &ex);
      create (i, co, ex, 2);
    }
  sort (1);
  sort (2);
  printf ("\nFirst polynomial:\n");
  display (1);
  printf ("\nSecond polynomial:\n");
  display (2);
  printf ("\nSum of the two polynomials:\n");
  add ();
  display (3);
}