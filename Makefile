##
# c brain fuck
#
# @file
# @version 0.1

cbf: cbf.c
	cc -o cbf cbf.c

release: cbf.c
	cc -o cbf cbf.c -O3
# end
