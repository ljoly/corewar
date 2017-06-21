/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:22:12 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/04 15:53:09 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] != c)
		count = 1;
	while (str[i + 1] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			count += 1;
		i++;
	}
	return (count);
}
