#include "file_writer.hpp"

void write_params(const string file_path, const Mat& intrinsics, const Mat& distCoeffs)
{
	FileStorage fs(file_path, FileStorage::WRITE);

	if (!fs.isOpened()) exit(1);

	fs << "intrinsics" << intrinsics;
	fs << "distCoeffs" << distCoeffs;

	cout << "Saved: " << file_path << endl;
	fs.release();
}