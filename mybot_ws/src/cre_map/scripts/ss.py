import cv2
import numpy as np

map_img = cv2.imread('/home/leduvanh/mybot_ws/src/cre_map/map/c1.pgm', cv2.IMREAD_GRAYSCALE)
cv2.imshow("dbsf", map_img)
cv2.waitKey(0)
rows, cols = map_img.shape
print(rows, cols)
center = (500, 500)

angle = 90

M = cv2.getRotationMatrix2D(center, angle, 1.0)

rotated_map = cv2.warpAffine(map_img, M, (rows, cols))
cv2.imshow("dbf", rotated_map)
cv2.waitKey(0)
cv2.imwrite('/home/leduvanh/mybot_ws/c11.pgm', rotated_map)
