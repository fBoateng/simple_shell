#include "shell.h"

/**
 * _myexit - Exits the shell.
 *
 * @info: A pointer to a struct containing information about the shell.
 *
 * Returns: The exit status of the shell.
 */
int _myexit(info_t *info) {
  // Check if there is an exit argument.
  if (info->argv[1]) {
    // Convert the argument to an integer and use it as the exit status.
    int exitcheck = _erratoi(info->argv[1]);
    if (exitcheck == -1) {
      // If the argument cannot be converted to an integer, print an error message and exit with status 2.
      info->status = 2;
      print_error(info, "Illegal number: ");
      _eputs(info->argv[1]);
      _eputchar('\n');
      return (1);
    }
    info->err_num = exitcheck;
    return (-2);
  }
  // If there is no exit argument, set the exit status to 0.
  info->err_num = -1;
  return (-2);
}

/**
 * _mycd - Changes the current directory of the process.
 *
 * @info: A pointer to a struct containing information about the shell.
 *
 * Returns: Always 0.
 */
int _mycd(info_t *info) {
  // Get the current working directory.
  char *s = getcwd(buffer, 1024);
  if (!s) {
    // If getcwd fails, print an error message.
    _puts("TODO: >>getcwd failure emsg here<<\n");
  }

  // If there is no argument, change to the home directory.
  if (!info->argv[1]) {
    char *dir = _getenv(info, "HOME=");
    if (!dir) {
      // If HOME is not set, change to the root directory.
      chdir("/");
    } else {
      chdir(dir);
    }
  }

  // If the argument is "-", change to the previous working directory.
  else if (_strcmp(info->argv[1], "-") == 0) {
    if (!_getenv(info, "OLDPWD=")) {
      _puts(s);
      _putchar('\n');
      return (1);
    }
    _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
    chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
  }

  // Otherwise, change to the directory specified by the argument.
  else {
    chdir(info->argv[1]);
  }

  // If chdir fails, print an error message.
  if (chdir_ret == -1) {
    print_error(info, "can't cd to ");
    _eputs(info->argv[1]), _eputchar('\n');
  }

  // Set the OLDPWD environment variable to the previous working directory.
  if (chdir_ret != -1) {
    _setenv(info, "OLDPWD", _getenv(info, "PWD="));
    _setenv(info, "PWD", getcwd(buffer, 1024));
  }

  return (0);
}

/**
 * _myhelp - Prints a help message for the shell.
 *
 * @info: A pointer to a struct containing information about the shell.
 *
 * Returns: Always 0.
 */
int _myhelp(info_t *info) {
  // Print a help message for the shell.
  _puts("help call works. Function not yet implemented \n");
  return (0);
}
