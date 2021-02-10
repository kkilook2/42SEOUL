/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:54:28 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 17:45:29 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flag)
{
    flag->minus = 0;
    flag->dot = 0;
    flag->prec = 0;
    flag->width = 0;
    flag->zero = 0;
}

char	*ft_format_parse(const char **format, va_list ap)
{
	char	*ret;
	
	ret = 0;
	if (**format == 'c')
		ret = ft_get_char(va_arg(ap, int));
	else if (**format == '%')
		ret = ft_get_char('%');
	else if (**format == 's')
		ret = ft_get_string(va_arg(ap, char*));
	else if (**format == 'u')
		ret = ft_get_integer(format, va_arg(ap, unsigned int));
	else if (**format == 'd' || **format == 'i')
		ret = ft_get_integer(format, va_arg(ap, int));
	else if (**format == 'x' || **format == 'X')
		ret = ft_get_hexa(format, va_arg(ap, unsigned int));
	else if (**format == 'p')
		ret = ft_get_pointer(va_arg(ap, unsigned long long));
		
	return ret;
}

void     ft_flag_parse(const char **format, t_flags *flag, va_list ap)
{
    while (!check_format(format))
    {
		if (**format == '0')
			flag->zero = 1;		
		else if (**format =='-')
			flag->minus = 1;
		else if (!(flag->dot) && (**format == '*' || ft_isdigit(**format)))
			flag->width = ft_treat_width(format, ap, flag);
		else if (**format == '.')
		{
			flag->dot = 1;
			flag->prec = ft_treat_prec(format, ap);
		}
		else if (!(ft_strchr(".-0*", **format)))
			ft_putchar_fd(**format, 1);
        (*format)++;
    }
}

int     ft_treat_format(const char *format, va_list ap, int len)
{
    char	*form_str;
	t_flags	*flag;
	
	flag = malloc(sizeof(t_flags));
	ft_init_flags(flag);
    while (*format)
    {
    	if (*format == '%')
        {
			format++;
     		ft_flag_parse(&format, flag, ap);
			form_str = ft_format_parse(&format, ap);
			len += ft_format_print(&format, form_str, flag, len);
			ft_init_flags(flag);
        }
        else //format != % 
        {
            ft_putchar_fd(*format, 1);
            len++;
        }
        format++;
    }
	free(flag);
    return (len);
}

int     ft_printf(const char *input, ...)
{
	va_list     ap;
    const char  *format;
    int         len;

    len = 0;
    format = ft_strdup(input);
    va_start(ap, input);
    if (*format)
        len += ft_treat_format(format, ap, len);
    va_end(ap);
    free((char *)format);
    return (len);
}  

// int	main(void)
// {
// 	// printf(", size: %d\n", printf("%*.*d", -4, 0, 8));
// 	// printf(", size: %d\n", ft_printf("%*.*d", -4, 0, 8));
// 	printf("%u\n", 4294967284);
// 	ft_printf("%u", 4294967284);

// 	printf("\n%s\n", ft_itoa(4294967284));
// 	ft_printf("%s", ft_itoa(4294967284));

// }
	
// 	// c
// 	printf("========== type c ==========\n");
// 	printf(", size: %d\n", printf("%*.5c",10,'a'));
// 	printf(", size: %d\n", ft_printf("%*.5c",10, 'a'));
	
// 	printf(", size: %d\n", printf("%-10c",'a'));
// 	printf(", size: %d\n", ft_printf("%-10c",'a'));
	
// 	printf(", size: %d\n", printf("%0.*c", 5,'a'));
// 	printf(", size: %d\n", ft_printf("%0.5c",'a'));
	
// 	// s
// 	printf("========== type s ==========\n");
// 	printf(", size: %d\n", printf("%s", ""));
// 	printf(", size: %d\n", ft_printf("%s", ""));
// 	printf(", size: %d\n", printf("hello %-5.4s world %4s%%", "abcde", "fg"));
// 	printf(", size: %d\n", ft_printf("hello %-*.4s world %4s%%",5, "abcde", "fg"));
// 	printf(", size: %d\n", printf("%5.7s", "abcd"));
// 	printf(", size: %d\n", ft_printf("%*.*s",5, 7,"abcd"));

// // 	// //p
// // 	// printf("========== type p ==========\n");
// // 	// printf(", size: %d\n", printf("%p", 0x101132f47));
// // 	// printf(", size: %d\n", ft_printf("%p", 0x101132f47));

// 	// d
// 	printf("========== type d ==========\n");
// 	printf(", size: %d\n", printf("%.*d", -4,0));
// 	printf(", size: %d\n", ft_printf("%.*d",-4, 0));

// 	printf(", size: %d\n", printf("%0.0d",0));
// 	printf(", size: %d\n", ft_printf("%0.0d", 0));

// 	printf(", size: %d\n", printf("%-0.0d", 0));
// 	printf(", size: %d\n", ft_printf("%-0.0d", 0));

// 	printf(", size: %d\n", printf("%d", 0));
// 	printf(", size: %d\n", ft_printf("%d", 0));

// 	printf(", size: %d\n", printf("%0d", 234));
// 	printf(", size: %d\n", ft_printf("%0d", 234));

// 	printf(", size: %d\n", printf("%3.0d",234));
// 	printf(", size: %d\n", ft_printf("%3.0d", 234));
	
// 	printf(", size: %d\n", printf("%0.0d", 234));
// 	printf(", size: %d\n", ft_printf("%0.0d", 234));
// 	printf(", size: %d\n", printf("%07d", 234));
// 	printf(", size: %d\n", ft_printf("%07d", 234));
// 	printf(", size: %d\n", printf("%-07d", 23456));
// 	printf(", size: %d\n", ft_printf("%-07d", 23456));


// 	//mid test
// 	printf("========== mid test ==========\n");
// 	printf(", size: %d\n", printf("Hello %4.3c world %5.4s is %0d", 'a', "python", 444));
// 	printf(", size: %d\n", ft_printf("Hello %4.3c world %5.4s is %0d", 'a', "python", 444));


// 	// i
// 	printf("========== type i ==========\n");
// 	printf(", size: %d\n", printf("%i", 23452));
// 	printf(", size: %d\n", ft_printf("%i", 23452));

// // 	// // u
// // 	// printf("========== type u ==========\n");
// // 	// printf(", size: %d\n", printf("%u", 23452));
// // 	// printf(", size: %d\n", ft_printf("%u", 23452));

// 	// x
// 	printf("========== type x ==========\n");
// 	printf(", size: %d\n", printf("%x", 113801));
// 	printf(", size: %d\n", ft_printf("%x", 113801));
	
// 	// X
// 	printf("========== type X ==========\n");
// 	printf(", size: %d\n", printf("hello world %X to %x", 113801, 113801));
// 	printf(", size: %d\n", ft_printf("hello world %X to %x", 113801, 113801));


// 	// // %
// 	// printf("========== type %% ==========\n");
// 	// printf(", size: %d\n", printf("%%"));
// 	// printf(", size: %d\n", ft_printf("%%"));
	
// 	return (0);
// }
