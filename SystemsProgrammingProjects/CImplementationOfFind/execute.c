/* expression.c */

#include "search.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Executes the -print or -exec expressions (or both) on the specified path.
 * @param   path        Path to a file or directory
 * @param   settings    Settings structure.
 * @return  Whether or not the execution was successful.
 *
 * If print == true then print what is in the file (kind of like cat and if exec is true (meaning if the file is executable) then )
 */


int	    execute(const char *path, const Settings *settings) {
    if (settings->exec_argc > 0){
		// Creates a local array of the settings->exec_argc with the {} string replaced with the current path in this function
        char *nullArr[settings->exec_argc + 1];
		for (int i = 0; i < settings->exec_argc; i++){
			if (streq(settings->exec_argv[i], "{}")){
				nullArr[i] = path;
			}else{
				nullArr[i] = settings->exec_argv[i];
			}
        }
		// Adds a terminating NULL to the end of the local array
        nullArr[settings->exec_argc] = NULL;

        int status = EXIT_SUCCESS;
		// Creates a child process
        pid_t pid = fork();

        if(pid<0){                           //Error
            return 1;
        }
		
		// Changes the code of the child process to run the command given to -exec in the command line
        if (pid == 0){                       //child
            //execvp provides an array of pointers to null-terminated strings that represent the argument list available to the new program
            if (execvp(nullArr[0], nullArr) < 0){   //executes command
                _exit(EXIT_FAILURE);        //exit if exec fails
            }
        }

        else{                                //parent
            while ((pid = wait(&status))< 0);

        }

        return 0;
    }
    // Prints the path if -exec is not used
    if (settings->print || !settings->exec_argc){
        puts(path);
        return 0;
    }

    return 1;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
