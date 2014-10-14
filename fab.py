#!/usr/bin/env python
#-*-coding=utf-8-*-
'''
@author jdpdyx@126.com (jiangdapeng)
@date 2014-10-14
@from netease interview problem
'''

'''
problem:
   calculate f(a,b) = f(a-1,b) + f(a,b-1)
   given: 
    f(0,b) = b
    f(a,0) = 1
    for a >=0 , b>=0
'''

# using closure
def gen_calculator(a,b):
  table = [[0 for j in range(b+1)] for i in range(a+1)]
  for i in range(b+1):
    table[0][i] = i
  for i in range(a+1):
    table[i][0] = 1

  def do_fab(a,b):
    if a == 0:
      return b
    if b == 0:
      return 1
    if table[a][b] == 0:
      table[a][b] = do_fab(a-1,b) + 2*do_fab(a,b-1)
    return table[a][b]
  
  return do_fab

def test():
  f = gen_calculator(10,10)
  print "f(0,0) =  %d" % (f(0,0)) 
  print "f(0,1) =  %d" % (f(0,1)) 
  print "f(1,0) =  %d" % (f(1,0)) 
  print "f(1,1) =  %d" % (f(1,1)) 
  print "f(2,3) =  %d" % (f(2,3)) 
  print "f(10,10) =  %d" % (f(10,10)) 

if __name__ == '__main__':
  test()
