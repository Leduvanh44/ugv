Kết quả mô phỏng:
This section evaluates the performance of the algorithms in processing and merging PointCloud data, as well as their capability in map scanning and localization experiments. The simulation results were obtained using the ROS Melodic platform.

System model and map in simulation.
The model has dimensions of 0.45x0.45x0.5m, with the depth camera and lidar simulated using the main specifications of Hokuyo and Kinect. The coordinates of the depth camera are (0.145, 0, 0.3) and those of the lidar are (0.13, 0, 0.23). Accordingly, we will have the transformation matrices for each device as follows.
The translation matrix of the depth camera: [■(0.145@0@0.3)].
The translation matrix of the lidar: [■(0.13@0@0.23)].
Since the sensors are not rotated, the transformation matrices are respectively:
From camera to base: [■(1&0&0&0.145@0&1&0&0@0&0&1&0.3@0&0&0&1)].
From lidar to base: [■(1&0&0&0.13@0&1&0&0@0&0&1&0.23@0&0&0&1)].

 
The map after the scanning is completed (using NDT method).

After completing the processing and map registration, during the mapping process, each time a frame of the map is scanned, the quality of the registered point cloud is evaluated against the original point cloud. The evaluation of point cloud quality is based on two main standards.
The first is the overlap ratio. This is the percentage of points in the original point cloud that overlaps with other point clouds (NDT, ICP, GICP). The overlap ratio is calculated by counting the number of points from the original point cloud that have at least one nearest point in the other point clouds (using a K-d tree to find the nearest point) and dividing this by the total number of points in the original point cloud.
The second is mean deviation. This is the average of the Euclidean distances between corresponding points in the original point cloud and the other point clouds (NDT, ICP, GICP). This helps to determine the level of difference between the processed point clouds and the original point cloud. The deviation indicates the accuracy of the algorithms compared to the original data.
	Evaluation of point cloud quality according to different algorithms.
Applied algorithm	Overlap (%)	Mean Deviation (m)
ICP	0.851	0.105
GICP	0.884	0.098
NDT	0.961	0.067

 
The map after conversion to 2D.
	Error data of the obtained map (Simulation)
Road section	Actual size on the simulation map (m)	Size on the map (m)
a 	3	3.03
b 	4.75	4.79
c	4.25	4.19

This is the result of localization coordinates on the indoor map (simulation) interpolated using the AMCL algorithm.
	Mocalization coordinates on the obtained map (simulation)
Point	Tọa độ x 	Tọa độ y	OA (vehicle coordinates, m)	OA (Rviz tool, m)
O	0.002	-0.001		
A	-4.365	6.595	7.9106	8
B	6.806	5.649		
