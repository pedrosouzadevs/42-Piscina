#include <unistd.h>

void ft_putstr(char *str);

int main(int argc, char *argv[])
{
  int i;

  i = argc;
  while (i > 1)
  {
    ft_putstr(argv[i - 1]);
    write(1, "\n", 1);
    i--;
  }
  return (0);
}

void ft_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}
