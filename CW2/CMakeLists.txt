cmake_minimum_required(VERSION 3.19)
project(CW2)
set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT "C:/local/boost_1_76_0")
include_directories("C:/local/boost_1_76_0")

add_executable(CW2 main.cpp User.cpp User.h inputvalidation.h Student.cpp Student.h Lecturer.cpp Lecturer.h duplicate_user_check.h password_validation.h generate_pin.cpp generate_pin.h template_class.cpp template_class.h File.cpp File.h Admin.cpp Admin.h system_announcement.cpp system_announcement.h lecturer_announcement.cpp lecturer_announcement.h EncryptFile.h DecryptFile.h md5hash.h)







