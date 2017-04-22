/* driver.c */

#include "search.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sys/stat.h>
#include <unistd.h>

/* Functions */

void	    usage(const char *program_name, int status) {
    fprintf(stderr, "Usage: %s PATH [OPTIONS] [EXPRESSION]\n", program_name);
    fprintf(stderr, "\nOptions:\n");
    fprintf(stderr, "    -executable     File is executable or directory is searchable to user\n");
    fprintf(stderr, "    -readable       File readable to user\n");
    fprintf(stderr, "    -writable       File is writable to user\n\n");
    fprintf(stderr, "    -type [f|d]     File is of type f for regular file or d for directory\n\n");
    fprintf(stderr, "    -empty          File or directory is empty\n\n");
    fprintf(stderr, "    -empty          File or directory is empty\n\n");
    fprintf(stderr, "    -name  pattern  Base of file name matches shell pattern\n");
    fprintf(stderr, "    -path  pattern  Path of file matches shell pattern\n\n");
    fprintf(stderr, "    -perm  mode     File's permission bits are exactly mode (octal)\n");
    fprintf(stderr, "    -newer file     File was modified more recently than file\n\n");
    fprintf(stderr, "    -uid   n        File's numeric user ID is n\n");
    fprintf(stderr, "    -gid   n        File's numeric group ID is n\n");
    fprintf(stderr, "\nExpressions:\n\n");
    fprintf(stderr, "    -print          Display file path (default)\n");
    fprintf(stderr, "    -exec cmd {} ;  Execute command on path\n");
    exit(status);
}


/* Main Execution */

int	    main(int argc, char *argv[]) {
	Settings settings = {								// Sets the default values for the settings struct
    	.access = 0,
    	.uid    = -1,
    	.gid    = -1,
	};
	char *FileName = argv[0];
    int argind = 1;
	char *Root;
	if (argc < 2 || (argc >= 2 && argv[1][0] == '-')){	// Uses the current directory as the root of the search when no path is given to ./search
		Root = ".";
	}else{
		Root = argv[1];									// Sets the path following ./search to the root of the search
		argind++;
	}

    while (argind<argc && strlen(argv[argind])>1 && argv[argind][0] == '-'){
		char *arg = argv[argind++];						// Sets the next "-whatever" to arg
		if (streq(arg, "-help"))
			usage(FileName, 0);
        if (streq(arg, "-executable")) {
            settings.access |= X_OK;					// Adds the X_OK option to access
        }
        if (streq(arg, "-readable")){
            settings.access |= R_OK;					// Adds the R_OK option to access
        }
        if (streq(arg, "-writable")){
            settings.access |= W_OK;					// Adds the W_OK option to access
        }
        if (streq(arg, "-type")){
			arg = argv[argind++];						// Updates arg to check if a f or d follows -type
            if (streq(arg, "f")){
                 settings.type =  S_IFREG;   
            }
            else if (streq(arg, "d")){
                settings.type = S_IFDIR;
			}else{
				usage(FileName, 1);						// Displays the usage if input is invalid
			}
        }
        if (streq(arg, "-name")){
            settings.name = argv[argind++];   			// Sets name to the string that follows -name
        }
        if (streq(arg, "-path")){
            settings.path = argv[argind++];   			// Sets path to the string that follows -path
        }    
        if (streq(arg, "-perm")){   
            int Oct2Dec = atoi(argv[argind++]);
            int PermInt = 0;
            int Place = 100;
            int Digit;
            while (Place != 1){							// Converts a 3-digit permission octal to its integer form since the comparrison in filter automatically converts the integer value of settings.perm to an octal
                Digit = Oct2Dec / Place;
                PermInt = (Digit + PermInt) * 8;
                Oct2Dec = Oct2Dec - Digit*Place;
                Place = Place/10;
                if (Place == 1){
                    PermInt = PermInt + Oct2Dec;
                }
            }
            
	    settings.perm = PermInt;		// Sets perm to the integer value of the string that follows -perm
        }
        if (streq(arg, "-newer")){
			settings.newer = get_mtime(argv[argind++]);	// Uses utilities.c to get the time_t value of the file that follows -newer
        }
        if (streq(arg, "-uid")){
			settings.uid = atoi(argv[argind++]);		// Sets uid to the integer value of the string that follows -uid
        }
        if (streq(arg, "-gid")){
			settings.gid = atoi(argv[argind++]);		// Sets gid to the integer value of the string that follows -gid
        } 
        if (streq(arg, "-print")){
            settings.print = true;
        }

        if (streq(arg, "-empty")){
            settings.empty = true;
        }

        if (streq(arg, "-exec")){
            char *execargv[argc];									// Makes an array of strings with a size of argc, size there will never be more strings than that
            int counter = 0;
            while (argind < argc && !streq(argv[argind], ";")){		// Loops while argind is in argv and argv[argind] isn't a ;
                  execargv[counter] = argv[argind++];					// Adds the string to the array
                   
                  counter++;
            }

	    if (counter == 0)
                usage(FileName, 1);

            settings.exec_argc = counter; 							// Sets exec_argc to the number of arguments given to -exec

            settings.exec_argv= malloc(counter *(sizeof(char*)));	// Allocates memory for the array of strings in settings

            for (int i=0; i<counter; i++){

                settings.exec_argv[i] = strdup(execargv[i]);		// Copies the strings in the local array to the array in the settings struct
            }

            
        }
    }

    if (filter(Root, &settings) == false){		// filter returns false when file or directory doesn't need to be passed over 
    	if (execute(Root, &settings) == 1){		// Calls execute on the root path because it will get skipped over in search
    	    fprintf(stderr, "Unable to execute %s: %s\n",Root, strerror(errno));
        }
    }

    search(Root, &settings);					// Calls search on the root with the given settings from the command line
    for (int i=0; i< settings.exec_argc; i++){	// Frees the memory allocated to each string in exec_argv
        free(settings.exec_argv[i]);
    }
    free (settings.exec_argv);					// Frees the exec_argv array
}
/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
