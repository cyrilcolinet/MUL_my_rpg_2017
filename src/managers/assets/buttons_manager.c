/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons_manager funtions
*/

# include "rpg.h"

void callback_btn(button_t *btn, button_t conf)
{
	btn->state = conf.state;
	btn->onClick = conf.onClick;
	btn->onHover = conf.onHover;
	btn->onStart = conf.onStart;
}

void add_button(rpg_t *rpg, button_t conf)
{
	button_t *tmp = rpg->btn;

	while (tmp != NULL)
		tmp = tmp->next;

	tmp = malloc(sizeof(button_t));
	if (tmp == NULL)
		return;

	tmp->name = conf.name;
	tmp->pos = conf.pos;
	tmp->rect = conf.rect;
	tmp->normal_rect = conf.rect;
	tmp->sprite = conf.sprite;
	tmp->next = NULL;

	callback_btn(tmp, conf);
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
