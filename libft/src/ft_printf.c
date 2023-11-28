/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:45:14 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 09:53:08 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

static t_var	ft_start(int a)
{
	t_var	var;

	var.size = a;
	var.c = a;
	return (var);
}

/*
 * IN:
 * 		void *a = the value that we want to print
 * 		int c = a counter to move inside the string
 * 		int size = the number of character that we are printing
 * 		char const *str = The string that contains the information
 * 	OUT:
 * 		int	var.size = the number of characters the function printed
 */

static int	put(void *a, int c, int size, char const *str)
{
	if (str[c + 1] == 's')
		size += ft_putstr((char *)a);
	else if (str[c + 1] == 'c')
		size += ft_putchar((int) a);
	else if (str[c + 1] == 'i')
		size += ft_putnbr((int) a);
	else if (str[c + 1] == 'u')
		size += ft_unsigned((unsigned int) a);
	else if (str[c + 1] == 'X' || str[c + 1] == 'x')
		size += ft_hex((unsigned int) a, str[c + 1]);
	else if (str[c + 1] == 'd')
		size += ft_putnbr((int) a);
	else if (str[c + 1] == 'p')
		size += ft_voidhex(a);
	return (size);
}

/*
 * IN:
 * 		char const *str = The string that contains the information
 * 	OUT:
 * 		int	var.size = the number of characters the function printed
 */

int	ft_printf(char const *str, ...)
{
	t_var	var;

	var = ft_start(0);
	va_start(var.param, str);
	while (str[var.c])
	{
		if (str[var.c] == '%' && str[var.c + 1] != '%')
		{
			var.size = put(va_arg(var.param, void *), var.c, var.size, str);
			var.c++;
		}
		else if (str[var.c] == '%' && str[var.c++ + 1] == '%')
			var.size += ft_putchar('%');
		else
			var.size += ft_putchar(str[var.c]);
		var.c++;
	}
	va_end(var.param);
	return (var.size);
}

/*int	main()
{
	int a;
	a = ft_printf(" NULL %s NULL ", NULL);
	printf("\n%d\n", a);
	printf("Numero original: %d\n", printf(" NULL %s NULL ", NULL));	
	return (0);
}*/
