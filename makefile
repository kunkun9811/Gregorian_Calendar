CC = g++
VER = '-std=c++11'

# Compiled program name
TARGET = theCalendar

all:
	$(CC) $(VER) -o $(TARGET) src/main.cpp src/calendar.cpp src/year.cpp src/month.cpp src/day.cpp src/todo.cpp
	./$(TARGET)
clean:
	rm $(TARGET)
