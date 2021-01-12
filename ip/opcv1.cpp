#include<opencv2/opencv.hpp>
#include<opencv2/core/utility.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat image1,final_im;
	float angle;
	image1 = imread("C:\\Users\\Ivan Roy\\Downloads\\images\\Real_Madrid_kit_goal_600_400.jpg");
	cout << "Dimensions are " << image1.rows << "x" << image1.cols << endl;
	if (image1.empty())
	{
		cout << "Not successfully loaded!" << endl;
	}
	else
	{
		cout << "Enter the angle by which the image should be rotated" << endl;
		cin >> angle;
		Point2f pt(image1.cols / 2., image1.rows / 2.);
		Mat v = getRotationMatrix2D(pt, angle, 1.0);
		warpAffine(image1, final_im, v, Size(image1.cols, image1.rows));
		imshow("Image before rotation", image1);
		imshow("Final Image", final_im);
		waitKey(0);
	}
return 0;
}