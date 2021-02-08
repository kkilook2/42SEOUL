/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:54:28 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/09 03:53:46 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flag)
{
    flag->minus = 0;
    flag->dot = 0;
    flag->prec = 0;
    flag->width = 0;
    flag->star = 0;
    flag->zero = 0;
}

char	*ft_format_parse(const char **format, t_flags *flag, va_list ap)
{
	char	*ret;
	
	ret = 0;
	if (**format == 'c')
		ret = ft_get_char(va_arg(ap, int));
	else if (**format == '%')
		ret = ft_get_char('%');
	else if (**format == 's')
		ret = ft_get_string(va_arg(ap, char *));
	else if (**format == 'd' || **format == 'i')
		ret = ft_get_integer(va_arg(ap, int));
	return ret;
}

//flag 정보 저장 (0, -, width, prec)
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
			form_str = ft_format_parse(&format, flag, ap);
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

int		main(void)
{
	ft_printf("hello world %-*.*s\n",3, 4, "abcdefg");
	printf("hello world %-3.4s\n", "abcdefg");
	ft_printf("%4.3s\n", "abcdefg");
	printf("%4.3s\n", "abcdefg");
	// c
	printf("========== type c ==========\n");
	printf(", size: %d\n", printf("%*.*c",10, 5,'a'));
	printf(", size: %d\n", ft_printf("%*.5c",10, 'a'));
	
	// s
	printf("========== type s ==========\n");
	printf(", size: %d\n", printf("%5.4s", "abcde"));
	printf(", size: %d\n", ft_printf("%*.4s",5, "abcde"));

	// //p
	// printf("========== type p ==========\n");
	// printf(", size: %d\n", printf("%p", 0x101132f47));
	// printf(", size: %d\n", ft_printf("%p", 0x101132f47));

	// // d
	// printf("========== type d ==========\n");
	// printf(", size: %d\n", printf("%d", 23452));
	// printf(", size: %d\n", ft_printf("%d", 23452));

	// // i
	// printf("========== type i ==========\n");
	// printf(", size: %d\n", printf("%i", 23452));
	// printf(", size: %d\n", ft_printf("%i", 23452));

	// // u
	// printf("========== type u ==========\n");
	// printf(", size: %d\n", printf("%u", 23452));
	// printf(", size: %d\n", ft_printf("%u", 23452));

	// // x
	// printf("========== type x ==========\n");
	// printf(", size: %d\n", printf("%x", 113801));
	// printf(", size: %d\n", ft_printf("%x", 113801));
	
	// // X
	// printf("========== type X ==========\n");
	// printf(", size: %d\n", printf("%X", 113801));
	// printf(", size: %d\n", ft_printf("%X", 113801));


	// %
	printf("========== type %% ==========\n");
	printf(", size: %d\n", printf("%%"));
	printf(", size: %d\n", ft_printf("%%"));
	
	return (0);
}

/*
int main()
{
	ft_printf("%-*.*s\n",3, 4, "abcdefg");
	printf("%-3.4s\n", "abcdefg");
	ft_printf("%4.3s\n", "abcdefg");
	printf("%4.3s\n", "abcdefg");
	
	ft_printf("%*c\n", 5, 'a');
	printf("%*c\n", 5, 'a');
	ft_printf("hello %% world %5.5c\n", 'a');
	printf("hello %% world %5.5c\n", 'a');
	
	ft_printf("hello %-10.5s world\n", "hello world");
	printf("hello %-10.5s world\n", "hello world");
	
	ft_printf("%5.5d\n", 20210208 );
	printf("%5.5d\n", 20210208 );
	
	return (0);
	
	
}
*/