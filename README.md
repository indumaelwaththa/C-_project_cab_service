TOUR MATE CAB SERVICE – C++ Console Application
# Project Overview

Tour Mate Cab Service is a C++ console-based application designed to manage a cab service system.
It supports admin and user roles, vehicle management, sales tracking, and basic authentication using file handling.

This project is suitable for learning:

File handling in C++

Structures & classes

Menu-driven programs

Basic data validation

Role-based access (Admin / User)


#Technologies Used

Language: C++

Concepts:

File I/O (fstream)

Structures & Classes

Functions

Conditional logic

Loops

Compiler: GCC / MinGW / any C++ compatible compiler

#User Roles
#Admin

Default admin credentials:

Username: admin
Password: 1234


Admin can:

View available vehicles

Add new vehicles

Update vehicle details

Delete vehicles

Add sales records

View all sales

View company details

# User

Users can register and log in.

User can:

View available vehicles

View company details

Logout


#Files Used (Auto-created)

File Name	Purpose
vehicals.txt	Stores vehicle details
sales.txt	Stores sales records
users.txt	Stores registered user credentials

#Vehicle Data Format (vehicals.txt)
VehicleRegNo VehicleType VehicleModel PricePerKm Availability


Example:

CAB123 Car Prius 100 1


Availability:

1 → Available

0 → Not available

Sales Data Format (sales.txt)
VehicleRegNo CustomerName BookingDate PricePerKm Distance TotalCost


Example:

CAB123 John 2026.01.03 100 25 2500


# Features Summary

Add / View / Update / Delete vehicles

Prevent duplicate vehicle registration numbers

Sales cost calculated automatically

File-based persistent storage

Simple authentication system

Menu-driven UI



#How to Run

Compile the program:

g++ main.cpp -o tourmate


Run the executable:

./tourmate


Follow on-screen menus.

#Known Limitations

Passwords are stored in plain text

No encryption or hashing

No input sanitization for spaces in vehicle fields

Limited to 50 vehicles

Console-based UI only


# License

This project is for educational purposes.
and this is for portfolio.



