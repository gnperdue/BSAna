CXX = clang++
ROOTFLAGS = `root-config --cflags --glibs`
TARGET = gstana_r

all: gstana_r 

gstana_r: Rungst.cxx gstana.cxx gstana.h
	$(CXX) -o gstana_r Rungst.cxx gstana.cxx $(ROOTFLAGS)
	cp gstana_r $(ANA_BIN_DIR)/

clean:
	rm -f $(ANA_BIN_DIR)/gstana_r
	rm -f gstana_r
