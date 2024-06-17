/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:38:27 by andre-da          #+#    #+#             */
/*   Updated: 2023/10/18 14:50:56 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwords(const char	*str, char c);
static void	*ft_putstring(const char	*str, char c, char **tstr);
static void	ft_giveword(const char	*str, char	*lstr, char c);
static int	ft_alloc_free(char **tstr, int f, int j);

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * (ft_cwords(s, c) + 1));
	if (str == NULL)
		return (NULL);
	if (!ft_putstring(s, c, str))
		return (NULL);
	return (str);
}

static int	ft_cwords(const char	*str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

static int	ft_alloc_free(char **tstr, int f, int j)
{
	tstr[f] = (char *)malloc(j + 1);
	if (tstr[f] == NULL)
	{
		while (f >= 0)
		{
			free(tstr[f]);
			f--;
		}
		free (tstr);
		return (1);
	}
	return (0);
}

static void	ft_giveword(const char *str, char *lstr, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		lstr[i] = str[i];
		i++;
	}
	lstr[i] = '\0';
}

static void	*ft_putstring(const char *str, char c, char **tstr)
{
	int		i;
	int		j;
	int		f;
	int		error;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			error = ft_alloc_free(tstr, f, j);
			if (error)
				return (NULL);
			ft_giveword(str + i, tstr[f++], c);
			i += j;
		}
	}
	tstr[f] = NULL;
	return (tstr);
}

/* int	main(void)
{
	int		i = 0;
	char	string[] = "   Hello   d  world !";
	char	**strings;

	strings = ft_split(string, ' ');
	while (strings[i])
	{
		printf("%s\n", strings[i]);
		i++;
	}
	return (0);
} */
