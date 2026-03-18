/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:47 by arakotot          #+#    #+#             */
/*   Updated: 2026/02/24 09:42:41 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_put_ptr_rec(unsigned long long n)
{
	if (n >= 16)
		ft_put_ptr_rec(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	ft_putptr(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	ft_put_ptr_rec(n);
	len += ft_ptr_len(n);
	return (len);
}
