#pragma once

class Pixel
{
public:

	bool boolvalue;

	Pixel * leftPixel;
	Pixel * upperPixel;
	Pixel * rightPixel;
	Pixel * lowerPixel;

	Pixel * leftUpperPixel;
	Pixel * rightUpperPixel;
	Pixel * leftLowerPixel;
	Pixel * rightLowerPixel;

	int livingNeighBourCount();
	int livingNeighBourCountInt;

	void updateBoolValue();

	Pixel();
	~Pixel();

private:

};
