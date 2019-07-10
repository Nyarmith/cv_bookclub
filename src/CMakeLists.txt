cmake_minimum_required(VERSION 3.8)
project(cv_examples)

find_package(OpenCV REQUIRED)

add_executable(manual_filter manual_filter.cc)
target_link_libraries(manual_filter ${OpenCV_LIBS})

add_executable(standard_filters standard_filters.cc)
target_link_libraries(standard_filters ${OpenCV_LIBS})

add_executable(pixel_transforms pixel_transforms.cc)
target_link_libraries(pixel_transforms ${OpenCV_LIBS})

add_executable(histogram_equalization histogram_equalization.cc)
target_link_libraries(histogram_equalization ${OpenCV_LIBS})
