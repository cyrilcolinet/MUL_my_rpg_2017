/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main function
*/

#include "rpg.h"

int main(int ac, char **av, char **env)
{
	int res = 0;
	int fd = -1;

	sfRenderTexture *topkek;
	if (env == NULL)
		return (84);
	Py_InitializeEx(0);
	PyObject *obj = Py_BuildValue("s", "test.py");
	FILE *file = _Py_fopen_obj(obj, "r+");
	if(file != NULL)
		PyRun_SimpleFile(file, "test.py");
	if (Py_FinalizeEx() < 0)
		return (ERROR_CODE);
	res = main_rpg(ac, av);
	return (res);
}
