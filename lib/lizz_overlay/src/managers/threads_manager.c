/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** thread_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static thread_t *set_functions(thread_t *thread)
{
	thread->destroy = &lizz_thread_destroy;
	thread->wait = &lizz_thread_wait;
	thread->start = &lizz_thread_start;
	thread->terminate = &lizz_thread_terminate;

	lizz_info("Thread \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" created.\n");

	return (thread);
}

static void fill_node_values(thread_t *node, thread_t values, void *data)
{
	node->name = values.name;
	node->thread = sfThread_create(values.callback, data);
	if (node->thread == NULL) {
		lizz_error("Error during creation of thread.\n");
	}

	node = set_functions(node);
	node->next = NULL;
}

static bool new_thread_node(lizz_t *st, thread_t values, void *data)
{
	thread_t **threads = &st->thread;
	thread_t *node = NULL;

	if (st->thread == NULL) {
		node = malloc(sizeof(thread_t));
		fill_node_values(node, values, data);
		node->next = *threads;
		*threads = node;
		return (true);
	}

	node = st->thread;
	while (node->next != NULL)
		node = node->next;

	node->next = malloc(sizeof(thread_t));
	if (node->next == NULL)
		return (false);
	fill_node_values(node->next, values, data);
	return (true);
}

/*
** Créerun noueau thread identifié par un nom
** @param (char *name) - Nom/ID du thread
** @param (void (*callback)(void *)) - Executed threaded function
** @param (void *data) - User data (see SFML documentation)
**  @return (int) - Retourne -1 si erreur et 0 si pas d'erreurs
*/
int lizz_thread_create(lizz_t *st, char *name, void (*c)(void *), void *d)
{
	thread_t thread;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	thread.name = name;
	thread.callback = c;

	if (!new_thread_node(st, thread, d))
		return (-1);

	return (0);
}

/*
** Récupérer un thread grace à son nom
** @param (char *name) - Nom du thread
** @return (thread_t) - Retourne NULL si aucun thread ne correspond
** au nom donné en argument, sinon retourne le thread correspondant
*/
thread_t *lizz_get_thread(lizz_t *st, char *name)
{
	thread_t *tmp = st->thread;

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
