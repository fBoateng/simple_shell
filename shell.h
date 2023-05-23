#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/*  read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*  command chaining */
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3
#define CMD_NORM        0

/*  convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* 1 for using system getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0
extern char **environ;

#define HIST_MAX        4096
#define HIST_FILE       ".simple_shell_history"



/**
 * struct liststr : singly linked list
 * @num:  number field
 * @str:  string
 * @next: points to  next node
 */
typedef struct liststr
{
        char *str;
        int num;
        struct liststr *next;
} list_t;

/**
 * struct passinfo - contain pseudo-arguement to pass in to a function,
 * it allowing uniform prototype for function pointer struct
 * @arg: is string generated from getline containing arguement
 * @argv: arrays of strings generated from arg
 * @path: is string path for the current command
 * @argc:  argument count
 * @line_count:  error count
 * @err_num:  error code for exit()s
 * @linecount_fla: is on count this line of input
 * @fnam:  program filename
 * @env:is linked list local copy of environ
 * @environ:it custom modified copy of environ from LL env
 * @historys:  history node
 * @alia: alias node
 * @env_change: on if environ was change
 * @status: the return statu of the last exec d command
 * @cmd_buf:an address of pointer to cmd buf, on if chaining
 * @cmd_buf_type: CMD type ||, &&, ;
 * @readfd: fd from which to read line input
 * @histcount: history line number count
 */
typedef struct passinfo
{
        int argc;
        char *arg;
        char **argv;
        char *path;
        int err_num;
        int linecount_flag;
        char *fname;
        list_t *env;
        list_t *history;
        list_t *alias;
        char **environ;
        int env_changed;
        unsigned int line_count;

        int status;
        int readfd;
        int histcount;

        char **cmd_buf; /* pointerses to cmd ; chain buffer, for   memory mangement */
        int cmd_buf_type; /* CMD_typ ||, &&, ; */
        } info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
        int (*func)(info_t *);
        char *type;
} builtin_table;



void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
int find_builtin(info_t *);


char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);


int loophsh(char **);


int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void _eputs(char *);


char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);


char *_strcpy(char *, char *);
int _putchar(char);
char *_strdup(const char *);
void _puts(char *);



char *_strncpy(char *, char *, int);
char *_strchr(char *, char);
char *_strncat(char *, char *, int);

char **strtow(char *, char *);
char **strtow2(char *, char);


char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int bfree(void **);


int _isalpha(int);
int _atoi(char *);
int interactive(info_t *);
int is_delim(char, char *);


int _erratoi(char *);
void print_error(info_t *, char *);
char *convert_number(long int, int, int);
void remove_comments(char *);
int print_d(int, int);


int _myexit(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);


int _myalias(info_t *);
int _myhistory(info_t *);


int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);


void set_info(info_t *, char **);
void free_info(info_t *, int);
void clear_info(info_t *);


char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int populate_env_list(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);


list_t *add_node(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);


size_t list_len(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);

int is_chain(info_t *, char *, size_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);

#endif
