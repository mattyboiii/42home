/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:48:15 by mexu              #+#    #+#             */
/*   Updated: 2024/11/27 11:14:02 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

# define PROMPT "🐚 MINISHELL:$ "
# define HEREDOC_NAME "/tmp/.minishell_heredoc_"
# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

// extern int	g_exit_code;

// --------------------------------------------typedefs
typedef struct s_token
{
	char			*str;
	bool			var_exists;
	int				type;
	int				quoting;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*hd_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
}	t_io_fds;

typedef struct s_command
{
	char				*cmd_str;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_cmd;

typedef struct s_minishell
{
	bool		interactive;
	t_token		*token;
	t_cmd		*cmd;
	char		*user_input;
	char		**env;
	pid_t		pid;
	int			last_exit_code;
}	t_minishell;

// --------------------------------------------enums
enum e_token_types
{
	EMPTY,
	SPACES,
	WORD,
	VAR,
	PIPE,
	INPUT,
	OUTPUT,
	HEREDOC,
	APPEND,
	END
};

enum e_quote_status
{
	DEFAULT,
	SQUOTE,
	DQUOTE
};

// --------------------------------------------functions
int		init_ms(t_minishell *data, char **env);
void	init_io(t_cmd *cmd);
void	exit_ms(t_minishell *data, int exno);
int		put_errmsg(char *s1, char *s2, char *s3, int err_nb);
void	clean_data(t_minishell *data);
void	close_fds(t_cmd *cmds, bool close_backups);
void	free_io(t_io_fds *io);
int		check_input(t_minishell *data);
int		create_token(t_minishell *data);
int		save_token(int *i, char *str, int start, t_minishell *data);
int		set_quote_status(int status, char *str);
int		save_word(t_token **token_lst, char *str, int index, int start);
int		save_separator(t_token **token_lst, char *str, int index, int type);
int		check_consecutives(t_token **token_lst);
int		check_if_var(t_token **token_lst);
t_token	*lst_new_token(char *str, int type, int status);
void	lst_delone_token(t_token *lst);
void	lst_clear_token(t_token **lst);
void	lst_add_back_token(t_token **lst, t_token *new);
int		handle_variable(t_minishell *data, t_token **token_lst);
char	*handle_variable_heredoc(t_minishell *data, char *str);
int		expand_var_token(t_token **token_node, char *var_value, int index);
char	*expand_var_heredoc(char *str, char *var_value, int index);
int		var_length(char *str);
char	*get_var_value(t_token *token, char *str, t_minishell *data);
char	*get_new_string(char *oldstr, char *var_value,
			int newstr_size, int index);
bool	is_quote(char c);
int		handle_quotes(t_token *token);
int		remove_quotes(t_token **token_node);
void	create_cmd(t_minishell *data, t_token *token);
void	parse_word(t_cmd **cmd, t_token **token_lst);
int		fill_args(t_token **token_node, t_cmd *last_cmd);
char	*join_vars(t_token **token_node);
int		count_args(t_token *temp, bool join_flag);
char	**copy_to_new_arr(int len, char **arr, t_cmd *last_cmd, t_token *tmp);
char	**copy_to_new_arr_join(int len, char **arr, t_cmd *last_cmd,
			t_token *tmp);
void	remove_empty_var_args(t_token **tokens);
t_cmd	*lst_new_command(bool value);
void	lst_add_back_cmd(t_cmd **lst, t_cmd *new);
t_cmd	*lst_last_cmd(t_cmd *cmd);
void	lst_delone_cmd(t_cmd *lst, void (*del)(void *));
void	lst_clear_cmd(t_cmd **lst, void (*del)(void *));
void	parse_output(t_cmd **last_cmd, t_token **token_lst);
char	*get_relative_path(char *file_to_open);
int		remove_infile_ref(t_io_fds *io);
int		remove_outfile_ref(t_io_fds *io);
void	parse_input(t_cmd **last_cmd, t_token **token_lst);
void	parse_append(t_cmd **last_cmd, t_token **token_lst);
void	parse_heredoc(t_minishell *data, t_cmd **last_cmd, t_token **token_lst);
bool	fill_heredoc(t_minishell *data, t_io_fds *io, int fd);
void	parse_pipe(t_cmd **cmd, t_token **token_lst);
int		env_var_index(char **env, char *var);
char	*env_var_value(char **env, char *var);
bool	is_valid_env_var_key(char *var);
bool	set_env_var(t_minishell *data, char *key, char *value);
bool	remove_env_var(t_minishell *data, int idx);
int		env_builtin(t_minishell *data, char **args);
int		pwd_builtin(t_minishell *data, char **args);
int		echo_builtin(t_minishell *data, char **args);
int		export_builtin(t_minishell *data, char **args);
int		unset_builtin(t_minishell *data, char **args);
int		cd_builtin(t_minishell *data, char **args);
int		exit_builtin(t_minishell *data, char **args);
// void	ignore_sigquit(void);
void	signal_in_prompt(void);
void	signal_in_execution(void);
// void	handle_signals(void);
int		execute(t_minishell *data);
int		child_process_exe(t_minishell *data, t_cmd *cmd);
int		execute_builtin(t_minishell *data, t_cmd *cmd);
bool	cmd_is_dir(char *cmd);
int		check_command_not_found(t_minishell *data, t_cmd *cmd);
char	*get_cmd_path(t_minishell *data, char *cmd);
int		create_pipes(t_minishell *data);
void	set_pipe_fds(t_cmd *cmds, t_cmd *curr_cmd);
void	close_pipe_fds(t_cmd *cmds, t_cmd *skip_cmd);
bool	is_files_set(t_io_fds *io);
void	redirect_io(t_io_fds *io);
void	restore_io(t_io_fds *io);
void	print_cmd_list(t_cmd *cmd);
void	print_token_list(t_token *lst);

#endif