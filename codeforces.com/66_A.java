import math
n = int(input())
if n <= 127 & n >= -128:
	print("byte")
elif n >= -32768 & n <= 32767:
	print("short")
elif n >= -2147483648 & n <= 2147483647:
	print("int")
elif n >= -9223372036854775808 & n <= 9223372036854775807:
	print("long")
else :
	print("BigInteger")
	