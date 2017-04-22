/* utilities.c */

#include "search.h"

#include <errno.h>
#include <string.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Test whether or not a directory is empty.
 * @param   path        Path to directory.
 * @return  Whether or not a directory is empty.
 */
bool        is_directory_empty(const char *path) {
	DIR *Directory;
	struct dirent *Files;
	int Counter = 0;
	if ((Directory = opendir(path)) != NULL){   // Opens the directory
		while ((Files = readdir(Directory)) != NULL){	// Checks if there are files in the directory
			if (streq(".", Files->d_name) || streq("..", Files->d_name))    // Ignores the two hidden relative path directories
				continue;
			Counter++;  //Increases Counter to show at least one file existed
			if (Counter > 1)    // Breaks after a file is preset so that it doesn't have to loop through every file
				break;
		}
	}
        else {
		fprintf(stderr, "Unable to open %s: %s\n", path, strerror(errno));  // Error message if directory can't be opened
		return false;
	}
	closedir(Directory);    // Closes the directory
	if (Counter == 0){
		return true;
	}
    return false;
}

/**
 * Retrieve the modification time of the given file.
 * @param   path        Path to file of directory.
 * @return  The modification time of the given file.
 */
time_t      get_mtime(const char *path) {
	struct stat SnowLeopard;
	if (lstat(path, &SnowLeopard) < 0){
		fprintf(stderr, "Unable to open %s: %s\n", path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return SnowLeopard.st_mtim.tv_sec;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
