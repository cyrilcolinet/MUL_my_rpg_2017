/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** events_manager functions
*/

# include "lizz.h"

static btn_t *get_button(lizz_t *l, menu_e m, pos_t p)
{
	btn_t *tmp = l->btn;
	sfVector2f pos;
	sfIntRect rec;

	while (tmp != NULL) {
		if (tmp->belongsTo == m && tmp->asset != NULL) {
			pos = tmp->asset->pos;
			rec = *tmp->asset->rect;

			if (p.x >= pos.x && p.x <= (pos.x + rec.width))
				if (p.y >= pos.y && p.y <= (pos.y + rec.height))
					return (tmp);
		}
		tmp = tmp->next;
	}

	return (NULL);
}

void lizz_poll_events(lizz_t *lizz, sfEvent *event, menu_e menu)
{
	pos_t p = { event->mouseMove.x, event->mouseMove.y };
	btn_t *btn = NULL;

	if (event->type == sfEvtMouseMoved) {
		btn = get_button(lizz, menu, p);
		if (btn != NULL) {
			printf("%s\n", btn->name);
		}
	}
}
