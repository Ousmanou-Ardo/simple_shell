#include "shell.h"
/**
 * _getline - function that used to read a string or a line
 * Return: 0
 */
/**
int _getline(void)
{
	char *string;
	size_t size;
	ssize_t bytes_read = 0;
	int i;

	string = (char *)malloc(size);
	if (bytes_read == -1)
	{
		puts("hsh");
	}
	else
		for (i = 0; i < 1; i++)
		{
			printf("$ ");
			bytes_read = getline(&string, &size, stdin);
		}
	return (0);
}
*/
/**
 * _strtok - function that used to read a string or a line
 * Return: 0
 */
/**
int _strtok(void)
{
	char *str = " ";
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
/**
 * _fork - creating a new process
 *Return: void
 */
/**
void _fork(void)
{
	char *argv[] = {"/bin/ls", "-l", ".", NULL};

	pid_t pid = fork();

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(NULL);
	}
}
*/
/**
 * sig_handler - checks if Ctrl C is pressed by the input
 * @signum: int
 *Return: void
 */
/**
void sig_handler(int signum)
{

	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
*/
/**
 *main - main function
 *Return: Always(0)
 */
/**
int main(void)
{
	int st = 1;

	signal(SIGINT, sig_handler);
	while (st)
	{
		_getline();
		_strtok();
		_fork();
	}
	return (0);
}
*/

/* ############################## GLOBAL VARIABLES SECTION ############################## */
int running = 1;
/**
 * @description the main :))
 * @param void return nothing
 * @return 0 if success
 */
int main(void) {
    /*  agrs */
    char *args[BUFFER_SIZE];

    /*  line */
    char line[MAX_LINE_LENGTH];

    /* line */
    char t_line[MAX_LINE_LENGTH];

    /* history func */
    char history[MAX_LINE_LENGTH] = "No commands in history";

    /*  redirecting */
    char *redir_argv[REDIR_SIZE];

    /* Check the child */
    int wait;

    /* banner shell */
    init_shell();
    int res = 0;

    /* running */
    while (running) {
        printf("%s:%s> ", prompt(), get_current_dir());
        fflush(stdout);

        /* reading */
        read_line(line);

        /* copy string */
        strcpy(t_line, line);

        /* Parsering input */
        parse_command(line, args, &wait);

        /* comparing */
        if (strcmp(args[0], "!!") == 0) {
            res = simple_shell_history(history, redir_argv);
        } else {
            set_prev_command(history, t_line);
            exec_command(args, redir_argv, wait, res);
        }
        res = 0;
    }
    return 0;
}

