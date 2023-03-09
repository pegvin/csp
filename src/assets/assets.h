#ifndef ASSETS_H
#define ASSETS_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// All the assets are saved in binary directly in the code, using tool/create_assets.py.

/*
	Function: Assets_get()
	Arguments:
		filePath: ex - data/fonts/Montserrat-Bold.ttf
		size: size of the data will be stored in this variable
*/
const void* Assets_Get(const char *filePath, int *size);

/*
	Function: Assets_list()
	Description: List all the assets in a given asset dir,
				 returns the number of assets listed, calls
				 the callback function on every item.
				 if the callback doesn't return 0, the asset
				 is skipped.
	Arguments:
		directoryPath: directory to list items of
		callback: function to call on every item
*/
int Assets_List(const char* directoryPath, int (*callback)(int i, const char *path));

#ifdef __cplusplus
}
#endif

#endif // ASSETS_H
