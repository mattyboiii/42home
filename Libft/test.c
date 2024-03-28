int main(void)
{
	t_list *start_of_list;

	start_of_list = ft_lstnew(& (int)10);

	int i = 10
	while (i-- != 0)
	{
		t_list newlst = ft_lstnew(&i)
		ft_lstadd_front(&start_of_list, newlst)
		start_of_list == address of the start of the list

	}


	ft_prntlst(t_list *start_of_list)
	{
		t_list *iterator;

		iterator = start_of_list;
		while (iterator->next != NULL)
		{
			printf("%d", iterator->content);
			iterator = iterator->next;
		}
		printf("%d", iterator->content);
	}
}
