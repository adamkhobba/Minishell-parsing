/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:50:46 by akhobba           #+#    #+#             */
/*   Updated: 2024/07/25 12:37:00 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *ft_change_key(char *command, int position, env_store *env)
{
	t_link *tmp;
	char *output;
	char *value;

	value = ft_strdup(getenv_value(command + 1, env));
	if (!command)
		return (NULL);
	output = malloc(sizeof(char) * (position *
		ft_strlen(value) + ft_strlen(command + position + 1) + 1));
	if (!output)
		return (NULL);
	output = ft_strlcpy(output, command, position);
	output = ft_strlcat(output, value, position + ft_strlen(value));
	output = ft_strlcat(output, command + position + 1,
	position + ft_strlen(value) + ft_strlen(command + position + 1));
	return (0);
}

int	ft_base_expand(t_link **link, env_store *env)
{
	t_link	*tmp;
	int position;

	tmp = *link;
	position = -1;
	while (tmp)
	{
		position = ft_strchr(tmp->command, '$');
		if (position != -1)
		{
			tmp = tmp->next;
			continue;
		}
		tmp->command = ft_change_key(tmp->command, position, env);
		tmp = tmp->next;
	}
	return (0);
}