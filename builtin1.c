#include "shell.h"

/**
 * _myhistory - Displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 *
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Returns: Always 0.
 */
int _myhistory(info_t *info) {
  // Prints the history list, one command by line, preceded
  // with line numbers, starting at 0.
  print_list(info->history);
  return (0);
}

/**
 * unset_alias - Removes an alias from the list.
 *
 * @info: Structure containing information about the shell.
 * @str: The name of the alias to remove.
 *
 * Returns: 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *str) {
  // Finds the index of the alias in the list.
  int index = get_node_index(info->alias, node_starts_with(info->alias, str, -1));

  // If the alias is not found, return an error.
  if (index == -1) {
    return (1);
  }

  // Removes the alias from the list.
  delete_node_at_index(&(info->alias), index);

  // Returns success.
  return (0);
}

/**
 * set_alias - Sets an alias in the list.
 *
 * @info: Structure containing information about the shell.
 * @str: The name of the alias to set.
 *
 * Returns: 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str) {
  // Finds the index of the alias in the list.
  int index = get_node_index(info->alias, node_starts_with(info->alias, str, -1));

  // If the alias is not found, add it to the list.
  if (index == -1) {
    return (add_node_end(&(info->alias), str, 0) == NULL);
  }

  // If the alias is found, update the value.
  else {
    list_t *node = get_node_at_index(info->alias, index);
    node->str = str;
  }

  // Returns success.
  return (0);
}

/**
 * print_alias - Prints an alias string.
 *
 * @node: The alias node.
 *
 * Returns: 0 on success, 1 on error.
 */
int print_alias(list_t *node) {
  // If the node is not null, print the alias string.
  if (node) {
    char *p = _strchr(node->str, '=');
    for (char *a = node->str; a <= p; a++) {
      _putchar(*a);
    }
    _putchar('\'');
    _puts(p + 1);
    _puts("'\n");
    return (0);
  }

  // If the node is null, return an error.
  return (1);
}

/**
 * _myalias - Mimics the alias builtin (man alias).
 *
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * Returns: Always 0.
 */
int _myalias(info_t *info) {
  // If there is only one argument, print all  aliases.
  if (info->argc == 1) {
    list_t *node = info->alias;
    while (node) {
      print_alias(node);
      node = node->next;
    }
    return (0);
  }

  // For each argument after the first,  print the alias.
  for (int i = 1; info->argv[i]; i++) {
    char *p = _strchr(info->argv[i], '=');
    if (p) {
      set_alias(info, info->argv[i]);
    } else {
      print_alias(node_starts_with(info->alias, info

