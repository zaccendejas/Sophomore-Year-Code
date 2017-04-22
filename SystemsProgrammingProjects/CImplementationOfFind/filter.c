/* filter.c */

#include "search.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>

/**
 * Test whether or not the given path should be filtered out of the output.
 * @param   path        Path to file or directory.
 * @param   settings    Settings structure.
 * @return  Whether or not the path should be excluded from the output (true to
 * exclude, false to include).
 */
bool        filter(const char *path, const Settings *settings) {
    struct stat FI;

	if (lstat(path, &FI) == -1){
		fprintf(stderr, "Unable to open %s: %s\n", path, strerror(errno));
		_exit(-1);
	}

	// Checks if the type attribute of settings is set and if the path being passed in does not match that type
	if ((settings->type && (FI.st_mode & S_IFMT) != settings->type))
		return true;
	// Checks if the uid of settings is set and if the path does not match that uid
	if ((settings->uid >= 0 && FI.st_uid != settings->uid)){
		return true;
        }
	// Checks if the gid of settings is set and if the path does not match that 
	if ((settings->gid >= 0 && FI.st_gid != settings->gid)){
		return true;
        }
	// Checks if the access of settings is set and if the path doesn't have the same access atributes
	if (settings->access && access(path, settings->access) != 0)
		return true;
	// Checks if the empty bool of settings is set and check if the path is a file or non-empty directory
	if ( settings->empty && ((FI.st_mode & S_IFMT) == S_IFREG || is_directory_empty(path) == false )){
		// Checks if the path is a file
    	if ((FI.st_mode & S_IFMT) == S_IFREG){
			// Checks if the file is empty
            if (FI.st_size == 0){
                return false;
            }else{
                return true;
            }
        }
        return true;
    }
	// Checks if the path of settings is set and if the path given to filer doesn't match the path in settings
	if (settings->path && fnmatch(settings->path, path, 0))
		return true;
	// Checks if the name of settings is set and if the name in the path doesn't match the name in settings
	if (settings->name && fnmatch(settings->name, basename(path), 0))
		return true;
	// Checks if newer is set and if the path isn't newer than the file used for newer in settings
	if (settings->newer && FI.st_mtim.tv_sec <= settings->newer)
		return true;
	// Checks if the perm of settings is set and if the path doesn't have the same permissions as perm in settings
	if (settings->perm && ((FI.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) != settings->perm)){
		return true;
        }
	// Returns false when none of these conditions are met meaning the path contains the specified settings and should be included in the results
	return false;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
