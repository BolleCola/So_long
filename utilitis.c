#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*s2;

	s2 = (char *)s;
	while (n > 0)
	{
		*s2 = 0;
		s2++;
		n--;
	}
}

void	*ft_calloc_two(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	resul;

	resul = 0;
	while (str[resul])
		resul++;
	return (resul);
}
