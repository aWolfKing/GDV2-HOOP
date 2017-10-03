#pragma once
#include "Pixel.h";
#include <string>
#include <iostream>

Pixel::Pixel()
{
	this->leftUpperPixel = NULL;
	this->upperPixel = NULL;
	this->rightUpperPixel = NULL;
	this->leftPixel = NULL;
	this->rightPixel = NULL;
	this->leftLowerPixel = NULL;
	this->lowerPixel = NULL;
	this->rightLowerPixel = NULL;

	this->boolvalue = false;
}

Pixel::~Pixel()
{
}

int Pixel::livingNeighBourCount() {
	int ret = 0;
	
	if (this->leftPixel) {
		ret += ((this->leftPixel)->boolvalue ? 1 : 0);
	}
	if (this->rightPixel) {
		ret += ((this->rightPixel)->boolvalue ? 1 : 0);
	}
	if (this->upperPixel) {
		ret += ((this->upperPixel)->boolvalue ? 1 : 0);
	}
	if (this->lowerPixel) {
		ret += ((this->lowerPixel)->boolvalue ? 1 : 0);
	}

	if (this->leftUpperPixel) {
		ret += ((this->leftUpperPixel)->boolvalue ? 1 : 0);
	}
	if (this->rightUpperPixel) {
		ret += ((this->rightUpperPixel)->boolvalue ? 1 : 0);
	}
	if (this->leftLowerPixel) {
		ret += ((this->leftLowerPixel)->boolvalue ? 1 : 0);
	}
	if (this->rightLowerPixel) {
		ret += ((this->rightLowerPixel)->boolvalue ? 1 : 0);
	}
	
	this->livingNeighBourCountInt = ret;
	
	return ret;
}

void Pixel::updateBoolValue() {
	if (this->livingNeighBourCountInt == 3 && !this->boolvalue) {
		this->boolvalue = true;
	}
	else if ((this->livingNeighBourCountInt == 2 || this->livingNeighBourCountInt == 3) && this->boolvalue) {
		this->boolvalue = true; //just for overviewing
	}
	else if (this->livingNeighBourCountInt > 3) {
		this->boolvalue = false;
	}
	else
	{
		this->boolvalue = false;
	}
}