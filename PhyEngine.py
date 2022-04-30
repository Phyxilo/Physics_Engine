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

def posFunction (t):

	pos = x0 + v0*t + (1/2)*a0*t**2

	return (pos)

def velFunction (t):

	vel = v0 + a0*t

	return (vel)

def Interval(ti, tf, dt, f):

	t = []
	x = []

	for i in range (int(abs((ti - tf)/dt))):

		t.append (round(i*dt, 4))
		x.append(round(f(i*dt), 4))

	return (t, x)

def drawGraph (x, y, z, dim):

	if (dim == "2d"):

		plt.plot(x, y)
		plt.grid(color='r', linestyle='--', linewidth=1)

		plt.xlabel("X-Axis")
		plt.ylabel("Y-Axis")

	if (dim == "3d"):

		fig = plt.figure()
		ax = fig.gca(projection='3d')

		z = findPos(velVect)[2]
		x = findPos(velVect)[0]
		y = findPos(velVect)[1]

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

def findPos (x):

	dimension = len(vectToArr (x))
	posArr = [0]*3

	for i in range (dimension):

		global v0
		global a0
		global x0

		a0 = vectToArr(accVect)[i]
		v0 = vectToArr(velVect)[i]
		x0 = vectToArr(posVect)[i]

		posArr[i] = Interval(initTime, finalTime, deltaTime, posFunction)[1]

	return(posArr)

def instantenousPoint(t, f):

	dimension = 3
	pointArr = [0]*dimension

	for i in range (dimension):

		global v0
		global a0
		global x0

		a0 = vectToArr(accVect)[i]
		v0 = vectToArr(velVect)[i]
		x0 = vectToArr(posVect)[i]

		pointArr[i] = f(t)

	return(pointArr)

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

def isInside(obj):

	isIn = False

	for i in range (int(abs((initTime - finalTime)/deltaTime))):

		isIn = obj(instantenousPoint(i*deltaTime, posFunction)) and obj(instantenousPoint(i*deltaTime, posFunction))[1] and obj(instantenousPoint(i*deltaTime, posFunction))[2]

		if (isIn): Collision


def Collision(enter):

	velVector[2] = 0

"""
drawGraph(findPos(velVect)[0], findPos(velVect)[1], findPos(velVect)[2], "3d")
"""

Collision(isInside(Object3D))
print(isInside(Object3D))

