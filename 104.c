/*
** 104.c for 104 in /home/pliso_c/Projets/104intersection
** 
** Made by Christian  Pliso
** Login   <pliso_c@epitech.net>
** 
** Started on  Fri Jan 16 00:28:44 2015 Christian  Pliso
** Last update Fri Jan 16 18:12:24 2015 Christian  Pliso
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void		affiche(double a, double b, double delta, char **av)
{
  double	x1;
  double	x2;

  if (delta < 0)
    printf("Nombre de points d'intersections : 0\n");
  if (delta == 0)
    {
      printf("Nombre de points d'intersections : 1\n");
      printf("Point d'intersection : (%.3f, %.3f, %.3f)\n", (-b / 2 * a), (-b /	2 * a), atof(av[4]));
    }
  if (delta > 0)
    {
      printf("Nombre de points d'intersections : 2\n");
      x1 = (-b - sqrt(delta)) / (2 * a);
      x2 = (-b + sqrt(delta)) / (2 * a);
      aff_point(x1, x2, av);
    }
}

int		sphere(char **av)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) + pow(atof(av[7]), 2);
  b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6])) + (2 * atof(av[4]) * atof(av[7]));
  c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2) + pow(atof(av[4]), 2)) - pow(atof(av[8]), 2);
  delta = b * b - 4 * a * c;
  affiche(a, b, delta, av);
}

int		cylindre(char **av)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  
  a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2);
  b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6]));
  c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2)) - pow(atof(av[8]), 2);
  delta = b * b - 4 * a * c;
  affiche(a, b, delta, av);
}

int		cone(char **av)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	angle;
  
  angle = (atof(av[8]) * M_PI) / 180;
  a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) - (pow(atof(av[7]), 2) / pow(tan(angle), 2));
  b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6])) - (2 * atof(av[4]) * atof(av[7]) / pow(tan(angle), 2));
  c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) - pow(atof(av[4]), 2) / pow(tan(angle), 2);
  delta = b * b - 4 * a * c;
  affiche(a, b, delta, av);
}

void		aff_point(double x1, double x2, char **av)
{
  double	xp1;
  double	yp1;
  double	zp1;
  double	xp2;
  double	yp2;
  double	zp2;

  xp1 = atof(av[2]) + x1 * atof(av[5]);
  yp1 = atof(av[3]) + x1 * atof(av[6]);
  zp1 = atof(av[4]) + x1 * atof(av[7]);
  xp2 = atof(av[2]) + x2 * atof(av[5]);
  yp2 = atof(av[3]) + x2 * atof(av[6]);
  zp2 = atof(av[4]) + x2 * atof(av[7]);
  printf("Point 1 : (%.3f, %.3f, %.3f)\n", xp1, yp1, zp1);
  printf("Point 2 : (%.3f, %.3f, %.3f)\n", xp2, yp2, zp2);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    {
      printf("%s", "Error, try to put an argue ;) \n");
      return (0);
    }
  if (av[1][0] > '3' || av[1][1] > '0')
    {
      printf("%s", "Your first argument is invalid\n");
      return (0);
    }
  if (av[1][0] == '1' && ac == 9)
    {
      printf("sphère de rayon '%s'\n", av[8]);
      printf("droite passant par le point (%s,%s,%s), de vecteur directeur (%s,%s,%s)\n", av[2], av[3], av[4], av[5], av[6], av[7]);
      sphere(av);
    }
  if (av[1][0] == '2' && ac == 9)
    {
      printf("cylindre de rayon '%s'\n", av[8]);
      printf("droite passant par le point (%s,%s,%s), de vecteur directeur (%s,%s,%s)\n", av[2], av[3], av[4], av[5], av[6], av[7]);
      cylindre(av);
    }
  if (av[1][0] == '3' && ac == 9)
    {
      printf("cône d'angle '%s'\n", av[8]);
      printf("droite passant par le point (%s,%s,%s), de vecteur directeur (%s,%s,%s)\n", av[2], av[3], av[4], av[5], av[6], av[7]);
      cone(av);
    }
  return (0);
}
