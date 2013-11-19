##################################
# Drawing lib configuration file #
##################################

cmake_minimum_required (VERSION 2.6)

add_library(Drawing SHARED drawing.c)
target_link_libraries (Drawing cairo)
