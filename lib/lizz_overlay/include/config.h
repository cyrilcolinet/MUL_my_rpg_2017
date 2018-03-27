/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** config header file
*/

# ifndef LIZZ_OVERLAY_CONFIG_H
# define LIZZ_OVERLAY_CONFIG_H

/*
** Ce fichier de configuration doit contenir toute la configuration
** nécéssaire au bon fonctionnement de la librarie. À savoir:
**
** Des enum/structs:
**   - enum menu_e
**   - enum button_e
**
** Des macros:
**   - LIZZ_BTN_PATH (default: "./assets/buttons/")
**
** Si aucunes des configurations précédentes sont requises, vous
** devez obligatoirement les initialiser, mais les laisser vide.
*/

# define LIZZ_BTN_PATH 						("./assets/buttons/")

typedef enum menu_e {
	stMain,
	stPause,
	stSettings,
	stSave,
	stCustom
} 	menu_e;

# endif
