# Day Type Program

This C++ program implements a class called `dayType`, which allows users to work with days of the week dynamically. The program includes a menu-driven interface that enables users to set the current day, print the day, and perform various operations related to days of the week.

## How It Works

1. **Class Definition**: 
   - The `dayType` class stores the current day of the week using a dynamically allocated string and provides methods to manipulate and access day information.

2. **Dynamic Memory Management**: 
   - The class uses dynamic memory allocation for the current day, ensuring efficient memory usage and management.

3. **Menu-Driven Interface**: 
   - The program presents a menu to the user, allowing them to select various options for interacting with the `dayType` object.

4. **Operations**: 
   - Users can set the current day, print the day, get the next and previous days, and add a certain number of days to the current day.

## Features

- **Dynamic Allocation**: 
   - The `dayType` class dynamically allocates memory for the current day, allowing for flexible memory management.
  
- **Copy Constructor**: 
   - The class includes a copy constructor to enable deep copying of `dayType` objects.
  
- **Menu-Driven Interaction**: 
   - Users can interact with the program through a simple and intuitive menu system.

## Functionality Overview

### Main Operations

1. **Set the Day**: 
   ```cpp
   d1->Set_Day(new_day);
   d1->Print_day();
   d1->Get_Day();
   d1->Next_Day();
   d1->Previous_Day();
   d1->add_Days(num);
