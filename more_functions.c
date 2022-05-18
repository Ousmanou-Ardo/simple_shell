/**
 * prompt - Display Shell Prompt
 */

/**
void prompt(void)
{
	PRINTER("$ ");
}
*/
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */

/**
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
*/

#include "shell.h"
/**
 *  shell
 * @param None
 * @return None
 */
void init_shell() {
    printf("**********************************************************************\n");
    printf("YOUR NEW SHELL \n");
    printf("*********************************************************************\n");
    char *username = getenv("USER");
    printf("\n\n\n WELCOME Mr/Ms %s", username);
    printf("\n");
}

char *get_current_dir() {
    char cwd[FILENAME_MAX];
    char*result = getcwd(cwd, sizeof(cwd));
    return result;
}

/**
 *  YYYY-MM-dd <space> hour:minute:second <space> default name of shell <space> >
 * @param None
 * @return a prompt string
 */
char *prompt() {
    static char *_prompt = NULL;
    time_t now;
    struct tm *tmp;
    size_t size;

    if (_prompt == NULL) {
        _prompt = malloc(PROMPT_MAX_LENGTH * sizeof(char));
        if (_prompt == NULL) {
            perror("Error: Unable to locate memory");
            exit(EXIT_FAILURE);
        }
    }

    // time
    now = time(NULL);
    if (now == -1) {
        fprintf(stderr, "Error: Cannot get current timestamp");
        exit(EXIT_FAILURE);
    }

    //timestamp
    tmp = localtime(&now);
    if (tmp == NULL) {
        fprintf(stderr, "Error: Cannot identify timestamp");
        exit(EXIT_FAILURE);
    }

    //  format YYYY-MM-dd <space> hour:minute:second <space>
    size = strftime(_prompt, PROMPT_MAX_LENGTH, PROMPT_FORMAT, tmp);
    if (size == 0) {
        fprintf(stderr, "Error: Cannot convert time to string");
        exit(EXIT_FAILURE);
    }
    // a shell
    char* username = getenv("USER");
    strncat(_prompt, username, strlen(username));
    return _prompt;
}

/**
 * hahalahalahalaha
 * @param None
 * @return None
 */
void error_alert(char *msg) {
    printf("%s %s\n", prompt(), msg);
}

/**
 * @description: description
 * @param: line 
 * @return:  '\n'
 */
void remove_end_of_line(char *line) {
    int i = 0;
    while (line[i] != '\n') {
        i++;
    }

    line[i] = '\0';
}

// Readline
/**
 * @description: descriptions
 * @param: line 
 * @return: none
 */
void read_line(char *line) {
    char *ret = fgets(line, MAX_LINE_LENGTH, stdin);

    // '\n'... '\0' - 
    remove_end_of_line(line);

    // "exit" "quit"  NULL 
    if (strcmp(line, "exit") == 0 || ret == NULL || strcmp(line, "quit") == 0) {
        exit(EXIT_SUCCESS);
    }
}

// Parser

/**
 * @description: description of the function
 * @param : input_string  ....?
 * @return: none
 */
void parse_command(char *input_string, char **argv, int *wait) {
    int i = 0;

    while (i < BUFFER_SIZE) {
        argv[i] = NULL;
        i++;
    }

    // If - else 
    *wait = (input_string[strlen(input_string) - 1] == '&') ? 0 : 1; //  wait = 0, wait = 1
    input_string[strlen(input_string) - 1] = (*wait == 0) ? input_string[strlen(input_string) - 1] = '\0' : input_string[strlen(input_string) - 1];
    i = 0;
    argv[i] = strtok(input_string, " ");

    if (argv[i] == NULL) return;

    while (argv[i] != NULL) {
        i++;
        argv[i] = strtok(NULL, " ");
    }

    argv[i] = NULL;
}