# Libft
First 19 school project wich consist of a personnal library of functions recreated by hands
char	*ft_strtrim(char const *s1, char const *set) {
	unsigned int	start;
	char			*trim;
	size_t 			end;

	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_is_set(s1[end], set))
	{
		end--;
	}
	trim = ft_substr(s1, start, end - start + 1);
	if (!trim)
		return (0);
	return (trim);
}

str trim a modif

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	res = malloc(count * size);
	if (!res || (count >= 65535 || size >= 65535))
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

calloc a modif

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmap;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	strmap = ft_strdup(s);
	if (!strmap)
		return (0);
	while (strmap[i])
	{
		strmap[i] = f(i, strmap[i]);
		i++;
	}
	return (strmap);
}

mapi a modif

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mem;

	while (lst && (*lst))
	{
		if ((*lst)->next)
			mem = (*lst)->next;
		else
			mem = 0;
		ft_lstdelone(*lst, del);
		(*lst) = mem;
	}
	(*lst) = 0;
}

lst clear a modif

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}

a modif ?



