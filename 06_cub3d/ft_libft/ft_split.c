/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:31:19 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/11 00:02:30 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_words_counter(const char *s, char c)
{
	unsigned int counter;
	unsigned int i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static void		*free_array(char **w_a, unsigned int current_word)
{
	unsigned int j;

	j = 0;
	while (j < current_word)
	{
		free(w_a[j]);
		w_a[j++] = NULL;
	}
	return (NULL);
}

static char		**fill_dar(char **w_a, char const *s, char c, unsigned int w_c)
{
	unsigned int symb_counter;
	unsigned int i;

	symb_counter = 0;
	i = 0;
	while (w_c > 1)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			if (*s != '\0')
				symb_counter += 1;
			if (!(w_a[i] = (char*)malloc(symb_counter + 1)))
				return (free_array(w_a, i));
			ft_strlcpy(w_a[i++], s - symb_counter + 1, symb_counter + 1);
			symb_counter = 0;
			w_c -= 1;
		}
		else if (*s != c && *(s + 1) != c)
			symb_counter += 1;
		s++;
	}
	return (w_a);
}

char			**ft_split(char const *s, char c)
{
	char			**words_array;
	unsigned int	counter;

	if (!s)
		return (NULL);
	counter = ft_words_counter(s, c);
	if (!(words_array = (char**)malloc(sizeof(char*) * (counter + 1))))
		return (NULL);
	if (!(fill_dar(words_array, s, c, counter + 1)))
	{
		free(words_array);
		words_array = NULL;
	}
	else
		words_array[counter] = NULL;
	return (words_array);
}
