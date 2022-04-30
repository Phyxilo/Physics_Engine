#!/usr/bin/python

import numpy as np
import math
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
from sympy import *
from mpl_toolkits.mplot3d import Axes3D

posVect = "0j"
velVect = "-8i,20j,12k"
accVect = "-9.81k"
initTime = 0
finalTime = 5
deltaTime = 0.01


def posFunction (r, v, a, t):

	pos = r + v*t + (1/2)*a*t**2

	return (pos)

def velFunction (r, v, a, t):

	vel = v + a*t

	return (vel)

def Force(a1Vect, isIn):

	a = [0]*3

	for i in range (3):
		a0 = vectToArr(accVect)[i]
		a1 = vectToArr(a1Vect)[i]

		if (isIn):

			a[i] = a0
		else:

			a[i] = a0

	return(a)

def Momentum(isIn):

	v = [0]*3

	for i in range (3):
		v0 = vectToArr(velVect)[i]
		#a1 = vectToArr(v1Vect)[i]

		if (isIn):

			v[1] = 0
			v[0] = 0
			v[2] = 100
		else:

			v[i] = v0

	return(v)


def drawGraph (x, y, z, dim):

	if (dim == "2d"):

		plt.plot(x, y)
		plt.grid(color='r', linestyle='--', linewidth=1)

		plt.xlabel("X-Axis")
		plt.ylabel("Y-Axis")

	if (dim == "3d"):

		fig = plt.figure()
		ax = fig.gca(projection='3d')

		z = findPos()[2]
		x = findPos()[0]
		y = findPos()[1]

		ax.plot(x, y, z, label='Path')
		ax.legend()

		ax.set_xlabel('X-Axis')
		ax.set_ylabel('Y-Axis')
		ax.set_zlabel('Z-Axis')


	plt.show()

def vectToArr (x):

	n = len(x.split(","))
	Arr = [0]*3

	for i in range (n):

		if (x.split(",")[i].find("i") >= 0):

			Arr[0] = float(x.split(",")[i].replace("i", ""))

		if (x.split(",")[i].find("j") >= 0):

			Arr[1] = float(x.split(",")[i].replace("j", ""))

		if (x.split(",")[i].find("k") >= 0):

			Arr[2] = float(x.split(",")[i].replace("k", ""))


	return (Arr)

isInInit = False

def instantenousVel(t, aSum, vSum):

	dimension = 3
	velArr = [0]*dimension

	for i in range (dimension):

		a0 = aSum[i]
		v0 = vSum[i]
		r0 = vectToArr(posVect)[i]		

		velArr[i] = velFunction(r0, v0, a0, t)

	return(velArr)

def Collision (vel, pos, obj):

	time = 0

	for t in range (int(abs((initTime - finalTime)/deltaTime))):


		isHit = isInside(obj, pos)

		if (isHit == false): 
			time += deltaTime
				
		else: 
			time = 0

		print(time)


	return(time)

		

def instantenousPoint(t, f, aArr):

	dimension = 3
	pointArr = [0]*dimension

	for i in range (dimension):

		a0 = aArr[i]
		v0 = vectToArr(velVect)[i]
		r0 = vectToArr(posVect)[i]		

		pointArr[i] = f(r0, v0, a0, t)
	

	return(pointArr)

def findPos ():

	n = int(abs((initTime - finalTime)/deltaTime))
	posArr = [([0]*n)[:], ([0]*n)[:], ([0]*n)[:]]
	pos = [0]*3
	time = 0

	v = [-8, 20, 12]

	for x in range (3):
		pos[x] = vectToArr(posVect)[x]

	for t in range (int(abs((initTime - finalTime)/deltaTime))):

		isHit = isInside(Object3D, pos)

		if (isHit == false): 
			time += deltaTime
			
		else: 
			time = 0
			v[2] *= 0.6
			
		for i in range (3):
			pos[i] += instantenousVel(time, Force("9.81k", isHit), v)[i]*deltaTime
			posArr[i][t] = pos[i]
		

	return(posArr)

def Object3D(vect):

	x = vect[0]
	y = vect[1]
	z = vect[2]

	objRegion = [False]*3

	dx = [-100, 100]
	dy = [-100, 100]
	dz = [-100, -0.01]

	objRegion[0] = x <= dx[1] and x >= dx[0]
	objRegion[1] = y <= dy[1] and y >= dy[0]
	objRegion[2] = z <= dz[1] and z >= dz[0]

	return (objRegion)

def isInside(obj, pos):

	isIn = False

	if (obj(pos) and obj(pos)[1] and obj(pos)[2]):
		isIn = True

	else: 
		isIn = False

	return (isIn)

drawGraph(findPos()[0], findPos()[1], findPos()[2], "3d")
#findPos()

#Collision(isInside(Object3D))
#print(isInside(Object3D))

