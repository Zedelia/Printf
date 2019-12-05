/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_bases.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:56:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:00:31 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_base_int_to_hex(unsigned int var)
{
	unsigned int		tmp;
	char				*hex;

	hex = "0123456789ABCDEF";
	if (var > 16)
		convert_base_int_to_hex(var / 16);
	tmp = var % 16;
	return (hex);
}

size_t		ft_unbrlen(unsigned long long nbr)
{
	unsigned long long	dividor;
	int					len;

	dividor = ULONG_MAX - 8446744073709551615;
	if (nbr / dividor)
		return (20);
	else if (nbr == 0)
		return (1);
	len = 0;
	dividor = 1;
	while (nbr / dividor)
	{
		len++;
		dividor *= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int nbr)
{
	char	*return_str;
	int		len;

	len = ft_unbrlen(nbr);
	if (!(return_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return_str[len--] = '\0';
	while (len >= 0)
	{
		return_str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (return_str);
}
