/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ltoabase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 19:55:17 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 20:03:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count_digit(t_uintmax nbr, int base)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

char			*ft_ltoabase(t_uintmax nbr, const char *base)
{
	int		base_len;
	char	*itoa_str;
	int		nbr_char;

	if (nbr == 0)
		return (ft_strsub(base, 0, 1));
	base_len = ft_strlen(base);
	nbr_char = count_digit(nbr, base_len);
	itoa_str = malloc(sizeof(char) * (nbr_char + 1));
	itoa_str = (char*)ft_memset((void*)itoa_str, '\0', (size_t)nbr_char);
	itoa_str[nbr_char--] = '\0';
	while (nbr)
	{
		itoa_str[nbr_char--] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (itoa_str);
}
