/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:58:12 by hichokri          #+#    #+#             */
/*   Updated: 2024/07/22 06:20:38 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

env_store	*env_node(char *key, char *value)
{
	env_store	*env_node;

	env_node = (env_store *)malloc(sizeof(env_store));
	if (!env_node)
		return (NULL);
	env_node->key = key;
	env_node->value = value;
	env_node->next = NULL;
	return (env_node);
}

void	env_var_add(char **envp, int i, env_store **head)
{
	char		*key;
	char		*value;
	char		*path;
	env_store	*new_node;
	env_store	*tmp;

	tmp = *head;
	path = ft_strchr(envp[i], '=');
	if (path)
	{
		key = ft_substr(envp[i], 0, path - envp[i]);
		value = ft_strdup(path + 1);
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
			{
				new_node = env_node(key, NULL);
				free(value);
			}
			tmp = tmp->next;
		}
		new_node = env_node(key, value);
	}
	else
		new_node = env_node(ft_strdup(envp[i]), NULL);
}
