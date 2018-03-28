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

static void print_created(thread_t *thread)
{
	lizz_info("Thread \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" created.\n");
}

/*
** Créerun noueau thread identifié par un nom
** @param (char *name) - Nom/ID du thread
** @param (void (*callback)(void *)) - Executed threaded function
** @param (void *data) - User data (see SFML documentation)
**  @return (int) - Retourne -1 si erreur et 0 si pas d'erreurs
*/
int lizz_thread_create(char *name, void (*callback)(void *), void *data)
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
	thread->thread = sfThread_create(callback, data);
	thread->destroy = &lizz_thread_destroy;
	thread->wait = &lizz_thread_wait;
	thread->start = &lizz_thread_start;
	thread->terminate = &lizz_thread_terminate;
	thread->next = NULL;
	print_created(thread);

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

	lizz_error("Unable to found a thread named \"");
	lizz_print(2, name);
	lizz_print(2, "\"\n");
	return (NULL);
}
