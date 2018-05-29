/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons_manager funtions
*/

# include "rpg.h"

static void fill_values(button_t *node, button_t conf)
{
	node->name = conf.name;
	node->pos = conf.pos;
	node->rect = conf.rect;
	node->normal_rect = conf.rect;
	node->sprite = conf.sprite;
	node->state = conf.state;
	node->onClick = conf.onClick;
	node->onHover = conf.onHover;
	node->onStart = conf.onStart;
	node->pressed = false;
	node->hovered = false;
	node->next = NULL;
}

void add_button(rpg_t *rpg, button_t conf)
{
	button_t **assets = &rpg->btn;
	button_t *node = NULL;

	if (rpg->btn == NULL) {
		node = malloc(sizeof(button_t));
		if (node == NULL)
			return;
		fill_values(node, conf);
		node->next = *assets;
		*assets = node;
		return;
	}
	node = rpg->btn;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(button_t));
	if (node->next == NULL)
		return;
	fill_values(node->next, conf);
}

button_t *is_button(rpg_t *rpg, int x, int y)
{
	button_t *tmp = rpg->btn;
	sfVector2f pos;
	sfIntRect rec;

	while (tmp != NULL) {
		pos = tmp->pos;
		rec = tmp->rect;

		if (rpg->state == tmp->state)
			if (x >= pos.x && x <= (pos.x + rec.width))
				if (y >= pos.y && y <= (pos.y + rec.height))
					return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}

void draw_buttons(rpg_t *rpg)
{
	button_t *tmp = rpg->btn;
	sfSprite *sprite = NULL;

	while (tmp != NULL) {
		if (tmp->state == rpg->state) {
			sprite = tmp->sprite;
			if (sprite != NULL)
				sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
		}
		tmp = tmp->next;
	}
}

button_t *get_button(rpg_t *rpg, char *name, state_e state)
{
	button_t *tmp = rpg->btn;

	while (tmp != NULL) {
		if (state == tmp->state)
			if (my_strequ(tmp->name, name))
				return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}
