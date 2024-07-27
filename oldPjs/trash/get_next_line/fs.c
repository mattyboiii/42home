t_list	*find_next_line(char *buffer)
{
	size_t		nl;
	t_list		**lst;
	
	lst = NULL;
	while (*buffer)
	{
		nl = 0;
		if (*buffer == '\n')
		{
			string_into_linkedlist(lst, ft_substr(buffer,
				buffer, 1));
			buffer++;
		}
		else
		{
			while (buffer[nl] && buffer[nl] != '\n')
				nl++;
			string_into_linkedlist(lst, ft_substr(buffer,
				0, nl + 1));
			*buffer += nl;
		}
		if (ft_strchr(buffer, '\n' != 1))
			string_into_linkedlist(lst,ft_substr(buffer,
				0, nl + 1));
	}
	return (lst);
}
