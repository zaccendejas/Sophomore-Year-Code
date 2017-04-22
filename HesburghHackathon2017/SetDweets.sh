#!/usr/bin/sh

# Sets 31 taken desks for the 12th floor
for x in $(seq 200 230)
do
	curl https://dweet.io/dweet/for/openSeat$x?desk=taken
done

# Sets 10 open desks for the 12th floor
for x in $(seq 231 240)
do
	curl https://dweet.io/dweet/for/openSeat$x?desk=open
done

# Sets 4 taken computers for the 12th floor
for x in $(seq 241 244)
do
	curl https://dweet.io/dweet/for/openSeat$x?computer=taken
done

# Sets 4 open computers for the 12th floor
for x in $(seq 245 248)
do
	curl https://dweet.io/dweet/for/openSeat$x?computer=open
done

# Sets 2 open tables for the 12th floor
for x in $(seq 249 250)
do
	curl https://dweet.io/dweet/for/openSeat$x?table=open
done

# Sets 10 open tables for the Center for Digital Scholarship
for x in $(seq 251 260)
do
	curl https://dweet.io/dweet/for/openSeat$x?table=open
done

# Sets 15 taken tables for the Center for Digital Scholarship
for x in $(seq 261 275)
do
	curl https://dweet.io/dweet/for/openSeat$x?table=taken
done

# Sets 5 open computers for the Center for Digital Scholarship
for x in $(seq 276 280)
do
	curl https://dweet.io/dweet/for/openSeat$x?computer=open
done

# Sets 10 taken computers for the Center for Digital Scholarship
for x in $(seq 281 290)
do
	curl https://dweet.io/dweet/for/openSeat$x?computer=taken
done
echo
