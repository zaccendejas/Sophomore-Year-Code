#!/usr/bin/python

import functools
import hashlib
import itertools
import multiprocessing
import os
import string
import sys

# Constants

ALPHABET	=	string.ascii_lowercase + string.digits
ARGUMENTS	=	sys.argv[1:]
CORES		=	1
HASHES		=	'hashes.txt'
LENGTH		=	1
PREFIX		=	''

# Functions

def usage(exit_code=0):
	print '''Usage: {} [-a ALPHABET -c CORES -l LENGTH -p PATH -s HASHES]
	-a ALPHABET	Alphabet to use in permutations
	-c CORES	Number of CPU Cores to use
	-l LENGTH	Length of permutations
	-p PREFIX	Prefix for all permutations
	-s HASHES	Path of hashes file'''.format(os.path.basename(sys.argv[0]))
	sys.exit(exit_code)

def md5sum(s):
# Converts a string into its MD5 cryptographic hash
	m = hashlib.md5()
	m.update(s)
	return m.hexdigest()

def permutations(length, alphabet = ALPHABET):
# Generates a string for every possible combination of characters from the ALPHABET specified of the LENGTH specified
	if length == 1:
		for i in alphabet:
			yield i
	else:
	# Recursively calls the permutations function 
		for j in alphabet:
			for k in permutations(length-1, alphabet):
				yield j + k

def smash(hashes, length, alphabet = ALPHABET, prefix = ''):
# Returns all the password permutations of the specified lenght that exist in thehashes file.
	return [prefix + i for i in list(permutations(length, alphabet)) if md5sum(prefix + i) in hashes]

# Main Execution

if __name__ == '__main__':
# Parses command line arguments
	args = sys.argv[1:]
	while len(args) and args[0].startswith('-') and len(args[0]) > 1:
		arg = args.pop(0)
		if arg == "-a":
			ALPHABET = str(args.pop(0))
		elif arg == "-c":
			CORES = int(args.pop(0))
		elif arg == "-l":
			LENGTH = int(args.pop(0))
		elif arg == "-p":
			PREFIX = str(args.pop(0))
		elif arg == "-s":
			HASHES = str(args.pop(0))
		elif arg == "-h":
			usage(1)

# Load hashes set

	# When multiple CPU cores are called to be used, the following breaks the potential permutations into a combination of shorter prefixes that can be called with a prefix. This allows the task of checking if an permutation is in a hashs file go from one function call to many that multiple cores can process independently
	if CORES > 1 and LENGTH > 1:
		if LENGTH > 6:
			PreLength = 3
			NewLength = LENGTH - PreLength
			NewPrefix = [PREFIX + i for i in list(permutations(PreLength, ALPHABET))]
		elif LENGTH > 4:
			PreLength = 2
			NewLength = LENGTH - PreLength
			NewPrefix = [PREFIX + i for i in list(permutations(PreLength, ALPHABET))]
		else:
			PreLength = 1
			NewLength = LENGTH - PreLength
			NewPrefix = [PREFIX + i for i in list(permutations(PreLength, ALPHABET))]
	# Hashes are loaded in as a set so that they can be searched in O(1) time
	Passwords = set(line.rstrip() for line in open(HASHES))

# Execute smash function to get passwords
	if CORES > 1 and LENGTH > 1:
		subsmash = functools.partial(smash, Passwords, NewLength, ALPHABET)
		pool = multiprocessing.Pool(CORES)
		Confirmed = itertools.chain.from_iterable(pool.imap(subsmash, NewPrefix))
	else:
		Confirmed = smash(Passwords, LENGTH, ALPHABET, PREFIX)

# Print passwords
	print '\n'.join(Confirmed)
