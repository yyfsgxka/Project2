#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{

	//练习二旋转及缩放
	Mat frame = imread("lena.jpg");
	Mat dstframe;
	if (frame.empty()) return 1;
	//旋转-40.缩放尺度为
	float angle = -10, scale = 1;
	cv::Point2f center(frame.rows*0.5, frame.cols*0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	//仿射变换函数
	cv::warpAffine(frame, dstframe, affine_matrix, frame.size());
	imshow("原图", frame);
	imshow("旋转缩放后的图", dstframe);


	//练习三仿射变换
	Mat scrMat = imread("lena.jpg");
	Mat dstMat;

	if (scrMat.empty()) return -1;
	const cv::Point2f scr_pt[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,100) };
	//变换后的三点坐标
	const cv::Point2f dst_pt[] = {
		cv::Point2f(300,100),
		cv::Point2f(300,50),
		cv::Point2f(200,100) };
	//仿射变换函数
	const cv::Mat  affine_matrix_fs = cv::getAffineTransform(scr_pt, dst_pt);
	std::cout << "sffine_matrix=\n" << affine_matrix_fs << std::endl;
	cv::warpAffine(scrMat, dstMat, affine_matrix_fs, scrMat.size());
	imshow("仿射变换后的图", dstMat);

	//练习四投影变换
	Mat pic = imread("lena.jpg");
	Mat dstpic;
	if (pic.empty()) return -1;
	const cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(350,150) };
	//变换后的四点坐标
	const cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180) };
	//透视变换行列计算
	const cv::Mat perspective_matrix = cv::getAffineTransform(pts1, pts2);
	//
	cv::warpPerspective(pic, dstpic, perspective_matrix, pic.size());
	imshow("投影变换后的图", dstMat);

	waitKey(0);


	return 0;



}