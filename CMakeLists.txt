cmake_minimum_required(VERSION 3.21)
project(lab_9)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_9 main.cpp Produs.cpp Produs.h RepoStl.cpp RepoStl.h Tests.cpp Tests.h Service.cpp Service.h UI.cpp UI.h RepositoryFile.cpp RepositoryFile.h ProdusValidator.cpp ProdusValidator.h Exceptions.cpp Exceptions.h)
