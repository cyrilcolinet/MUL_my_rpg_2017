/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quests view
*/

# include "rpg.h"

static void draw_quest_name(rpg_t *rpg, quest_t *quest)
{
	sfVector2f pos = {230, 250};
	char *str = NULL;
	int id = quest->id;

	if (quest->id == 9)
		id -= 1;
	for (int i = 0; i < id + 1; i++) {
		sfText_setPosition(rpg->text, pos);
		sfText_setString(rpg->text, "Quete ");
		sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
		pos.x += 100;
		sfText_setPosition(rpg->text, pos);
		str = my_itoa(i + 1);
		sfText_setString(rpg->text, str);
		free(str);
		sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
		pos.y += 80;
		pos.x -= 100;
	}
}

static void draw_quest_info(rpg_t *rpg, quest_t *quest)
{
	sfVector2f pos = {360, 250};
	char *str[10] = {
		": Aller voir le paysan",
		": Aider le paysan contre les bandits",
		": Aller voir le marchand",
		": Aller voir le soldat",
		": Aller examiner le cimetiere",
		": Aller voir le soldat",
		": Aller tuer les nuisances de la foret",
		": Aller faire votre rapport au soldat",
		": Aller au chateau du Roi",
		NULL
	};

	for (int i = 0; i < quest->id + 1; i++) {
		sfText_setPosition(rpg->text, pos);
		sfText_setString(rpg->text, str[i]);
		sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
		pos.y += 80;
	}
}

static void draw_quest_status(rpg_t *rpg, quest_t *quest)
{
	sfVector2f pos = {1100, 250};

	for (int i = 0; i < quest->id; i++) {
		sfText_setPosition(rpg->text, pos);
		sfText_setColor(rpg->text, sfGreen);
		sfText_setString(rpg->text, "Accomplie");
		sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
		pos.y += 80;
	}
	if (quest->id < 9) {
	sfText_setPosition(rpg->text, pos);
	sfText_setColor(rpg->text, sfBlue);
	sfText_setString(rpg->text, "En cour");
	sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
	}
}

static void draw_quest(rpg_t *rpg, quest_t *quest)
{
	sfVector2f pos = {300, 160};

	sfRenderWindow_drawRectangleShape(rpg->win, quest->win, NULL);
	sfText_setCharacterSize(rpg->text, 55);
	sfText_setColor(rpg->text, sfBlack);
	sfText_setPosition(rpg->text, pos);
	sfText_setString(rpg->text, "Journal de quete");
	sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
	sfText_setCharacterSize(rpg->text, 32);
	if (quest->id > 9)
		quest->id = 9;
	draw_quest_name(rpg, quest);
	draw_quest_info(rpg, quest);
	sfText_setCharacterSize(rpg->text, 24);
	draw_quest_status(rpg, quest);
}

void quests_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Quest");
	draw_quest(rpg, rpg->player->quest);
}
