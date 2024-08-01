CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
INCLUDES = -I./src -I./include
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/p2p_file_transfer

SOURCES := $(shell find $(SRCDIR) -name *.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)