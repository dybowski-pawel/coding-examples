//    This file is part of Examples repository by Pawe³ Dybowski.
//
//    Copyright (C) 2021 Pawe³ Dybowski <dybowski015 at gmail dot com>
//    https://github.com/dybowski-pawel/coding-examples
//
//    Examples is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Examples is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Examples.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pawel on 17.11.21.
//

// This whole code looks like a bad student wrote it, I know.
// It is just a Proof of Concept to see if I reliably understand what I want to achieve and if I can get it to work.
// At the start it was much worse, believe me, the methods here are making it much less ugly.
// Right now I want to code something, let it run, see if it works. 
// If it does, I will write it nicely.
// Writing this thing took a week of 10minutes/day of sitting, so I expect a month or two on polishing it afterwards.
// It will actually be ground-up rewrite, not a polishing, because I don't want that kind of code in the end product.

// There is a lot of debug code that uses #define, don't worry about it too much

#include <iostream>
#include <chrono>
#include <iomanip>

#include "Version.h"
#include "Screenshot.h"

//#define cv_vid

#define testColors false

#if testColors
#define color_return cv::Scalar
#else
#define color_return bool
#endif

bool isBlackColor(cv::Vec3b pixel) {
	return((unsigned int)pixel[0] < 30 && (unsigned int)pixel[1] < 30 && (unsigned int)pixel[2] < 30);
}

color_return isGreenColor(cv::Vec3b pixel) {
	//     R   G   B
	//min 113 193  30
	//max 144 208  54
	unsigned int min[] = {105, 185, 25};
	unsigned int max[] = {155, 215, 60};
	unsigned int B = pixel[0], G = pixel[1], R = pixel[2];
	bool LR = min[0] > R, BR = R > max[0];
	bool LG = min[1] > G, BG = G > max[1];
	bool LB = min[2] > B, BB = B > max[2];
#if testColors
	return cv::Scalar(LB ? 125 : BB ? 255 : 0, LG ? 125 : BG ? 255 : 0, LR ? 125 : BR ? 255 : 0);
#else
	return(min[0] <= R && R <= max[0] && min[1] <= G && G <= max[1] && min[2] <= B && B <= max[2]);
#endif
}

color_return isRedColor(cv::Vec3b pixel) {
	//     R   G   B
	//min 218  93  86
	//max 230 109 108
	unsigned int min[] = {210, 90, 80};
	unsigned int max[] = {240, 115, 115};
	unsigned int B = pixel[0], G = pixel[1], R = pixel[2];
	bool LR = min[0] > R, BR = R > max[0];
	bool LG = min[1] > G, BG = G > max[1];
	bool LB = min[2] > B, BB = B > max[2];
#if testColors
	return cv::Scalar(LB ? 125 : BB ? 255 : 0, LG ? 125 : BG ? 255 : 0, LR ? 125 : BR ? 255 : 0);
#else
	return(min[0] <= R && R <= max[0] && min[1] <= G && G <= max[1] && min[2] <= B && B <= max[2]);
#endif
}

color_return isGoldColor(cv::Vec3b pixel) {
	//     R   G   B
	//min 247 250 115  
	//max 255 255 153
	unsigned int min[] = {225, 230, 105};
	unsigned int max[] = {255, 255, 160};
	unsigned int B = pixel[0], G = pixel[1], R = pixel[2];
	bool LR = min[0] > R, BR = R > max[0];
	bool LG = min[1] > G, BG = G > max[1];
	bool LB = min[2] > B, BB = B > max[2];
#if testColors
	return cv::Scalar(LB ? 125 : BB ? 255 : 0, LG ? 125 : BG ? 255 : 0, LR ? 125 : BR ? 255 : 0);
#else
	return(min[0] <= R && R <= max[0] && min[1] <= G && G <= max[1] && min[2] <= B && B <= max[2]);
#endif
}

cv::Vec3b getPixel(cv::Mat src, bool fromScreen, int x, int y) {
	cv::Vec3b pixel;
	if (fromScreen) {
		auto tmp = src.at<cv::Vec4b>(y, x);
		for (int i = 0; i < 4; i++) {
			pixel[i] = tmp[i];
		}
	} else {
		pixel = src.at<cv::Vec3b>(y, x);
	}
	return pixel;
}

int main(int argc, const char* argv[]) {
	std::cout << "Version: " << dbs::Version::GetVersion() << std::endl;


	HWND hwnd = GetDesktopWindow();

	bool fromScreen = false;

	unsigned int counter = 255;

#ifdef cv_vid
	cv::VideoCapture cap("C:/Users/dybas/Data/idleon/vid-in.mp4");
	while (cap.isOpened()) {
		counter++;
#else
	while(counter < 275) {
#endif

		std::stringstream inputBase, outputBase;
		inputBase << "C:/Users/dybas/Data/idleon/input/" << std::setfill('0') << std::setw(4) << counter;
		outputBase << "C:/Users/dybas/Data/idleon/output/" << std::setfill('0') << std::setw(4) << counter;

		cv::Mat src;
		int x, y, w, h;
		if (fromScreen) {
			src = Screenshot::CaptureScreen(hwnd, x, y, w, h);
		} else {
			std::stringstream inputImageName;
			inputImageName << inputBase.str() << "-in.jpg";
#ifdef cv_vid
			cap.read(src);
			cv::imwrite(inputImageName.str(), src);
#else
			src = cv::imread(inputImageName.str(), cv::IMREAD_COLOR);
#endif
			x = 0, y = 0, w = src.cols, h = src.rows;
		}

		cv::Mat draw = src.clone();

		int yTop = 0, yBottom = 0, xLeft = 0, xRight = 0;

		bool match = false;

		//find longest line, so that we don't search below it.

		unsigned int middleX = (w - x) / 2.;
		unsigned int longestY = 0;
		unsigned int widestBlack = 0;

		for (int yStart = y; yStart < h; yStart++) {
			unsigned int currentBlack = 0;
			auto pixel = getPixel(src, fromScreen, middleX, yStart);
			if (isBlackColor(pixel)) {
				currentBlack++;
				for (unsigned int xStart = 0; middleX - xStart > 0; xStart++) {
					auto pixel2 = getPixel(src, fromScreen, middleX - xStart, yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
				for (unsigned int xStart = 0; middleX + xStart < w; xStart++) {
					auto pixel2 = getPixel(src, fromScreen, middleX + xStart, yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
			}
			if (currentBlack > widestBlack*1.1) {
				widestBlack = currentBlack;
				longestY = yStart;
			}
		}

		//find leftmost black area

		unsigned int middleY = (h - y) / 2.;
		unsigned int leftX = 0;
		widestBlack = 0;

		for (int xStart = middleX; xStart > 0; xStart--) {
			unsigned int currentBlack = 0;
			auto pixel = getPixel(src, fromScreen, xStart, middleY);
			if (isBlackColor(pixel)) {
				currentBlack++;
				for (unsigned int yStart = 0; middleY - yStart > 0; yStart++) {
					auto pixel2 = getPixel(src, fromScreen, xStart, middleY - yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
				for (unsigned int yStart = 0; middleY + yStart < h; yStart++) {
					auto pixel2 = getPixel(src, fromScreen, xStart, middleY + yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
			}
			if (currentBlack > widestBlack * 1.1) {
				widestBlack = currentBlack;
				leftX = xStart;
			}
		}

		//find rightmost black area

		unsigned int rightX = 0;
		widestBlack = 0;

		for (int xStart = middleX; xStart < w; xStart++) {
			unsigned int currentBlack = 0;
			auto pixel = getPixel(src, fromScreen, xStart, middleY);
			if (isBlackColor(pixel)) {
				currentBlack++;
				for (unsigned int yStart = 0; middleY - yStart > 0; yStart++) {
					auto pixel2 = getPixel(src, fromScreen, xStart, middleY - yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
				for (unsigned int yStart = 0; middleY + yStart < h; yStart++) {
					auto pixel2 = getPixel(src, fromScreen, xStart, middleY + yStart);
					if (isBlackColor(pixel2)) {
						currentBlack++;
					} else {
						break;
					}
				}
			}
			if (currentBlack > widestBlack * 1.1) {
				widestBlack = currentBlack;
				rightX = xStart;
			}
		}

		for (unsigned int power = 2; power < 32 && !match; power *= 2) {

			for (unsigned int part = 1; part < power && !match; part += 2) {

				int xStart = (int)(w - x) * part / (double)power;

				bool wasPreviousNonBlack = false;

				for (int yStart = y; yStart < longestY && !match; yStart++) {

					cv::Vec3b pixel = getPixel(src, fromScreen, xStart, yStart);
					cv::circle(draw, cv::Point(xStart, yStart), 0, cv::Scalar(0, 0, 255), -1);

					if (isBlackColor(pixel)) {
						if (!wasPreviousNonBlack) {
							continue;
						}
						wasPreviousNonBlack = false;

						int matches = 0, mostLeft = xStart, mostRight = xStart;
						for (int xCandLeft = 1; xStart - xCandLeft > leftX; xCandLeft++) {

							cv::Vec3b pixelCand = getPixel(src, fromScreen, xStart - xCandLeft, yStart);
							cv::circle(draw, cv::Point(xStart - xCandLeft, yStart), 0, cv::Scalar(255, 0, 0), -1);

							if (isBlackColor(pixelCand)) {
								matches++;
								mostLeft = xStart - xCandLeft;
							} else {
								break;
							}
						}

						for (int xCandRight = 1; xStart + xCandRight < rightX; xCandRight++) {
							
							cv::Vec3b pixelCand = getPixel(src, fromScreen, xStart + xCandRight, yStart);
							cv::circle(draw, cv::Point(xStart + xCandRight, yStart), 0, cv::Scalar(255, 0, 0), -1);

							if (isBlackColor(pixelCand)) {
								matches++;
								mostRight = xStart + xCandRight;
							} else {
								break;
							}
						}


						if (matches > (w - x) / 6. && matches < (w - x) / 2.) {
							xLeft = mostLeft;
							xRight = mostRight;
							yTop = yStart;
							yBottom = yTop;

							bool secondNonBlackFound = false;

							for (int yEnd = yStart + 1; yEnd < h; yEnd++) {

								pixel = getPixel(src, fromScreen, xStart, yEnd);

								if (isBlackColor(pixel)) {
									if (!secondNonBlackFound) {
										continue;
									}
									yBottom = yEnd;
									break;
								} else {
									secondNonBlackFound = true;
								}
							}

							match = true;
							break;
						}

					} else {
						wasPreviousNonBlack = true;
					}
				}
			}
		}
		std::stringstream outputImageNameDrawn;
		outputImageNameDrawn << outputBase.str() << "-out-drawn.jpg";
		cv::imwrite(outputImageNameDrawn.str(), draw);

		if (match) {

			cv::Point p1(xLeft - 15, yTop - 35);
			cv::Point p2(xRight + 15, yBottom + 20);

			int LT = std::max(xLeft - 15, x);
			int RT = std::min(xRight + 15, w - 1);
			int LB = std::max(yTop - 55, y);
			int RB = std::min(yBottom + 20, h - 1);

			cv::Mat cropped = src.colRange(LT, RT).rowRange(LB, RB);

			//At this point the cropped contains only the minigame window, we can now see if it's safe to do a click.

			//1. Go to about a middle of rectangle

			auto xLeftCropped = xLeft - LT;
			auto xRightCropped = xRight - LT;
			auto yTopCropped = yTop-LB;
			auto yBottomCropped = yBottom-LB;

			auto yMiddle = yTopCropped;
			bool firstNonBlackFound = false;

			auto croppedDraw = cropped.clone();

			while (yMiddle < yBottomCropped) {
				yMiddle++;
				auto pixel = getPixel(cropped, fromScreen, xLeftCropped, yMiddle);

				if (isBlackColor(pixel)) {
					cv::circle(croppedDraw, cv::Point(xLeftCropped, yMiddle), 0, cv::Scalar(255, 0, 0), -1);
					if (firstNonBlackFound) {
						cv::circle(croppedDraw, cv::Point(xLeftCropped, yMiddle), 0, cv::Scalar(255, 255, 255), -1);
						break;
					}
				} else {
					cv::circle(croppedDraw, cv::Point(xLeftCropped, yMiddle), 0, cv::Scalar(0, 0, 255), -1);
					firstNonBlackFound = true;
				}
			}

			//we got yMiddle
			//now find starts and ends of three colors

			auto redLeft = -1, redRight = -1, greenLeft = -1, greenRight = -1, goldLeft = -1, goldRight = -1;
			for (auto xStart = xLeftCropped; xStart < xRightCropped; xStart++) {
				auto pixel = getPixel(cropped, fromScreen, xStart, yMiddle);
#if testColors
				auto scalar = isRedColor(pixel);
				cv::line(croppedDraw, cv::Point(xStart, yMiddle - 2), cv::Point(xStart, yMiddle + 2), scalar, 1);
#else				
				if (isRedColor(pixel)) {
					if (redLeft > 0) {
						redRight = xStart;
					} else {
						redLeft = xStart;
					}
				} else if (isGreenColor(pixel)) {
					if (greenLeft > 0) {
						greenRight = xStart;
					} else {
						greenLeft = xStart;
					}
				} else if (isGoldColor(pixel)) {
					if (goldLeft > 0) {
						goldRight = xStart;
					} else {
						goldLeft = xStart;
					}
				}
#endif
			}

			//we got where are all the colors, nice. Now just draw (for science) colorful rectangles

			if (redLeft != -1 && redRight != -1) {
				cv::rectangle(croppedDraw, cv::Rect(cv::Point(redLeft, yTopCropped), cv::Point(redRight, yBottomCropped)), cv::Scalar(0, 0, 255), 2);
			}
			if (greenLeft != -1 && greenRight != -1) {
				cv::rectangle(croppedDraw, cv::Rect(cv::Point(greenLeft, yTopCropped), cv::Point(greenRight, yBottomCropped)), cv::Scalar(0, 255, 0), 2);
			}
			if (goldLeft != -1 && goldRight != -1) {
				cv::rectangle(croppedDraw, cv::Rect(cv::Point(goldLeft, yTopCropped), cv::Point(goldRight, yBottomCropped)), cv::Scalar(0, 200, 200), 2);
			}

			//now we have the areas where it is nice and where it is bad!
			//time to find the leaf :)

			// save img

			std::stringstream outputImageNameCropped, outputImageNameWhereFrom, outputImageNameCroppedDraw;
			outputImageNameCropped << outputBase.str() << "-out-cropped.jpg";
			outputImageNameCroppedDraw << outputBase.str() << "-out-croppedDraw.jpg";
			outputImageNameWhereFrom << outputBase.str() << "-out-wherecropped.jpg";

			cv::imwrite(outputImageNameCropped.str(), cropped);
			cv::imwrite(outputImageNameCroppedDraw.str(), croppedDraw);

			cv::rectangle(src, cv::Rect(cv::Point(LT, LB), cv::Point(RT, RB)), cv::Scalar(255, 255, 255));

			cv::imwrite(outputImageNameWhereFrom.str(), src);
		}

		counter++;

	}

	return 0;
}