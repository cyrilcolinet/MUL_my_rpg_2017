/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** thread_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static thread_t *new_thread_node(void)
{
	thread_t **tmp = &lizz->thread;

	while (*tmp != NULL)
		*tmp = (*tmp)->next;

	*tmp = malloc(sizeof(thread_t));

	if (*tmp == NULL) {
		lizz_error("Unable to alloc thread_t: Out of memory.\n");
		return (NULL);
	}

	return (*tmp);
}

/*
** Créerun noueau thread identifié par un nom
** @param (char *name) - Nom/ID du thread
**  @return (int) - Retourne -1 si erreur et 0 si pas d'erreurs
*/
int lizz_thread_create(char *name)
{
	thread_t *thread = NULL;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	thread = new_thread_node();
	if (!thread)
		return (-1);

	thread->name = name;
	thread->thread = NULL;
	thread->callback = NULL;
	thread->user_data = NULL;
	thread->next = NULL;

	return (0);
}

/*
** Récupérer un thread grace à son nom
** @param (char *name) - Nom du thread
** @return (thread_t) - Retourne NULL si aucun thread ne correspond
** au nom donné en argument, sinon retourne le thread correspondant
*/
thread_t *lizz_get_thread(char *name)
{
	thread_t *tmp = lizz->thread;

	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0) { // TODO: Forbidden function
			return (tmp);
		}
		tmp = tmp->next;
	}

	return (NULL);
}
