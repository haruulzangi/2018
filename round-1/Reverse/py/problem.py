#!/usr/bin/env python

oruulsan_utga = raw_input("Nuuts ug: ")

if len(oruulsan_utga) != 15:
  print "Muu"
  exit()


zuv_arr = [247, 211, 219, 121, 251, 56, 255, 105, 158, 146, 93, 89, 89, 56, 186]
oruulsan_arr = []
for char in oruulsan_utga:

  oruulsan_arr.append( (((ord(char) << 4) | (ord(char) >> 2)) ^ 101) & 255 )

if (oruulsan_arr == zuv_arr):
  print "Sain"
else:
  print "Muu"