# topics time complexity ,linkedlist , array, stack ,queue , hashing ,searhing and sorting
# not coverd topics , Trees and Graphs

# Data Structure and Algorithm  coverd in python from CampaxX'

#Algorithmic Complexity

#how to measure how good your algorithm 
#what is efficiency in a program
# time & space

# google search 
# search a word in google 
#it's appear all the pages which has used word
#it's sort all the pages relivent to the user
#in take 0.65 ms to sort 10 cores of web pages
# searh engine is only google 
#ecommerence  flipcard , amazon
# swggy , zamatao eating
# travel ola , uber
# but search engine is only google
# google is accutually is manupally
# google used an algorithm page rank

#Example Of Space 
#2015 samsung   2gb/16gb  asphalt 8 GameLoft , 3gb
# everyone want to play but due to space  can't play
# they build their lite version asphalt lite
# instagram lite , facebook lite

# let suppose you are head of facebook

# facebook CSS file is 20Kb
#when you hit a URL it's goes to Server and download HTml and CSS file into your local machine 
# download mean we use bandwight  , it's cost to campany


#19kb  candiate 1  package 20LPA            ,   18 kb candiate 2    30 LPA             fb daily active user 1.95 Billion

# 200 * 10^7   * 1KB
# 2 * 10 ^ 9  * 1KB
#convert KB to gb divide by 1024 to MB , mb to gb 1024
# divide by 10^6
# 2 * 10^9 / 10 ^6  = 2* 1000=2000gb data save 
#per gb bandwight is 10 rupees   2000gb * 365 * 10rupees = 73 lakh save money

# how to measure time
#count operation to measure time
#Abstract notion order of growth

#1. Measure time

#problem with this code is varies time for different machine slow machine take larger time and fast machine has less time
import time

currTime= time.time()

# for i in range(1,101):
#     print(i)
print(currTime-time.time())

def intToString(i):
    digit="0123456789"
    result=""
    if i==0:
        return "0"
    while(i>0):
        result=digit[i%10] + result
        i=i//10
    return result
def SumPrint(n):
    total=0
    for i in range(1,n):
        total+=i
    return total
    
print(SumPrint(11))
number=123
number = intToString(number)
print(number)
print(type(number))

A=[1,2,3,4,5]
B=[2,3,4,5,6,6]

# for i in A:
#     for j in B:
#         for k in range(100000):
#             print('({},{})'.format(i,j))
#             print(k)
#order of growth
# we will calculate the time complexity for big input
# time and input methematical formula
# we just need a type of relationship time and input 
#order of growth is calculate using BIG Notation

#import ctypes

L=[]
L.append(1)
L.append(10)
L.append("2")
L.append('x')
L.append(1.2)
print(L)
print(type(L))
print(len(L))