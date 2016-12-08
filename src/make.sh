#!/bin/bash


if [ "$1" == "" ]
	then
	 echo "nem jó"
	else
		g++ -Wall -g $1.cpp -lGL -lGLU -lglut -o $1 -std=c++11
fi