#!/bin/bash

CT=0
STATE='Indiana'
FORMAT='text'

while getopts hc:f:s: opt	# Used to parse through command line flags and arguments
do
	case $opt in
		h)
			echo 'Usage: zipcode.sh
	-c CITY		Which city to search
	-f FORMAT	Which format (text, csv)
	-s STATE	Which state to search (Indiana)
If no CITY is specified, then all the zip codes for that STATE are displayed.'
			exit 1
			;;
		c)
			CT=1
			CITY=$OPTARG
			;;
		f)
			FORMAT=$OPTARG
			;;
		s)
			STATE=$OPTARG
			;;
	esac
done

if [[ $FORMAT = 'text' || $FORMAT = 'csv' ]]		# A nested if is used to ensure that valid text was entered for the -f flag and the ifs nested inside display the desired zipecodes using regex.
then
	if [[ $CT = '0' && $FORMAT != 'csv' ]]
	then
		/usr/bin/curl -sL http://www.zipcodestogo.com/"$STATE"/ | sed -En 's|.*[[:upper:]]{2}/([0-9]{5}).*|\1|p' | sort | uniq		# usr/bin/curl may need to be modified if you do not have it stored in the same path
		exit 0
	fi
	if [[ $CT = '1' && $FORMAT != 'csv' ]]
	then
		/usr/bin/curl -sL http://zipcodestogo.com/"$STATE"/ | grep "/$CITY/" | sed -En 's|.*[[:upper:]]{2}/([0-9]{5}).*|\1|p' | sort | uniq
		exit 0
	fi
	if [[ $CT = '0' && $FORMAT = 'csv' ]]
	then
		/usr/bin/curl -sL http://www.zipcodestogo.com/"$STATE"/ | sed -En 's|.*[[:upper:]]{2}/([0-9]{5}).*|\1|p' | sort | uniq | paste -d , -s
		exit 0
	fi
	if [[ $CT = '1' && $FORMAT = 'csv' ]]
	then
		/usr/bin/curl -sL http://zipcodestogo.com/"$STATE"/ | grep "/$CITY/" | sed -En 's|.*[[:upper:]]{2}/([0-9]{5}).*|\1|p' | sort | uniq | paste -d , -s
		exit 0
	fi
fi
echo "-f must be followed by either 'text' of 'csv'"
exit 1
