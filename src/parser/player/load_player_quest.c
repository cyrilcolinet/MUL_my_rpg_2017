/*
** EPITECH PROJECT, 2018
** load_player_quest
** File description:
** rpg
*/

#include "rpg.h"

static void configure_dialogue(quest_t *quest)
{
	quest->pnj[0]->dialogue[0] = my_strdup(
	"Quelle belle journee.");
	quest->pnj[0]->dialogue[1] = my_strdup(
	"Aidez moi mes champs sont attaques !!");
	quest->pnj[0]->dialogue[2] = my_strdup(
	"Merci, allez voir le marchand dans la ville.");
	quest->pnj[1]->dialogue[0] = my_strdup(
	"Je n'ai rien pour vous, partez !");
	quest->pnj[1]->dialogue[1] = my_strdup(
	"Merci pour votre aide, tenez.");
	quest->pnj[1]->dialogue[2] = my_strdup(
	"Allez voir le soldat en bas de la ville.");
	quest->pnj[2]->dialogue[0] = my_strdup(
	"Circulez !");
	quest->pnj[2]->dialogue[1] = my_strdup(
	"Allez enqueter au cimetiere.");
	quest->pnj[2]->dialogue[2] = my_strdup(
	"Allez tuer les nuisances de la foret");
	quest->pnj[2]->dialogue[3] = my_strdup(
	"Allez au chateau du roi");
}

static void configure_pnj_quest(quest_t *quest)
{
	quest->pnj = malloc(sizeof(pnj_t *) * 4);
	quest->pnj[3] = NULL;
	for (int i = 0; i < 3; i++) {
		quest->pnj[i] = malloc(sizeof(pnj_t));
		quest->pnj[i]->sprite = sfSprite_create();
		quest->pnj[i]->rec.top = 128;
		quest->pnj[i]->rec.left = 0;
		quest->pnj[i]->rec.width = 64;
		quest->pnj[i]->rec.height = 64;
	}
	quest->pnj[0]->dialogue = malloc(sizeof(char *) * 4);
	quest->pnj[0]->dialogue[3] = NULL;
	quest->pnj[1]->dialogue = malloc(sizeof(char *) * 4);
	quest->pnj[1]->dialogue[3] = NULL;
	quest->pnj[2]->dialogue = malloc(sizeof(char *) * 5);
	quest->pnj[2]->dialogue[4] = NULL;
	configure_dialogue(quest);
	quest->pnj[0]->rec.top = 64;
}

static quest_t *configure_quest(void)
{
	quest_t *quest = malloc(sizeof(quest_t));

	quest->win = sfRectangleShape_create();
	quest->unlock =  malloc(sizeof(bool) * 8);
	quest->done = malloc(sizeof(bool) * 8);
	for (int i = 0; i < 8; i++) {
		quest->unlock[i] = false;
		quest->done[i] = false;
	}
	quest->unlock[0] = true;
	return (quest);
}

void load_player_quest(rpg_t *rpg)
{
	rpg->player->quest = configure_quest();
	configure_pnj_quest(rpg->player->quest);
	rpg->player->quest->id = 0;
}
