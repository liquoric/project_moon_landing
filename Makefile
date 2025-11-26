CXX = g++
TARGET = main
SOURCES = Main.cpp Solution.cpp
HEADERS = Solution.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean