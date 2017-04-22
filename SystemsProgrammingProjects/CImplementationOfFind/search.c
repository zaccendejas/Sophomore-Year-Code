/* search.c */

#include "search.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>

/**
 * Recursively search through the provided root directory
 * @param   root        Path to directory
 * @param   settings    Settings structure
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root, const Settings *settings) {
    DIR *directory;
    struct dirent *dp;


    if((directory=opendir(root)) != NULL){
        while (( dp = readdir(directory)) != NULL){

            errno = 0;
            if((strcmp (dp->d_name, "..") == 0) || (strcmp(dp->d_name, ".") == 0)){
                continue;
            }
            char *NewRoot = malloc(strlen(root)+strlen(dp->d_name)+2);
            strcpy(NewRoot, root);
            strcat(NewRoot, "/");
            strcat(NewRoot, dp->d_name);
            if (filter(NewRoot, settings) == false){     //filter returns false when file or directory doesn't need to be passed over 
                if (execute(NewRoot, settings) == 1){
                    fprintf(stderr, "Unable to execute %s: %s\n",dp->d_name, strerror(errno));
                }
            }
            if (dp->d_type == DT_DIR){                      //need to call the function recursively when sudirectories are found
                search(NewRoot, settings);    
            }
            free(NewRoot);
        }
        //}

    	if (errno != 0){
        	fprintf(stderr, "There was an issue reading the directory");
        	return EXIT_FAILURE;
    	}

    	closedir(directory);
    	}else {
        	fprintf(stderr, "Unable to open %s: %s\n", root, strerror(errno));
        	return EXIT_FAILURE;
    	}


    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
