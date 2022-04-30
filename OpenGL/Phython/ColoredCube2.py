#!/usr/bin/python

import pygame
import EngineBase
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

colors = (
    (1,0,0),
    (0,1,0),
    (0,0,1),
    (0,1,0),
    (1,1,1),
    (0,1,1),
    (1,0,0),
    (0,1,0),
    (0,0,1),
    (1,0,0),
    (1,1,1),
    (0,1,1),
    )

verticies= (
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
    )

edges = (
    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)
    )

surfaces = (
    (0,1,2,3),
    (3,2,7,6),
    (6,7,5,4),
    (4,5,1,0),
    (1,5,7,2),
    (4,0,3,6)
    )

def velFunction (v, a, t):

	vel = v + a*t

	return (vel)
#print(EngineBase.finalVel(2))

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

vel = "40i,60j,-20k"
acc = "0i,-9.81j,0k"

def Cube():

    glBegin(GL_QUADS)
    for surface in surfaces:
        x = 0
        for vertex in surface:
            x+=1
            glColor3fv(colors[x])
            glVertex3fv(verticies[vertex])
    glEnd()

    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glColor3fv((0,0,0))
            glVertex3fv(verticies[vertex])
    glEnd()
print(Cube.Position.x)
def main():
    pygame.init()
    display = (800,600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(40, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(-10.0,0.0,-30)
    glRotatef(0, 0, 0, 0)

    time = 0

    while True:
        for event in pygame.event.get():
            time += 1/20
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            #glRotatef(1, 3, 1, 1)
            glTranslatef(velFunction(vectToArr(vel)[0], vectToArr(acc)[0], time)/800,velFunction(vectToArr(vel)[1], vectToArr(acc)[1], time)/800,velFunction(vectToArr(vel)[2], vectToArr(acc)[2], time)/800)

            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
            Cube()
            pygame.display.flip()
            pygame.time.wait(10)

main()
