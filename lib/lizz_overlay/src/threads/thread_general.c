/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** thread_general functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

/*
** Détruire un thread
** @param (thread_t *thread) - Thread a destruire
** @return (void)
*/
void lizz_thread_destroy(thread_t *thread)
{
	if (!thread)
		return;

	thread->terminate(thread);
	sfThread_destroy(thread->thread);
	lizz_info("Thread named \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" has been destroyed!\n");
}

/*
** Mettre un thread en attente
** @param (thread_t *thread) - Thread a faire patienter...
** (une petite musique d'ascensseur d'impose fortement...)
** @return (void)
*/
void lizz_thread_wait(thread_t *thread)
{
	if (!thread)
		return;

	sfThread_wait(thread->thread);
	lizz_info("Thread named \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" is waiting!\n");
}

/*
** Démarrer un thread
** @param (thread_t *thread) - Thread a démarrer
** @return (void)
*/
void lizz_thread_start(thread_t *thread)
{
	if (!thread)
		return;

	sfThread_launch(thread->thread);
	lizz_info("Thread named \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" started!\n");
}

/*
** Terminer un thread
** @param (thread_t *thread) - Thread a terminer
** @return (void)
*/
void lizz_thread_terminate(thread_t *thread)
{
	if (!thread)
		return;

	sfThread_terminate(thread->thread);
	lizz_info("Thread named \"");
	lizz_print(1, thread->name);
	lizz_print(1, "\" stopped!\n");
}
