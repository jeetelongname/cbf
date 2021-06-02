##
# c brain fuck
#
# @file
# @version 0.1
CFLAGS = -Wall -Wextra -pedantic
OUT = cbf
cbf: cbf.c
	cc -o $(OUT) cbf.c $(CFLAGS) -g

fast: cbf.c
	cc -o $(OUT) cbf.c $(CFLAGS) -O3
# end
