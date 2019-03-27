##
#	Makefile for `Tong_two_side_match` application
##
CC = gcc
CXX = g++
LIBS = -lrt
CFLAGS = --std=c++11 -W -Wall -Wno-sign-compare -O2 -s -pipe -mmmx -msse -msse2 -msse3
TARGET = ./all

#all: Greedy Random Rank ERank Polar OPolar OTGOA Batch
all: Greedy Random ERank Batch LLEP NNP Guide Polar-op
Greedy: monitor.h global.h Greedy.cpp
	$(CXX) $(CFLAGS) -o Greedy Greedy.cpp $(LIBS) -D WATCH_MEM

Random: monitor.h global.h Random.cpp
	$(CXX) $(CFLAGS) -o Random Random.cpp $(LIBS) -D WATCH_MEM

#Rank: monitor.h global.h Rank.cpp
#	$(CXX) $(CFLAGS) -o Rank Rank.cpp $(LIBS) -D WATCH_MEM

ERank: monitor.h global.h ERank.cpp
	$(CXX) $(CFLAGS) -o ERank ERank.cpp $(LIBS) -D WATCH_MEM
	
Polar: monitor.h global.h Polar.cpp
	$(CXX) $(CFLAGS) -o Polar Polar.cpp $(LIBS) -D WATCH_MEM

OPolar: monitor.h global.h OPolar.cpp
	$(CXX) $(CFLAGS) -o OPolar OPolar.cpp $(LIBS) -D WATCH_MEM
	
OTGOA: monitor.h global.h OTGOA.cpp
	$(CXX) $(CFLAGS) -o OTGOA OTGOA.cpp $(LIBS) -D WATCH_MEM

Batch: monitor.h global.h Batch.cpp
	$(CXX) $(CFLAGS) -o Batch Batch.cpp $(LIBS) -D WATCH_MEM

LLEP: monitor.h global.h Hungarian.h LLEP.cpp
	$(CXX) $(CFLAGS) -o LLEP LLEP.cpp $(LIBS) -D WATCH_MEM

NNP: monitor.h global.h NNP.cpp
	$(CXX) $(CFLAGS) -o NNP NNP.cpp $(LIBS) -D WATCH_MEM

Guide: monitor.h global.h Guide.cpp
	$(CXX) $(CFLAGS) -o Guide Guide.cpp $(LIBS) -D WATCH_MEM

Polar-op: monitor.h global.h Polar-op.cpp
	$(CXX) $(CFLAGS) -o Polar-op Polar-op.cpp $(LIBS) -D WATCH_MEM
	
.PHONY: clean 
clean:
		-@rm *.o *.gcno *~ 2> /dev/null || true
		-@rm Greedy Rank ERank Polar OPolar OTGOA Batch LLEP NNP 2> /dev/null || true	
		
