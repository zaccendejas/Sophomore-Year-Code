This is a C Implementation of the unix find command, including some of its fundemental flags. All the flags supported by ./search can be found by running ./search -help from the command line. An example call to the program could be:

./search /etc -exec stat -t {} ; -perm 644

I worked on this program with Noelle Rosa and we created each file together.
