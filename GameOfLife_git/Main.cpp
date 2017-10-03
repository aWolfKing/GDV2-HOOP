#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include "Pixel.h"
#include <random>
#include <string>
#include "Windows.h"


int height = 20;
int width = 100;

int main() {
	
	vector<Pixel> * pixels = new vector<Pixel>();
	
	if (true) {
		
		for (int i = 0; i < height*width; i++) {
			pixels->push_back(Pixel());
		}

		if (true) //link pixels
		{
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {

					if (x > 0) {
						pixels->at((y*width) + x).leftPixel = &pixels->at((y*width) + (x - 1));
					}
					if (x < (width - 1)) {
						pixels->at((y*width) + x).rightPixel = &pixels->at((y*width) + (x + 1));
					}
					if (y > 0) {
						pixels->at((y*width) + x).upperPixel = &pixels->at(((y - 1)*width) + x);
					}
					if (y < (height - 1)) {
						pixels->at((y*width) + x).lowerPixel = &pixels->at(((y + 1)*width) + x);
					}

					if (x > 0 && y > 0) {
						pixels->at((y*width) + x).leftUpperPixel = &pixels->at(((y - 1)*width) + (x - 1));
					}
					if (x < (width - 1) && y > 0) {
						pixels->at((y*width) + x).rightUpperPixel = &pixels->at(((y - 1)*width) + (x + 1));
					}
					if (x > 0 && y < (height - 1)) {
						pixels->at((y*width) + x).leftLowerPixel = &pixels->at(((y + 1)*width) + (x - 1));
					}
					if (x < (width - 1) && y < (height - 1)) {
						pixels->at((y*width) + x).rightLowerPixel = &pixels->at(((y + 1)*width) + (x + 1));
					}

				}
			}
		}

		if (false) //randomize pixel values
		{
			for (int i = 0; i < width*height; i++) {
				pixels->at(i).boolvalue = (rand() % 2) == 0 ? false : true;
			}
		}

		if (false) //glider test
		{
			pixels->at(1).boolvalue = true;
			pixels->at(width + 2).boolvalue = true;
			pixels->at((width * 2)).boolvalue = true;
			pixels->at((width * 2) + 1).boolvalue = true;
			pixels->at((width * 2) + 2).boolvalue = true;
		}
		if (true) //glider gun test
		{
			pixels->at(width + 25).boolvalue = true;

			pixels->at((width * 2) + 23).boolvalue = true;
			pixels->at((width * 2) + 25).boolvalue = true;

			pixels->at((width * 3) + 13).boolvalue = true;
			pixels->at((width * 3) + 14).boolvalue = true;
			pixels->at((width * 3) + 21).boolvalue = true;
			pixels->at((width * 3) + 22).boolvalue = true;
			pixels->at((width * 3) + 35).boolvalue = true;
			pixels->at((width * 3) + 36).boolvalue = true;

			pixels->at((width * 4) + 12).boolvalue = true;
			pixels->at((width * 4) + 16).boolvalue = true;
			pixels->at((width * 4) + 21).boolvalue = true;
			pixels->at((width * 4) + 22).boolvalue = true;
			pixels->at((width * 4) + 35).boolvalue = true;
			pixels->at((width * 4) + 36).boolvalue = true;

			pixels->at((width * 5) + 1).boolvalue = true;
			pixels->at((width * 5) + 2).boolvalue = true;
			pixels->at((width * 5) + 11).boolvalue = true;
			pixels->at((width * 5) + 17).boolvalue = true;
			pixels->at((width * 5) + 21).boolvalue = true;
			pixels->at((width * 5) + 22).boolvalue = true;

			pixels->at((width * 6) + 1).boolvalue = true;
			pixels->at((width * 6) + 2).boolvalue = true;
			pixels->at((width * 6) + 11).boolvalue = true;
			pixels->at((width * 6) + 15).boolvalue = true;
			pixels->at((width * 6) + 17).boolvalue = true;
			pixels->at((width * 6) + 18).boolvalue = true;
			pixels->at((width * 6) + 23).boolvalue = true;
			pixels->at((width * 6) + 25).boolvalue = true;

			pixels->at((width * 7) + 11).boolvalue = true;
			pixels->at((width * 7) + 17).boolvalue = true;
			pixels->at((width * 7) + 25).boolvalue = true;

			pixels->at((width * 8) + 12).boolvalue = true;
			pixels->at((width * 8) + 16).boolvalue = true;

			pixels->at((width * 9) + 13).boolvalue = true;
			pixels->at((width * 9) + 14).boolvalue = true;
		}

	}


	if (true) {

		char key;

		do
		{		
				for (int y = 0; y < height; y++) {

					string print = "";

					for (int x = 0; x < width; x++) {
						//print += to_string(pixels->at((y*width) + x).value);
						if (pixels->at((y*width) + x).boolvalue == 1) {
							print += char(219);// 254);
						}
						else
						{
							print += char(255);
						}
					}

					cout << print << endl;

				}

				//cout << char(223) << endl;

				cout << "" << endl;
				cout << "end by inputting '0'" << endl;
				cin >> key;
				system("cls");
				
				cout.clear();
				//cout << string(100, '\n');

				for (int i = 0; i < width*height; i++) {
					pixels->at(i).livingNeighBourCount();
				}
				for (int i = 0; i < width*height; i++) {
					/*
					pixels->at(i).boolvalue = (
						pixels->at(i).livingNeighBourCountInt == 2
						||
						pixels->at(i).livingNeighBourCountInt == 3
						);
					*/
					pixels->at(i).updateBoolValue();
				}
			
		} while (key != '0');

	}


	delete pixels;

	cout << "" << endl;
	cout << "ended" << endl;
	cout << "input anything to exit" << endl;

	char key;
	cin >> key;

	//delete pixels;

	return 0;
}