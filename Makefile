##
# c brain fuck
#
# @file
# @version 0.1
CFLAGS = -Wall -Wextra -O2 -std=c99  -pedantic
OUT = cbf
cbf: cbf.c
	cc -o $(OUT) cbf.c $(CFLAGS)
# end
