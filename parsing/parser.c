/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:11:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/02 08:14:53 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



int ft_parser(char *input)
{
    char **split_input;
    // t_link *link;

    split_input = ft_lexer(input);


    // link = ft_def_type(split_input);
    int i = 0;
    while (split_input[i])
    {
        printf("%s\n", split_input[i]);
        i++;
    }
    ft_free(split_input);
    // // if (!ft_ch)
    // if (!ft_check_command(link))
    //     return (0); 
    return (1);
}