/** #ifndef _SHELL_H_
#define _SHELL_H_
*/

/**###### environ var ######*/

/**extern char **environ; */

/**##### MACROS ######

//#define BUFSIZE 1024 
//#define DELIM " \t\r\n\a" 
//#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))
*/

/**###### LIBS USED ######

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
*/




/**###### STRING FUNCTION ######

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);  
*/

/**###### MEMORIE  MANGMENT ####

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
*/

/**###### INPUT Function ######

void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);
*/
/** ###### Command parser and extractor ###

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
*/

/** ####BUL FUNC #####

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);
*/

/** ####error handle and Printer ####
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);
*/


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */
/**
typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif

*/



#ifndef _SHELL_H_
#define _SHELL_H_

/* ############################## INCLUDE SECTION ###################################### */
#include <stdio.h>  /*  printf(), fgets() */
#include <string.h> /*  strtok(), strcmp(), strdup() */
#include <stdlib.h> /*  free() */
#include <unistd.h> /*  fork() */
#include <sys/types.h>
#include <sys/wait.h> /*  waitpid() */
#include <sys/stat.h>
#include <fcntl.h> /*  open(), creat(), close() */
#include <time.h>
#include <errno.h>

/*  ############################## DEFINE SECTION ######################################## */
#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 64
#define REDIR_SIZE 2
#define PIPE_SIZE 3
#define MAX_HISTORY_SIZE 128
#define MAX_COMMAND_NAME_LENGTH 128

#define PROMPT_FORMAT "%F %T "
#define PROMPT_MAX_LENGTH 30

#define TOFILE_DIRECT ">"
#define APPEND_TOFILE_DIRECT ">>"
#define FROMFILE "<"
#define PIPE_OPT "|"

/* ################## functions ########################################################## */
void init_shell() ;
char *get_current_dir();
char *prompt();
void error_alert(char *msg);
void remove_end_of_line(char *line);
void read_line(char *line) ;
void parse_command(char *input_string, char **argv, int *wait);

/* ###### the redirectioin the functions */
int is_redirect(char **argv) ;
int is_pipe(char **argv);
void parse_redirect(char **argv, char **redirect_argv, int redirect_index);
void parse_pipe(char **argv, char **child01_argv, char **child02_argv, int pipe_index);

/* ## executions functions */
void exec_child(char **argv);
void exec_child_overwrite_from_file(char **argv, char **dir);
void exec_child_overwrite_to_file(char **argv, char **dir);
void exec_child_append_to_file(char **argv, char **dir) ;
void exec_child_pipe(char **argv_in, char **argv_out);
void exec_parent(pid_t child_pid, int *bg);

/* ###### environment function ,execv, history etc..... */
void set_prev_command(char *history, char *line);
char *get_prev_command(char *history) ;
int simple_shell_cd(char **args);
int simple_shell_help(char **args);
int simple_shell_exit(char **args);
void exec_command(char **args, char **redir_argv, int wait, int res);
int simple_shell_history(char *history, char **redir_args);
int simple_shell_redirect(char **args, char **redir_argv) ;
int simple_shell_pipe(char **args);
void exec_command(char **args, char **redir_argv, int wait, int res);


#endif